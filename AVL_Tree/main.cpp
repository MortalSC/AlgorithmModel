#include "AVL.hpp"
#include <iostream>
#include <ctime>
//static int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
static int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
void testInsert() {
	AVL<int, int> avl;
	
	for (auto e : a) {
		avl.insert(std::make_pair(e, e));
	}
	//int N = 10000;
	//for (int i = 0; i < N; i++) {
	//	int e = rand();
	//	avl.insert(std::make_pair(e, e));
	//	cout << e << endl;
	//}
	std::cout << avl.isBalance() << std::endl;

	//avl.InOrder();
}

int main() {
	srand((unsigned)time(0));
	testInsert();

	return 0;
}