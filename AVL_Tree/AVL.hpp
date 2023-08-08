#ifndef _AVL_HPP_
#define _AVL_HPP_

#include <iostream>
#include <assert.h>
using namespace std;
// 三叉结点
template<class K, class V>
struct AVLnode
{
	AVLnode<K, V>* _left;				// 左指针
	AVLnode<K, V>* _right;		// 右指针
	AVLnode<K, V>* _parent;			// 父节点指针

	pair<K, V> _kv;				
	int _bf;					// balance factor：平衡因子
	AVLnode(const pair<K, V>& kv) 
		: _left(nullptr), _right(nullptr), _parent(nullptr), _kv(kv), _bf(0)
	{

	}
};

template<class K, class V>
class AVL {
	typedef AVLnode<K,V> Node;

public:
	// 插入
	bool insert(const pair<K, V>& kv) {
		if (_root == nullptr) {
			_root = new Node(kv);
			return true;
		}

		// 1. 探索插入位置
		Node* prev = nullptr;
		Node* current = _root;
		while (current) {
			if (kv.first < current->_kv.first) {
				// 小于左走
				prev = current;
				current = current->_left;
			}
			else if (kv.first > current->_kv.first) {
				// 大于右走
				prev = current;
				current = current->_right;
			}
			else {
				return false;
			}
		}
		// 2. 结点插入
		current = new Node(kv);
		if (kv.first < current->_kv.first) {
			prev->_left = current;
		}
		else {
			prev->_right = current;
		}
		current->_parent = prev;

		// 3. 平衡检测及控制
		// prev 指向的是当前结点的父节点
		// current 指向的是当前结点（新增）
		/*
			1. 新增在右：parent->bf++；
			2. 新增在左：parent->bf--；
			3. 新增结点后，parent->bf == 1 or -1；
				【说明：原来的 bf == 0！说明左右子树的高度相等！插入后破坏平衡了！
				注意：需要继续往上更新！（可能更新到根结点）】
			4. 新增结点后，parent->bf == 0；
				【说明：原来的 bf == -1 / 1！说明插入前左右子树的高度不相等！
				插入后，使得高度相等！即满足平衡条件，不需要向上更新！】
			5. 新增结点后，parent->bf == 2 or -2；
				【说明：bf == -1 / 1！说明插入前左右子树的高度不相等！
				加剧了不平衡性！导致左右子树高度差的绝对值大于 1，打破了平衡！parent所在子树需要旋转调整】
			6. 新增结点后，不可能出现 bf > 2 or bf < -2 的情形，如果有，就已经不是AVL树了！说明之前的操作有问题！
		*/
		while (prev) {				
			if (current == prev->_left) {
				// 左新增
				prev->_bf--;
			}
			else {
				prev->_bf++;
			}
			if (0 == prev->_bf) {
				// 原来不平衡，插入后平衡了！
				break;
			}
			else if (1 == prev->_bf || -1 == prev->_bf) {
				// 原来平衡，插入后不平衡了！
				// 需要向上更新
				current = prev;
				prev = current->_parent;
			}
			else if(2 == prev->_bf || -2 == prev->_bf) {
				// 平衡因子到此，bf == 2 / -2，需要旋转
				if (prev->_bf == 2 && current->_bf == 1) {
					// 情形一：右 + 右 = 单次左旋
					Left_Rotate(prev);
				}
				else if (prev->_bf == -2 && current->_bf == -1) {
					// 情形二：左 + 左 = 单次右旋
					Right_Rotate(prev);
				}
				else if (prev->_bf == -2 && current->_bf == 1) {
					// 情形三：左 + 右 = 左旋 + 右旋
					LR_Rotate(prev);
				}
				else  if (prev->_bf == 2 && current->_bf == -1) {
					RL_Rotate(prev);
				}
				else {
					assert(false);
				}
				break;
			}
			else {
				assert(false);
			}
		}

		return true;
	}

	void InOrder() {
		_InOrder(_root);
		std::cout << std::endl;
	}

	bool isBalance() {
		return _isBalance(_root);
	}

private:
	void _InOrder(Node* root) {
		if (root == nullptr) return;
		_InOrder(root->_left);
		std::cout << root->_kv.first << ' ';
		_InOrder(root->_right);
	}

	bool _isBalance(Node* root) {
		if (root == nullptr) return true;
		int left = height(root->_left);
		int right = height(root->_right);
		int diff = right - left;
		return abs(diff) < 2 
			&& _isBalance(root->_left) 
			&& _isBalance(root->_right);
	}

	// 获取树的高度
	int height(Node* root) {
		if (root == nullptr) return 0;
		return max(height(root->_left), height(root->_right)) + 1;
	}

	// 左旋
	void Left_Rotate(Node* parent) {
		Node* subR = parent->_right;
		Node* subRL = parent->_left;

		parent->_right = subRL;
		if (subRL) {
			subRL->_parent = parent;
		}

		Node* ppNode = parent->_parent;		// 记录当前操作结点的父节点（非根节点）

		subR->_left = parent;
		parent->_parent = subR;

		if (_root == parent) {
			// 特殊的：parent 就是根节点
			_root = subR;
			subR->_parent = nullptr;
		}
		else {
			if (ppNode->_left == parent) {
				ppNode->_left = subR;
			}
			else {
				ppNode->_right = subR;
			}
			subR->_parent == ppNode;
		}

		subR->_bf = parent->_bf = 0;
	}


	// 右旋
	void Right_Rotate(Node* parent) {
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		// 判断 subLR的右子树是否存在
		if (subLR) {
			subLR->_parent = parent;
		}

		// 记录 parent 的父节点
		Node* ppNode = parent->_parent;

		// 链接时，类似双向链接的关联！
		subL->_right = parent;
		parent->_parent = subL;
		
		if (_root == parent) {
			_root = subL;
			subL->_parent = nullptr;
		}
		else {
			if (ppNode->_left == parent) {
				ppNode->_left = subL;
			}
			else {
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}
		subL->_bf = parent->_bf = 0;
	}

	// 左右旋：难点：平衡因子的更新！
	void LR_Rotate(Node* parent) {
		// 提前记录结点：便于更新平衡因子
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		// 旋转
		Left_Rotate(parent->_left);
		Right_Rotate(parent);

		subLR->_bf = 0;
		if (bf == 1) {
			parent->_bf = 0;
			subL->_bf = -1;
		}
		else if( bf == -1 ){
			parent->_bf = 1;
			subL->_bf = 0;
		}
		else if (bf == 0) {
			parent->_bf = 0;
			subL->_bf = 0;
		}
		else {
			assert(false);
		}
	}

	// 右左旋：难点：平衡因子的更新！
	void RL_Rotate(Node* parent) {
		// 提前记录结点：便于更新平衡因子
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		// 旋转
		Right_Rotate(parent->_right);
		Left_Rotate(parent);


		subRL->_bf = 0;
		if (bf == 1) {
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1) {
			subR->_bf = 1;
			parent->_bf = 0;
		}
		else if (bf == 0) {
			parent->_bf = 0;
			subR->_bf = 0;
		}
		else {
			assert(false);
		}
	}

private:
	Node* _root = nullptr;				// 根节点
};

#endif