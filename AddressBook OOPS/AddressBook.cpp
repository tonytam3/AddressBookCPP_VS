#include <iostream>
#include <string>
#include <stdlib.h>
#include "Contacts.h"
#include <fstream>

void mainMenu();
void addContact();
void updateContact();
void removeContact();
void sortContacts();
void searchContact(int update);
void transverseList(string name, int number, int userResponse);
bool testMatch();
void printNode(Contacts *Node);
void modify(int modify);
void populateContact(Contacts *current, int choice);
void displayContacts();
void bubbleMatch(int userResponse);
void swap();
string lowerCase(string input);
  

using namespace std;

Contacts *head = NULL;
Contacts *current = NULL;
Contacts *tail = NULL;

Contacts *temp = NULL;
Contacts *prevNode = NULL;

int bookSize = 0;

//Contacts *temp = new Contacts();

void mainMenu() {
	int userResponse = 0;
	while(userResponse<8||userResponse>8){

		displayContacts();

		cout << "Welcome to AddressBook.exe.\nWhat would you like to do?" <<
			"\n\t1) Add Contact" << "\n\t2) Update Existing Contact" << "\n\t3) Remove Contact" <<
			"\n\t4) SortContact" << "\n\t5) Search Contact" << "\n\t6) Save AddressBook"
			<< "\n\t7) Exit Program\n";
		cin >> userResponse;

		switch (userResponse) {
		case 1:addContact(); break;
		case 2:updateContact(); break;
		case 3:removeContact(); break;
		case 4:sortContacts(); break;
		case 5:searchContact(0); break;
		//case 6:saveAddressBook; break;
		//case 7:uploadAddressBook(); break;
		//case 8:exit(); break;
		default:cout << "Pick a valid option"; break;
		}
	}
}

void displayContacts() {
	current = head;
	if (current==NULL) {
		cout << "\nCurrent list of contacts is empty.\n\n";
	}

	else {

		while (current != NULL) {
			printNode(current);
			current = current->getNext();
		}
		
	}
}

void addContact() {
	current = new Contacts;
	modify(0);
	if (head == NULL) {
		current->setNext(head);
		head = current;
	}
	else {//Push method of Linked List;
		current->setNext(head);
		head = current;
	}

	current = head;

	while (current != NULL) {
		tail = current;
		current = current->getNext();
	}

	bookSize++;

	printNode(tail);
	cout << "====================================" << endl;

}

void updateContact() {
	searchContact(1);
}

void removeContact() { 
	searchContact(0);
	if (current == head) {
		if (current->getNext() == NULL) {
			delete current;
			current = NULL;
			head = NULL;
		}
		else {
			head = current->getNext();
			delete current;
			current = NULL;
		}
	}
	else {
		temp->setNext(current->getNext());
		delete current;
		current = NULL;
	}

	bookSize--;
}

void sortContacts() {
	int userResponse = 0;

	while (userResponse < 1 || userResponse > 6) {
		cout << "How would you like to perform the sort?\n" << "\t1) First Name\n" << "\t2) Last Name\n" << "\t3) Phone Number\n" << "\t4) Street Name\n" << "\t5) City Name\n" << "\t6) Zip Number\n"<<endl;
		cin >> userResponse;
	}
	
	
	while (head != tail) {

		current = head;
		temp = NULL;
		prevNode = NULL;

		do {
			prevNode = temp;
			temp = current;
			current = current->getNext();
			bubbleMatch(userResponse);
		} while (current != tail);

		tail = temp;

	}
		cout << "sort ended\n";
}
	//tail = temp;


void bubbleMatch(int userResponse) {
	string tempStr = " ";
	string currStr = " ";
	
		switch (userResponse) {
		case 1: if (lowerCase(temp->getFirstName()) > lowerCase(current->getFirstName())) { swap(); cout << "swap" << endl; break; }
		case 2: if (lowerCase(temp->getLastName()) > lowerCase(current->getLastName())) { swap(); break; }
		case 3: if (temp->getPhoneNumber() > current->getPhoneNumber()) { swap(); break; }
		case 4: if (lowerCase(temp->getStreet()) > lowerCase(current->getStreet())) { swap(); break; }
		case 5: if (lowerCase(temp->getCity()) > lowerCase(current->getCity())) { swap(); break; }
		case 6: if (temp->getZip() > current->getZip()) { swap(); break; }
		default: cout << "===========" << endl; break;
		}
}

void swap() {
	Contacts *box = new Contacts;
	printNode(temp);
	printNode(current);
	cout << "==========" << endl;

	if (temp == head && prevNode == NULL) {
		temp->setNext(current->getNext());
		current->setNext(temp);
		head = current;
		if (current == tail) { tail = temp; }
		current = temp;
		temp = head;
		cout << "1\n";
	}
	else {
		prevNode->setNext(current);
		temp->setNext(current->getNext());
		current->setNext(temp);
		if (current == tail) { tail = temp; }
		cout << "2\n";
		current = temp;
		temp = prevNode->getNext();
	}

	cout << "++++++++++" << endl;

}

void searchContact(int update) {
	cout << "How would you like to perform the search?\n" << "\t1) First Name\n" << "\t2) Last Name\n" << "\t3) Phone Number\n" << "\t4) Street Name\n" << "\t5) City Name\n" << "\t6) Zip Number\n";
	int userResponse = 0;
	int matchParamInt=0;
	string matchParamStr=" ";

	cin >> userResponse;
	switch (userResponse) {
	case 1: cout << "Enter First Name\n"; cin >> matchParamStr; break;
	case 2: cout << "Enter Last Name\n"; cin >> matchParamStr; break;
	case 3:	cout << "Enter Phone Number\n"; cin >> matchParamInt; break;
	case 4: cout << "Enter Street Name\n"; cin >> matchParamStr; break;
	case 5: cout << "Enter City Name\n"; cin >> matchParamStr; break;
	case 6: cout << "Enter Zip Number\n"; cin >> matchParamInt; break;
	default: cout << "Select an valid option\n"; break;
	}

	transverseList(matchParamStr, matchParamInt, userResponse);

	if (update == 1){
		modify(1);
	}

}

void transverseList(string name, int number, int userResponse) {
	temp = head;
	current = head;
	int select = 0;
	bool done = false;
	while (current != NULL&&done == false) {
		switch (userResponse) {
		case 1: if (current->getFirstName() == name && testMatch() == true) { done = true; break;}
				else { temp = current; current = current->getNext(); break; };
		case 2: if (current->getLastName() == name && testMatch() == true) { done = true; break; }
				else { temp = current; current = current->getNext(); break; };
		case 3: if (current->getPhoneNumber() == number && testMatch() == true) { done = true; break; }
				else { temp = current; current = current->getNext(); break; }
		case 4:  if (current->getStreet() == name && testMatch() == true) { done = true; break; }
				 else { temp = current; current = current->getNext(); break; }
		case 5: if (current->getCity() == name && testMatch() == true) { done = true; break; }
				else { temp = current; current = current->getNext(); break; }
		case 6: if (current->getZip() == number && testMatch() == true) { done = true; break; }
				else { temp = current; 
			current = current->getNext(); break; }
		}
	}

	if (current == NULL) { cout << "No match was found\n"; }
	cout << "Search Completed\n";
	
}

bool testMatch() {
	
	int select = 0;
	while (select != 1 || select != 2) {
		printNode(current);
		cout << "is this your match?\n" << "\t1) YES\n" << "\t2) NO\n";
		cin >> select;
		switch (select) {
		case 1:return true; break;
		case 2:return false; break;
		default: cout << "Select a valid option\n";
		}
	}
}


void printNode(Contacts *current) {
	string firstName = current->getFirstName();
	string lastName = current->getLastName();
	int phoneNumber = current->getPhoneNumber();
	string street = current->getStreet();
	string city = current->getCity();
	int zip = current->getZip();

	cout << firstName << " " << lastName << ", " << phoneNumber << ", " << street << ", " << city << ", " << zip << endl;
}

void modify(int modify){
	
	int choice = 0;
	if (modify == 1) {
		while (choice < 7 || choice>7) {
			cout << "Which part of the contact do you wish to change?\n" << "\t1) First Name\n" << "\t2) Last Name\n" << "\t3) Phone Number\n" << "\t4) StreetName\n" << "\t5) City Name\n" << "\t6) Zip Number\n" << "\t7) Exit\n";
			cin >> choice;
			populateContact(current,choice);
		}
	}
	else { populateContact(current, 0); }
	cout << "OUT2";
}

void populateContact(Contacts *current,int choice) {
	string name;
	int number;

	switch (choice) {
	case 0:cout << "Start Adding" << endl;
	case 1:cout << "Insert First Name\n"; cin >> name; current->setFirstName(name); if (choice > 0) { break; };
	case 2:cout << "Insert Last Name\n"; cin >> name; current->setLastName(name); if (choice > 0) { break; };
	case 3:cout << "Insert Phone Number\n"; cin >> number; current->setPhoneNumber(number); if (choice > 0) { break; };
	case 4:cout << "Insert Street Name\n"; cin >> name; current->setStreet(name); if (choice > 0) { break; };
	case 5:cout << "Insert City Name\n"; cin >> name; current->setCity(name); if (choice > 0) { break; };
	case 6:cout << "Insert Zip\n"; cin >> number; current->setZip(number); if (choice > 0) { break; };
	default:break;
	}
}

string lowerCase(string input) {
	string package = input;
	for (int i = 0; i < input.length(); i++) {
		package[i] = tolower(input[i]);
	}
	return package;
}

void saveContacts() {
	ofstream saveFile;
	
}


int main() {
	mainMenu();
}