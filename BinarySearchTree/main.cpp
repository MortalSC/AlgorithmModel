#include "BST.hpp"
#include <iostream>

static int a[] = { 5,3,4,8,1,478,2,58,12,6 };

void TestInsert(BST<int> & bst) {
	for (auto t : a) {
		bst.insert(t);
	}
	bst.InOrder();
}

#if 0
void TestFind(BST<int>& bst, int aim) {
	if (bst.findR(aim)) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}
}

void TestErase(BST<int>& bst) {
	bst.InOrder();
	for (auto p : a) {
		std::cout << "delete：" << p << std::endl;
		bst.eraseR(p);
		bst.InOrder();
	}
}
#endif

int main() {

	BST<int> bst;
	TestInsert(bst);
	//TestFind(bst, 1);
	//TestErase(bst);

	//BST<int> cp(bst);
	//std::cout << "copy" << std::endl;
	//cp.InOrder();

	//BST<int> cpp;
	//cpp = cp;
	//std::cout << "copy" << std::endl;
	//cpp.InOrder();
	//return 0;
}