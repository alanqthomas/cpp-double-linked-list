#include "DoubleLinkedList.h"
#include <iostream>

int main() {

	const int x = 1;

	ListNode<int> node1 = ListNode<int>(x);

	int y = node1.data();
	printf("%d\n", y);
}