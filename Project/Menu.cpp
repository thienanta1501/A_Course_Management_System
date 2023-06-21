#include "Struct.h"
#include "Header.h"

string identifyUser(ID_User* User)
{
	if (checkInfoInListStaff != 0) return "Staff";
	else return "Student";
}

void interfaceOfStudent(ID_User* User)
{
	int MonthOfSystem;
	cout << "ENTER CURRENT MONTH TO CONTINUE: ";
	cin >> MonthOfSystem;
	switch (MonthOfSystem)
	{
	case 1: {
		//Dau semester 2
	}
	case 2: {
		//Semester 2
	}
	case 3: {
		//Semester 2
	}
	case 4: {
		//Cuoi Semester 2
	}
	case 5: {
		//Dau semester 3
	}
	case 6: {
		//Semester 3
	}
	case 7: {
		//Semester 3
	}
	case 8: {
		//Cuoi Semester 3
	}
	case 9: {
		//Dau school year
		//Dau semester 1
	}
	case 10: {
		//Semester 1
	}
	case 11: {
		//Semester 1
	}
	case 12: {
		//Cuoi Semester 1
	}
	default: cout << "IS IT WRONG? REENTER, PLEASE!" << endl;
	}

}

void interfaceOfStaff(ID_User* User)
{
	int MonthOfSystem;
	cout << "ENTER CURRENT MONTH TO CONTINUE: ";
	cin >> MonthOfSystem;
	switch (MonthOfSystem)
	{
	case 1: {
		//Dau semester 2
	}
	case 2: {
		//Semester 2
	}
	case 3: {
		//Semester 2
	}
	case 4: {
		//Cuoi Semester 2
	}
	case 5: {
		//Dau semester 3
	}
	case 6: {
		//Semester 3
	}
	case 7: {
		//Semester 3
	}
	case 8: {
		//Cuoi Semester 3
	}
	case 9: {
		//Dau school year
		//Dau semester 1
	}
	case 10: {
		//Semester 1
	}
	case 11: {
		//Semester 1
	}
	case 12: {
		//Cuoi Semester 1
	}
	default: cout << "IS IT WRONG? REENTER, PLEASE!" << endl;
	}

}

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
		if (!checkID(User)) {
			do
			{
				system("cls");
				cout << "YOUR ID OR PASSWORD IS WRONG!" << endl;
				cout << "Enter your ID: " << endl;
				cin >> User->Social_ID;
				cout << "Enter your password: " << endl;
				cin >> User->Password;
			} while (!checkID(User));
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
			/*THANG 9 CREATE NEW SCHOOL YEAR NEW SEMESTER 1
			THANG 1 NEW SEMESTER 2
			THANG 5 NEW SEMESTER 3
			//Dau semester
			6 -> 13 (Staff)
			15 -> 18 (Staff)

			//Semester
			14 (Student)
			15 -> 18 (Staff)
			//Cuoi semester
			15 -> 18 (Staff)
			19 -> 23 (Staff)
			24 (Student)
			*/
			if (identifyUser(User) == "Staff") interfaceOfStaff(User);
			else interfaceOfStudent(User);

		}
		}
	}
}


