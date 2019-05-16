#include <iostream>
#include "Contacts.h"

using namespace std;

/*Contacts::Contacts()
{

}*/

Contacts::~Contacts()
{
	cout << "Destructor Called" << endl;
}

string Contacts::getFirstName() const {
	return firstName;
};

string Contacts::getLastName() const {
	return lastName;
};

int Contacts::getPhoneNumber() const {
	return phoneNumber;
};

string Contacts::getStreet() const {
	return street;
}

string Contacts::getCity()const {
	return city;
}

int Contacts::getZip()const {
	return zip;
}

Contacts* Contacts::getNext()const {
	return next;
}

void Contacts::setFirstName(string name)
{
	this->firstName = name;
}

void Contacts::setLastName(string name)
{
	this->lastName = name;
}

void Contacts::setPhoneNumber(int number)
{
	this->phoneNumber = number;
}

void Contacts::setStreet(string name)
{
	this->street = name;
}

void Contacts::setCity(string name)
{
	this->city = name;
}

void Contacts::setZip(int number)
{
	this->zip = number;
}

void Contacts::setNext(Contacts *current)
{
	this->next = current;
}





