#ifndef PHONEBOOKENTRY_H_
#define PHONEBOOKENTRY_H_

#include <iostream>
#include <string>

class PhoneBookEntry 
{
private:
	std::string _name;
	std::string _number;
	std::string _email;

public:

	PhoneBookEntry(){ }

	~PhoneBookEntry() {
		std::cout << "Destructor called.\n";
	}

	PhoneBookEntry(const std::string &name, const std::string &number) :
		_name(name), _number(number) { }

	PhoneBookEntry(const std::string &name, const std::string &number, const std::string &email) :
		_name(name), _number(number), _email(email) { }

	PhoneBookEntry(const PhoneBookEntry &copyFrom) :
		_name(copyFrom.name()), _number(copyFrom.phoneNumber()), _email(copyFrom.email()) { }

	// Get the name of this entry
	std::string name() const {
		return _name;
	}

	// Get the phone number of this entry
	std::string phoneNumber() const {
		return _number;
	}

	// Get the email of this entry
	std::string email() const {
		return _email;
	}

	// Set the phone number of this entry
	void phoneNumber(const std::string &newNumber) {
		_number = newNumber;
	}

	// Set the email of this entry
	void email(const std::string &newEmail) {
		_email = newEmail;
	}

	// Overload == operator
	bool operator==(const PhoneBookEntry& o) const{
		return _name.compare(o.name()) == 0;
	}

	// Overload != operator
	bool operator!=(const PhoneBookEntry& o) const {
		return _name.compare(o.name()) != 0;
	}

	// Overload < operator
	bool operator<(const PhoneBookEntry& o) const {
		return _name.compare(o.name()) < 0;
	}

	// Overload <= operator
	bool operator<=(const PhoneBookEntry& o) const {
		return _name.compare(o.name()) <= 0;
	}

	// Overload > operator
	bool operator>(const PhoneBookEntry& o) const {
		return _name.compare(o.name()) > 0;
	}

	// Overload >= operator
	bool operator>=(const PhoneBookEntry& o) const {
		return _name.compare(o.name()) >= 0;
	}	
};

std::ostream& operator<<(std::ostream &out, const PhoneBookEntry &entry);

#endif /* PHONEBOOKENTRY_H_ */
