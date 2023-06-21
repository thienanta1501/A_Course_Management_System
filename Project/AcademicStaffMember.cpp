#include "Struct.h"
#include "Header.h"


//Cac ham ve tinh nang cua Staff
//Tam
void loginSystem()
{
	while (1)
	{
		system("cls");
		cout << "------------A COURSE MANAGEMENT SYSTEM------------" << endl;
		ID_User* User = new ID_User;
		cout << "YOU MUST LOG IN TO THE SYSTEM!" << endl;
		cout << "Enter your ID: " << endl;
		cin >> User->Social_ID;
		cout << "Enter your password: " << endl;
		cin >> User->Password;
		if (!checkID(lID, User)) {
			do
			{
				cout << "YOUR ID OR PASSWORD IS WRONG!" << endl;
				cout << "Enter your ID: " << endl;
				cin >> User->Social_ID;
				cout << "Enter your password: " << endl;
				cin >> User->Password;
			} while (!checkID(lID, User));
		}
		cout << "LOG IN SUCCESSFULLY!" << endl;
		int select;
		do {
			cout << "-----------------------MENU-----------------------" << endl;
			cout << "1. View your profile info." << endl;
			cout << "2. Change your password." << endl;
			cout << "3. Log out of the system." << endl;
			cout << "4. Choose advance functions of system." << endl;
			cout << "--------------------------------------------------" << endl;
			cout << "CHOOSE YOUR ACTION!" << endl;
			cin >> select;
		} while (select != 1 && select != 2 && select != 3 && select != 4);
		switch (select)
		{
		case 1: {
			viewInfo(User);
			break;
		}
		case 2: {
			string newPassword;
			cout << "ENTER YOUR PASSWORD THAT YOU WANT TO CHANGE INTO: ";
			cin >> newPassword;
			changePassword(User, lID, newPassword);
			//outputListID(lID);
			//ofstream ListIDout;
			//ListIDout.open("ListID.csv", ios::out);
			//outputFileListID(ListIDout, lID);
			//ListIDout.close();
			//inputListID(ListIDin, lID);
			break;
		}
		case 3: {
			delete User;
			User = NULL;
			cout << "LOGGING OUT OF THE SYSTEM!" << endl;
			loginSystem();
			break;
		}
		case 4: {

		}
		}
	}
}