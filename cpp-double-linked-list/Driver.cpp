#include "DoubleLinkedList.h"
#include "OrderedDoubleLinkedList.h"
#include "PhoneBookEntry.h"
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

	list->pop_front();
	list->pop_back();
	list->pop_back();

	list->insert_before(list->first(), 1);
	list->insert_before(list->first(), 2);
	list->insert_after(list->last(), 3);

	list->erase(3);

	list->print();
	list->debug(std::cout);

	std::cout << "\n\n\n";

	OrderedDoubleLinkedList<int>* oList = new OrderedDoubleLinkedList<int>();

	oList->insert(3);
	oList->insert(1);	
	oList->insert(5);
	oList->insert(2);
	oList->insert(4);

	oList->erase(3);
	oList->erase(5);

	oList->print();
	oList->debug(std::cout);

	PhoneBookEntry entry = PhoneBookEntry("Joe", "123");
	PhoneBookEntry entry2 = PhoneBookEntry("Bob", "456");
	PhoneBookEntry entry3 = PhoneBookEntry(entry);

	std::cout << "entry < entry2: " << (entry == entry2) << ".\n";

	std::getchar();
}