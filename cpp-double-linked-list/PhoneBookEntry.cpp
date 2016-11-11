#include "PhoneBookEntry.h"

std::ostream & operator<<(std::ostream & out, const PhoneBookEntry & entry)
{
	out << entry.name() << "(" << entry.phoneNumber() << ")<" << entry.email() << ">";
	return out;
}
