#include "Phonebook.h"

Phonebook::Phonebook() {
	counter = 0;
}

int Phonebook::search(string target) {
	int low = 0;
	int high = contactList.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (target == contactList[mid].name) {
			return mid;
		}
		else if (target > contactList[mid].name) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}

	}
	return -1;
}

void Phonebook::showMenu() {
	cout << "********************************" << endl;
	cout << "********** Phonebook ***********" << endl;
	cout << "********************************" << endl;
	cout << "*****    1. Add contact    *****" << endl;
	cout << "*****    2. Show contacts  *****" << endl;
	cout << "*****    3. Delete contact *****" << endl;
	cout << "*****    4. Find contact   *****" << endl;
	cout << "*****    5. Edit contact   *****" << endl;
	cout << "*****    6. Clear contacts *****" << endl;
	cout << "*****    0. Exit           *****" << endl;
	cout << "********************************" << endl;
	cout << "********************************" << endl;
	cout << "********************************" << endl;
	cout << "> Please enter a number from the above list\n";
}

void Phonebook::AddContact() {
	ContactInfo contact;

	cout << "> Inser contact info: \n";

	cout << "> Name: ";
	cin >> contact.name;
	cout << endl;

	cout << "> Phone number: ";
	cin >> contact.phoneNumber;
	cout << endl;

	cout << "> Address: ";
	cin >> contact.address;
	cout << endl;

	contactList.push_back(contact);
	counter++;

	// sort in alphabetical order
	sort(contactList.begin(), contactList.end(), [](const ContactInfo& lhs, const ContactInfo& rhs) {
		return lhs.name < rhs.name;
		});

	cout << "> Contact added successfully! \n";

	system("pause");
	system("cls");
}

void Phonebook::ShowContacts() {
	if (contactList.size() == 0) {
		cout << "> Phonebook is empty!\n";
	}
	else {
		for (auto it = contactList.begin(); it != contactList.end(); it++) {
			cout << "//-------------------------------------------------//\n";
			cout << "> Name: " << it->name << endl;
			cout << "> Phone number: " << it->phoneNumber << endl;
			cout << "> Address: " << it->address << endl;
		}
	}
	system("pause");
	system("cls");
}

void Phonebook::seachContact() {
	string target;

	cout << "Enter contact's name you want to search: ";
	cin >> target;

	int found = search(target);
	
	if (found == -1) {
		cout << "> Contact not found!\n";
	}
	else {
		cout << "> Contact info found! \n";
		cout << "> Name: " << contactList[found].name << endl;
		cout << "> Phone number: " << contactList[found].phoneNumber << endl;
		cout << "> Address: " << contactList[found].address << endl;
	}
	system("pause");
	system("cls");
}

void Phonebook::DeleteContact() {
	string target;

	cout << "Enter contact's name you wish to delete: ";
	cin >> target;

	int found = search(target);

	if (found == -1) {
		cout << "> Contact not found!\n";
	}
	else {
		cout << "> Contact info deleted! \n";
		cout << "> Name: " << contactList[found].name << endl;
		cout << "> Phone number: " << contactList[found].phoneNumber << endl;
		cout << "> Address: " << contactList[found].address << endl;
		contactList.erase(remove_if(contactList.begin(), contactList.end(), [&](ContactInfo const& contactList) {
			return contactList.name == target;
			}), contactList.end());
	}
	system("pause");
	system("cls");

}

void Phonebook::editContact() {
	string target;

	cout << "Enter contact's name you want to change: ";
	cin >> target;

	int found = search(target);

	if (found == -1) {
		cout << "> Contact not found!\n";
	}
	else {
		cout << "> Contact info found! \n";
		cout << "> Please enter the revised name: ";
		cin >> contactList[found].name;
		cout << endl;
		cout << "> Please enter the revised phone number: ";
		cin >> contactList[found].phoneNumber;
		cout << endl;
		cout << "> Please enter the revised address: ";
		cin >> contactList[found].address;
		cout << endl;
		cout << "> Contact info changed successfully!\n";
	}
	system("pause");
	system("cls");
}

void Phonebook::clearContacts() {
	char ans = 'n';
	cout << "> Are you sure you want to delete the phonebook?\n";
	cout << "> Enter n for no and y for yes: ";
	while (true) {
		cin >> ans;
		if (ans == 'y' || ans == 'n') {
			
			break;
		}
		else {
			cout << "> Invalid input, please try again!\n";
		}
	}

	if (ans == 'y') {
		contactList.clear();
		cout << "> Phonebook deleted!";
	}
	else {
		cout << "> Phonebook deletion canceled!\n";
	}
}