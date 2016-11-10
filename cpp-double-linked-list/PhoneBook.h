#include <iostream>
#include <string>

class PhoneBook {
	private:
		int size;
	public:
		void insert(PhoneBookEntry entry);
		void print();
		int size();
		PhoneBookEntry find(int index);
		PhoneBookEntry find(std::string name);
		bool erase(std::string name);
		PhoneBookEntry last();
		void debug(std::ostream& ostream);

};

class PhoneBookEntry {
	private:
		int num;
	public:
		PhoneBookEntry();
		PhoneBookEntry(const std::string &name, const std::string &number);
		PhoneBookEntry(const std::string &name, const std::string &number, const std::string &email);
		PhoneBookEntry(const PhoneBookEntry &copyFrom);
		std::string name() const;
		std::string phoneNumber() const;
		std::string email() const;
		void phoneNumber(const std::string &newNumber);
		void email(const std::string &newEmail);
};

std::ostream& operator<<(std::ostream &out, const PhoneBookEntry &entry);