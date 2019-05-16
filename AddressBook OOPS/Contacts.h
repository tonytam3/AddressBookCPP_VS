#ifndef CONTACTS_H
#define CONTACTS_H
#include <string>

using namespace std;

class Contacts {
	private:
		string firstName;
		string lastName;
		int phoneNumber;
		string street;
		string city;
		int zip;
		Contacts *next;
	public:
		//Contacts();
		~Contacts();

		string getFirstName()const;
		string getLastName()const;
		string getStreet()const;
		string getCity()const;
		int getPhoneNumber()const;
		int getZip()const;
		Contacts* getNext()const;

		void setFirstName(string name);
		void setLastName(string name);
		void setPhoneNumber(int number);
		void setStreet(string name);
		void setCity(string name);
		void setZip(int number);
		void setNext(Contacts *current);

};

#endif // !CONTACTS_H

