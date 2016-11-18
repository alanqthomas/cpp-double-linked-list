#include <iostream>
#include <string>

#include "DoubleLinkedList.h"
#include "PhoneBook.h"
#include "Stack.h"
#include "Queue.h"

void testStack();
void printStackInfo(Stack<int>& stack);

void testQueue();
void printQueueInfo(Queue<int>& queue);

void testPhoneBook();
void testList();

int main() 
{
	std::cout << "===============Testing the Phone Book===============" << std::endl << std::endl;
	testPhoneBook();

	std::cout << std::endl << std::endl;
	std::cout << "===============Testing the DoubleLinkedList class===============" << std::endl << std::endl;
	testList();

	std::cout << std::endl << std::endl;
	std::cout << "===============Testing the Stack class===============" << std::endl << std::endl;
	testStack();

	std::cout << std::endl << std::endl;
	std::cout << "===============Testing the Queue class===============" << std::endl << std::endl;
	testQueue();

	std::cout << std::endl << std::endl;
	std::cout << "Press any key to exit...";
	std::getchar();

	return 0;
}

void testStack() {
	Stack<int> stack;

	stack.push(1);
	printStackInfo(stack);
	stack.push(2);
	printStackInfo(stack);
	stack.push(3);
	printStackInfo(stack);

	stack.print();

	stack.pop();
	printStackInfo(stack);
	stack.pop();
	printStackInfo(stack);

	stack.print();

	stack.pop();
	stack.print();

	stack.push(3);
	printStackInfo(stack);
	stack.push(2);
	printStackInfo(stack);
	stack.push(1);
	printStackInfo(stack);

	stack.print();
}

void testQueue() {
	Queue<int> queue;

	queue.push(1);
	printQueueInfo(queue);
	queue.push(2);
	printQueueInfo(queue);
	queue.push(3);
	printQueueInfo(queue);

	queue.print();

	queue.pop();
	printQueueInfo(queue);
	queue.pop();
	printQueueInfo(queue);

	queue.print();

	queue.pop();
	queue.print();

	queue.push(3);
	printQueueInfo(queue);
	queue.push(2);
	printQueueInfo(queue);
	queue.push(1);
	printQueueInfo(queue);

	queue.print();
}

void printStackInfo(Stack<int>& stack) {
	std::cout << "Size: " << stack.size() << ".\n";
	std::cout << "Top: " << stack.top() << ".\n";
}

void printQueueInfo(Queue<int>& queue) {
	std::cout << "Size: " << queue.size() << ".\n";
	std::cout << "Front: " << queue.front() << ".\n";
	std::cout << "Back: " << queue.back() << ".\n";
}

void testPhoneBook()
{
	PhoneBook phoneBook;

	std::cout << "First do 6 inserts" << std::endl;
	phoneBook.insert(PhoneBookEntry("The Phone Place", "800-333-2222", "service@example.com"));
	phoneBook.insert(PhoneBookEntry("Bob Smith", "800-222-3333"));
	phoneBook.insert(PhoneBookEntry("Sue Jones", "999-444-5678", "suej@example.net"));
	phoneBook.insert(PhoneBookEntry("Albert A. Allan", "800-111-3333", "aaa.whats.up@example.net"));
	phoneBook.insert(PhoneBookEntry("Zed Zedson", "800-777-3333", "zztop@example.org"));
	phoneBook.insert(PhoneBookEntry("Sven Stevens", "800-444-3333"));

	std::cout << std::endl;
	std::cout << "Display list with " << phoneBook.size() << " items" << std::endl;
	std::cout << "They should be in order, sorted by name" << std::endl;
	phoneBook.print();

	std::cout << std::endl;
	std::cout << "Try to insert an already existing entry (Sven Stevens) with a different phone number." << std::endl;
	std::cout << "This should update the exsting entry." << std::endl;
	phoneBook.insert(PhoneBookEntry("Sven Stevens", "888-555-1234"));
	std::cout << std::endl;

	std::cout << "Display list with " << phoneBook.size() << " items" << std::endl;
	std::cout << "Sven's number should now be 888-555-1234" << std::endl;
	phoneBook.print();
	std::cout << std::endl;

	std::cout << "Try out some find operators. Notta Person will not be found." << std::endl;
	for (auto name : { "Albert A. Allan", "Notta Person", "Zed Zedson" })
	{
		if (phoneBook.find(name))
		{
			std::cout << "Name \"" << name << "\" was found" << std::endl;
		}
		else
		{
			std::cout << "Name \"" << name << "\" was not found" << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "Now erase some entries from the list. Notta Person will not be dropped since it isn't in the list" << std::endl;
	for (auto name : { "Albert A. Allan", "Notta Person", "Sue Jones", "Zed Zedson" })
	{
		std::cout << "Erase \"" << name << "\"" << std::endl;
		if (phoneBook.erase(name))
		{
			std::cout << "Erase was successful" << std::endl;
		}
		else
		{
			std::cout << "Erase was not successful" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Display list with " << phoneBook.size() << " items" << std::endl;
		phoneBook.print();
		std::cout << std::endl;
	}

	std::cout << "Display list with " << phoneBook.size() << " items in reverse order" << std::endl;
	std::cout << "When Sven Stevens is found in the loop, update the phone number and e-mail address" << std::endl;
	for (auto current = phoneBook.last(); current != nullptr; current = current->previous())
	{
		// note the & in auto &item allows us to update the item.
		// without this we are just updating a copy and it won't be
		// reflected in the actual phoneBook entry.
		auto &item = current->data();
		if (item.name() == "Sven Stevens")
		{
			item.phoneNumber("555-222-3333");
			item.email("sven@example.org");
		}

		std::cout << item << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Debug output" << std::endl;
	phoneBook.debug(std::cout);
	std::cout << std::endl;
}

void testList()
{
	std::cout << "DoubleLinkedList" << std::endl;
	DoubleLinkedList<int> list;
	std::cout << std::endl;
	std::cout << "First add items 1, 2, 3, 4 and 5 using push_front()" << std::endl;
	for (auto value : { 1, 2, 3, 4, 5 })
	{
		std::cout << "push_front()" << std::endl;
		list.push_front(value);
	}

	list.debug(std::cout);
	std::cout << std::endl;
	std::cout << "Remove items 5, 4, and 3 using pop_front()" << std::endl;
	for (auto value : { 5, 4, 3 })
	{
		std::cout << "pop_front() # " << value << std::endl;
		list.pop_front();
	}

	std::cout << "First add items 6, 7, 8 and 9 using push_back()" << std::endl;
	for (auto value : { 6, 7, 8, 9 })
	{
		std::cout << "push_back()" << std::endl;
		list.push_back(value);
	}

	list.debug(std::cout);

	std::cout << "Try to find entries 2, 4, 6 and 9. Item 4 will not be found." << std::endl;
	for (auto entry : { 2, 4, 6, 9 })
	{
		auto foundEntry = list.find(entry);
		if (foundEntry == nullptr)
		{
			// entry not found
			std::cout << "Entry " << entry << " was not found" << std::endl;
		}
		else
		{
			// entry found
			std::cout << "Entry " << foundEntry->data() << " was found" << std::endl;
		}
	}

	std::cout << "Remove items 9, and 8 using pop_back()" << std::endl;
	for (auto value : { 9, 8 })
	{
		std::cout << "pop_back() # " << value << std::endl;
		list.pop_back();
	}

	list.debug(std::cout);

	std::cout << "Use the print() function" << std::endl;
	list.print();

	std::cout << "Add new nodes before existing nodes." << std::endl;
	for (auto value : { 6, 2, 7, 3 })
	{
		auto findNode = list.find(value);
		if (findNode != nullptr)
		{
			std::cout << "add new node (" << value + 10 << ") before " << value << std::endl;
			list.insert_before(findNode, value + 10);
		}
		else
		{
			std::cout << "node " << value << " not found" << std::endl;
		}
	}

	list.debug(std::cout);

	std::cout << "Add new nodes after existing nodes." << std::endl;
	for (auto value : { 12, 8, 16, 7 })
	{
		auto findNode = list.find(value);
		if (findNode != nullptr)
		{
			std::cout << "add new node (" << value + 20 << ") after " << value << std::endl;
			list.insert_after(findNode, value + 20);
		}
		else
		{
			std::cout << "node " << value << " not found" << std::endl;
		}
	}

	list.debug(std::cout);

	std::cout << "Try to delete nodes 12, 8, 16, and 27." << std::endl;
	for (auto value : { 12, 8, 16, 27 })
	{
		bool deleted = list.erase(value);
		if (deleted)
		{
			std::cout << "deleted node " << value << std::endl;
		}
		else
		{
			std::cout << "node " << value << " not found" << std::endl;
		}
	}

	list.debug(std::cout);

	std::cout << "make a copy of the list" << std::endl;
	{
		auto list2(list);
		std::cout << "Original list" << std::endl;
		list.debug(std::cout);
		std::cout << "Copy of list" << std::endl;
		list2.debug(std::cout);
	}

	std::cout << "remove all entries" << std::endl;
	while (!list.empty())
	{
		std::cout << "pop_front()" << std::endl;
		list.pop_front();
	}

	list.debug(std::cout);
}
