#include "Phonebook.h"

int main() {
	Phonebook p1;

	int select = 0;

	while (true)
	{
		p1.showMenu();

		cin >> select;

		switch (select)
		{
		case 1:
			p1.AddContact();
			break;
		case 2:
			p1.ShowContacts();
			break;
		case 3:
			p1.DeleteContact();
			break;
		case 4:
			p1.seachContact();
			break;
		case 5:
			p1.editContact();
			break;
		case 6:
			p1.clearContacts();
		case 0:
			cout << "> Thank you for using Phonebook!\n";
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}

