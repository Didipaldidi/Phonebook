#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ContactInfo {
	string name;
	string phoneNumber;
	string address;
};


class Phonebook
{
public:
	Phonebook();
	void showMenu();
	void AddContact();
	void ShowContacts();
	void seachContact();
	void DeleteContact();
	void editContact();
	void clearContacts();

private:
	vector<ContactInfo> contactList;
	int counter;
	int search(string target);
};

