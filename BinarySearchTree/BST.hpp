#ifndef  _BST_HPP_
#define  _BST_HPP_

#include <iostream>

// 二叉树结点
template<class T>
struct BSTnode {
public:
	BSTnode<T>* _left;		// 左指针
	BSTnode<T>* _right;		// 右指针
	T _data_key;			// 数据 / 键

	// 构造函数：
	BSTnode(const T& data)
		:_left(nullptr), _right(nullptr), _data_key(data)
	{

	}
};

template <class Key>
class BSTree {
	typedef BSTnode<Key> Node;	// 别名

public:
	BSTree() :_root(nullptr) {}
	~BSTree() {
		_destroy(_root);
	}
	BSTree(const BSTree<Key>& bst) {
		_root = _copy(bst._root);
	}
	BSTree<Key>& operator = (BSTree<Key> bst) {
		std::swap(_root, bst._root);
		return * this;
	}


	/* 插入结点：被数据一定满足小了放左边，大了放右边！ */
	bool insert(const Key& key) {
		// 根节点为空！
		if (_root == nullptr) {
			_root = new Node(key);
			return true;
		}
		// 设置游标指针探路：寻找插入位置
		Node* current = _root;
		Node* prev = nullptr;					// 记录当前探索节点的父节点：用于结点插入
		while (current) {
			prev = current;
			if ( key < current->_data_key) {
				// 小于靠左行
				current = current->_left;
			}
			else if( key > current->_data_key ){
				// 大于靠右行
				current = current->_right;
			}
			else {
				// 不允许出现相同值！
				return false;
			}
		}

		// 结点插入：
		current = new Node(key);			// 创建新结点
		if (prev->_data_key > key) {
			// 右插
			prev->_left = current;
		}
		else {
			prev->_right = current;
		}
		return true;

	}

	// 插入结点：递归版
	bool insertR(const Key& key) {
		return _insertR(_root, key);
	}

	// 查找
	bool find(const Key& key) {
		// if (_root == nullptr) return false;		// 空树直接返回
		
		// 设置游标用于查找
		Node* current = _root;
		while (current) {
			if (key < current->_data_key) {
				// 向左子树寻找
				current = current->_left;
			}else if(key > current->_data_key ){
				// 向右子树找！
				current = current->_right;
			}
			else {
				return true;
			}
		}
		return false;
	}

	// 查找：递归版本！
	bool findR(const Key& key) {
		return _findR(_root, key);
	}

	// 删除
	bool erase(const Key& key) {

		if (!_root) return false;	// 空树
		Node* prev = nullptr;
		Node* current = _root;
		// 寻找删除目标，并删除
		while (current) {
			// 找删除目标！
			if (key < current->_data_key) {
				prev = current;
				current = current->_left;
			}
			else if (key > current->_data_key) {
				prev = current;
				current = current->_right;
			}
			else {
				// 找到了删除目标
				// 1. 目标结点的左子树为空！
				if (current->_left == nullptr) {
					if (current == _root) {
						// 特殊情况：删除目标是根结点
						_root = current->_right;
					}
					else {
						if (current == prev->_left) {
							prev->_left = current->_right;
						}
						else {
							prev->_right = current->_right;
						}
					}
					delete current;
					current = nullptr;
				}
				else if (current->_right == nullptr) {
					if (current == _root) {
						_root = current->_left;
					}
					else {
						if (current == prev->_left) {
							prev->_left = current->_left;
						}
						else {
							prev->_right = current->_left;
						}
					}
					delete current;
					current = nullptr;
				}
				else {
					// 双子：使用替换法删除
					// 搜索二叉树的特点：父节点的值一定小于右子树的任意节点值！
					// 交换的目标：即：被删除结点与被删除结点子树的最小值进行交换！
					Node* min = current->_right;		// 用于记录右子树的最小结点
					Node* ptr = current;
					while (min->_left) {
						ptr = min;						// 记录最小结点的上一个结点，后用于删除操作！
						min = min->_left;				// 最小值一定在子树的最左边！
					}
					// 找到了进行交换
					std::swap(min->_data_key, current->_data_key);	// 值交换
					// 结点删除
					if (ptr->_left == min) {
						ptr->_left = min->_right;
					}
					else {
						ptr->_right = min->_right;
					}
					delete min;
					min = nullptr;
				}
				return true;
			}

		}
		return false;
	}

	// 删除：递归版
	bool eraseR(const Key& key) {
		return _eraseR(_root, key);
	}

	// 遍历方式：
	// 中序遍历
	// 注意：对于成员函数：由于私有化了根节点！无法显示传递参数！
	// 解决方式一：定义一个返回根节点的函数
	// 解决方式二：私有化包装功能函数如下
	void InOrder() {
		_InOrder(_root);	// 调用私有化方法！
		std::cout << std::endl;
	}
private:
	Node* _copy(Node* root) {
		if (!root) return nullptr;
		Node* cpnode = new Node(root->_data_key);
		cpnode->_left = _copy(root->_left);
		cpnode->_right = _copy(root->_right);
		return cpnode;
	}

	void _destroy(Node* &root) {
		if (!root) return;
		_destroy(root->_left);
		_destroy(root->_right);
		delete root;
		root = nullptr;
	}

	void _InOrder(Node* root) {
		if (root == nullptr) return;
		_InOrder(root->_left);
		std::cout << root->_data_key << " ";
		_InOrder(root->_right);
	}

	bool _findR(Node* root, int key) {
		if (root == nullptr) return false;
		if (key < root->_data_key)
			return _findR(root->_left, key);
		else if(key > root->_data_key)
			return _findR(root->_right, key);
		else {
			return true;
		}
	}

	// 神之一手：Node* &root 解决了非根节点的递归中，新结点的传递式父节点连接问题
	// 如果出现空，使用引用即找到了上一级子结点的别名
	bool _insertR(Node* &root, const Key& key) {
		if (!root) {
			root = new Node(key);		// 引用的作用仅在此处体现！
			return true;
		}
		if (key > root->_data_key) 
			return _insertR(root->_right, key);
		else if (key < root->_data_key) 
			return _insertR(root->_left, key);
		else
			return false;
	}

	bool _eraseR(Node* &root, const Key& key) {
		if (!root) {
			return false;
		}
		// 找删除目标
		if (key > root->_data_key) {
			return _eraseR(root->_right, key);
		}
		else if (key < root->_data_key) {
			return _eraseR(root->_left, key);
		}
		else {
			Node* del = root;
			// 引用的作用：引用的结点就是被删除的结点的父节点的子树指针的别名
			if (root->_left == nullptr) {
				root = root->_right;
			}
			else if (root->_right == nullptr) {
				root = root->_left;
			}
			else {
				Node* min = root->_right;
				while (min->_left) {
					min = min->_left;
				}
				std::swap(min->_data_key, root->_data_key);
				return _eraseR(root->_right, key);
			}
			delete del;
			del = nullptr;
		}
	}




private:
	Node* _root = nullptr;		// 根节点
};


#endif