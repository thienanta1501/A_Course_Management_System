#include "Struct.h"
#include "Header.h"

//Menu School year void SCHOOLYEAR(List_Year& lAll)
//Menu Begin Semester void SEMESTER(List_Year& lAll)
// void viewListCourseOfStudent()
//void viewAtAnyTime()



string identifyUser(ID_User* User)
{
	if (checkInfoInListStaff != 0) return "Staff";
	else return "Student";
}

void interfaceOfStudent(List_Year lAll, ID_User* User)
{
	string temp;
	cout << "ENTER CURRENT MONTH TO CONTINUE: ";
	cin >> temp;
	int MonthOfSystem;
	MonthOfSystem = stoi(temp);
	switch (MonthOfSystem)
	{
	case 1: {
		//Dau semester 2
		viewListCourseOfStudent();

	}
	case 2: {
		//Semester 2
		viewListCourseOfStudent();

	}
	case 3: {
		//Semester 2
		viewListCourseOfStudent();
	}
	case 4: {
		//Cuoi Semester 2
		viewListCourseOfStudent();

	}
	case 5: {
		//Dau semester 3
		viewListCourseOfStudent();

	}
	case 6: {
		//Semester 3
		viewListCourseOfStudent();

	}
	case 7: {
		//Semester 3
		viewListCourseOfStudent();

	}
	case 8: {
		//Cuoi Semester 3
		viewListCourseOfStudent();

	}
	case 9: {
		//Dau school year
		

		//Dau semester 1
		viewListCourseOfStudent();

	}
	case 10: {
		//Semester 1
		viewListCourseOfStudent();

	}
	case 11: {
		//Semester 1
		viewListCourseOfStudent();

	}
	case 12: {
		//Cuoi Semester 1
		viewListCourseOfStudent();

	}
	default: cout << "IS IT WRONG? REENTER, PLEASE!" << endl;
	}

}

void interfaceOfStaff(List_Year lAll, ID_User* User)
{
	string temp;
	cout << "ENTER CURRENT MONTH TO CONTINUE: ";
	cin >> temp;
	int MonthOfSystem;
	MonthOfSystem = stoi(temp);
	switch (MonthOfSystem)
	{
	case 1: {
		//Dau semester 2
		//SEMESTER(lAll);
		viewAtAnyTime(lAll);
		break;
	}
	case 2: {
		//Semester 2
		viewAtAnyTime(lAll);
		break;
	}
	case 3: {
		//Semester 2
		viewAtAnyTime(lAll);
		break;
	}
	case 4: {
		//Cuoi Semester 2
		viewAtAnyTime(lAll);
		break;
	}
	case 5: {
		//Dau semester 3
		//SEMESTER(lAll);
		viewAtAnyTime(lAll);
		break;
	}
	case 6: {
		//Semester 3
		viewAtAnyTime(lAll);
		break;
	}
	case 7: {
		//Semester 3
		viewAtAnyTime(lAll);
		break;
	}
	case 8: {
		//Cuoi Semester 3
		viewAtAnyTime(lAll);
		break;
	}
	case 9: {
		//Dau school year
		schoolYear(lAll);
		//Dau semester 1
		// SEMESTER(lAll);
		//viewAtAnyTime();
		break;
	}
	case 10: {
		//Semester 1
		viewAtAnyTime(lAll);
		break;
	}
	case 11: {
		//Semester 1
		viewAtAnyTime(lAll);
		break;
	}
	case 12: {
		//Cuoi Semester 1
		viewAtAnyTime(lAll);
		break;
	}
	default: cout << "IS IT WRONG? REENTER, PLEASE!" << endl;
	}

}

void schoolYear(List_Year& lAll)
{
	string temp;
	while (1)
	{
		do {
			cout << "Hello, September! It's time to begin new school year!" << endl;
			cout << "-----------------------MENU-----------------------" << endl;
			cout << "1. Create a school year." << endl;
			cout << "2. Create several classes for 1st-year students." << endl;
			cout << "3. Add new 1st year students to 1st-year classes." << endl;
			cout << "4. Import a CSV file containing all students in a specific class to the system, instead of adding one by one." << endl;
			cout << "5. Show list of students including 2nd-year, 3rd-year, or 4th-year students." << endl;

			cout << "--------------------------------------------------" << endl;
			cout << "CHOOSE YOUR ACTION!" << endl;
			cin >> temp;
		} while (temp != "1" && temp != "2" && temp != "3" && temp != "4" && temp != "5");
		int select;
		select = stoi(temp);
		switch (select)
		{
		case 1: {
			string SchoolYearName;
			cout << "ENTER NAME OF THE NEW SCHOOL YEAR: ";
			cin >> SchoolYearName;
			List_School_Year _2022_2023;
			outputListYear(lAll);
			initListSchoolYear(_2022_2023, SchoolYearName);
			inputListYear(lAll, _2022_2023);
			outputListYear(lAll);
			break;
		}
		case 2: {
			string select = "1";
			while (select == "1")
			{
				string ClassName;
				List_Student newCLass;
				cout << "ENTER NAME OF CLASS THAT YOU WANT TO: ";
				cin >> ClassName;
				initListStudent(newCLass, ClassName);
				inputListSchoolYear(lAll.tail->a, newCLass);
				cout << "DO YOU WANT TO CONTINUE TO ADD A CLASS TO THE NEW SCHOOL YEAR?" << endl;
				cout << "0. No!" << endl;
				cout << "1. Yes!" << endl;
				cin >> select;
			}
			outputListYear(lAll);
			break;
		}
		case 3: {
			string addclass;
			cout << "ENTER NAME OF CLASS THAT YOU WANT TO ADD A STUDENT TO: ";
			cin >> addclass;
			Student extraStudent;
			extraStudent = enterOneStudent();
			add1stStudent(lAll.tail->a, addclass, extraStudent);
			outputListYear(lAll);
			break;
		}
		case 4: {
			string select = "1";
			while (select == "1")
			{
				fstream csvfile;
				string filename, classname;
				cout << "ENTER NAME OF THE CLASS: ";
				cin >> classname;
				cout << "ENTER NAME OF A CSV FILE THAT YOU WANT TO IMPORT: ";
				cin >> filename;
				filename += ".csv";
				csvfile.open(filename, ios_base::in);
				inputListStudent(csvfile, findListStudent(lAll.tail->a, classname)->a);
				csvfile.close();
				cout << "DO YOU WANT TO CONTINUE?" << endl;
				cout << "0. No!" << endl;
				cout << "1. Yes!" << endl;
				cin >> select;
			}
			outputListYear(lAll);
			break;
		}
		case 5: {
			cout << "You don't need to add 2nd-year, 3rd-year, or 4th-year students, because these students had been added in the previous years.";
			outputListYear(lAll);
			break;
		}
		}
	}
	
}

void loginSystem(List_Year& lAll)
{
	while (1)
	{
		system("cls");
		cout << "------------A COURSE MANAGEMENT SYSTEM------------" << endl;
		ID_User* User = new ID_User;
		cout << "YOU MUST LOG IN TO THE SYSTEM!" << endl;
		cout << "Enter your ID: ";
		cin >> User->Social_ID;
		cout << "Enter your password: ";
		cin >> User->Password;
		if (!checkID(User)) {
			do
			{
				system("cls");
				cout << "YOUR ID OR PASSWORD IS WRONG!" << endl;
				cout << "Enter your ID: ";
				cin >> User->Social_ID;
				cout << "Enter your password: ";
				cin >> User->Password;
			} while (!checkID(User));
		}
		cout << "LOG IN SUCCESSFULLY!" << endl;
		int select;
		/*string temp;


		int MonthOfSystem;
		MonthOfSystem = stoi(temp);

		while (temp != "1" && temp != "2" && temp != "3" && temp != "4" && temp != "5");

		int select;
		select = stoi(temp);*/
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
			viewInfo(lAll, User);
			system("pause");
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
			loginSystem(lAll);
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
			if (identifyUser(User) == "Staff") interfaceOfStaff(lAll, User);
			else interfaceOfStudent(lAll, User);

		}
		}
	}
}


