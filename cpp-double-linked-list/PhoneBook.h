#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

#include <iostream>
#include <string>
#include "OrderedDoubleLinkedList.h"
#include "PhoneBookEntry.h"

class PhoneBook 
{
	private:
		OrderedDoubleLinkedList<PhoneBookEntry> list;
	public:

		// Default constructor
		PhoneBook() { }

		// Destructor
		~PhoneBook() {
			std::cout << "PhoneBook destructor called.\n";
		}

		// Insert phone book entry into phonebook
		void insert(PhoneBookEntry entry);

		// Insert phone book entry into phonebook
		void insert(const std::string &name, const std::string &number, const std::string &email) {
			PhoneBookEntry entry = PhoneBookEntry(name, number, email);
			PhoneBook::insert(entry);			
		}

		// Insert phone book entry into phonebook
		void insert(const std::string &name, const std::string &number) {
			PhoneBookEntry entry = PhoneBookEntry(name, number);
			PhoneBook::insert(entry);
		}

		// Print all the entries in the phonebook
		void print() {
			list.print();
		}

		// Get the number of entries in the phonebook
		int size() {
			return list.size();
		}

		// Check if the argument name exists in the phonebook
		bool find(std::string name);

		// Erases the entry that matches the name argument. Returns true/false if found/not found.
		bool erase(std::string name) {
			PhoneBookEntry entry = PhoneBookEntry(name, "temp-record");
			return list.erase(entry);
		}

		// Returns a pointer to the first entry in the phonebook
		ListNode<PhoneBookEntry>* first() const {
			return list.first();
		}

		// Returns a pointer to the last entry in the phonebook
		ListNode<PhoneBookEntry>* last() const {
			return list.last();
		}

		// Print debug information to the ostream argument
		void debug(std::ostream& ostream) {
			list.debug(ostream);
		}
};

// Insert phone book entry into phonebook
inline void PhoneBook::insert(PhoneBookEntry entry) {
	ListNode<PhoneBookEntry>* foundNode = list.find(entry);

	if (foundNode == NULL) {
		std::cout << "Entry not already in list. Adding.\n";
		list.insert(entry);
	}
	else {
		std::cout << "Entry already in list. Updating record.\n";
		list.erase(entry);
		list.insert(entry);
	}
}

inline bool PhoneBook::find(std::string name) {
	PhoneBookEntry entry = PhoneBookEntry(name, "temp-record");
	ListNode<PhoneBookEntry>* foundEntry = list.find(entry);

	if (foundEntry != NULL) {
		std::cout << "Found entry.\n";
		return true;
	}
	else {
		std::cout << "Did not find entry.\n";
		return false;
	}
}

#endif /* PHONEBOOK_H_ */