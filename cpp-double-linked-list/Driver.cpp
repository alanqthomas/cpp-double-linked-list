#include "DoubleLinkedList.h"
#include <iostream>


int main() {

	ListNode<int>* node1 = new ListNode<int>(1);
	ListNode<int>* node2 = new ListNode<int>(2);
	ListNode<int>* node3 = new ListNode<int>();

	int x = node1->data();
	const int y = node2->data();
	int z = node3->data();

	std::cout << "Your first number: " << x << "\n";
	std::cout << "Your second number: " << y << "\n";

	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->push_back(1);
	list->push_back(2);
	list->push_back(3);

	list->print();
	list->debug(std::cout);

	std::getchar();
}