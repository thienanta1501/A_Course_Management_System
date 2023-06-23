#include "Struct.h"
#include "Header.h"

//Menu School year void SCHOOLYEAR(List_Year& lAll)
//Menu Begin Semester void SEMESTER(List_Year& lAll)
// void viewListCourseOfStudent()
//void viewAtAnyTime()

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

string identifyUser(ID_User* User)
{
	int temp = stoi(User->Social_ID);
	if (temp < 10000000) return "Staff";
	else return "Student";
}

void interfaceOfStudent(List_Year& lAll, ID_User* User)
{
	int _temp = 1;
	while (_temp)
	{
		string temp;
		cout << "ENTER CURRENT MONTH TO CONTINUE: ";
		cin >> temp;
		int MonthOfSystem;
		MonthOfSystem = stoi(temp);
		switch (MonthOfSystem)
		{
		case 1: {
			system("cls");
			//Dau semester 2
			viewListCourseOfStudent(lAll.tail->a.lSemester.tail->semester, User->Social_ID);
			system("pause");
		}
		case 2: {
			system("cls");
			//Semester 2
			viewListCourseOfStudent(lAll.tail->a.lSemester.tail->semester, User->Social_ID);
			system("pause");
		}
		case 3: {
			system("cls");
			//Semester 2
			viewListCourseOfStudent(lAll.tail->a.lSemester.tail->semester, User->Social_ID);
			system("pause");
		}
		case 4: {
			system("cls");
			//Cuoi Semester 2
			viewListCourseOfStudent(lAll.tail->a.lSemester.tail->semester, User->Social_ID);
			system("pause");
		}
		case 5: {
			system("cls");
			//Dau semester 3
			viewListCourseOfStudent(lAll.tail->a.lSemester.tail->semester, User->Social_ID);
			system("pause");
		}
		case 6: {
			system("cls");
			//Semester 3
			viewListCourseOfStudent(lAll.tail->a.lSemester.tail->semester, User->Social_ID);
			system("pause");
		}
		case 7: {
			system("cls");
			//Semester 3
			viewListCourseOfStudent(lAll.tail->a.lSemester.tail->semester, User->Social_ID);
			system("pause");
		}
		case 8: {
			//Cuoi Semester 3
			viewListCourseOfStudent(lAll.tail->a.lSemester.tail->semester, User->Social_ID);
			system("pause");
		}
		case 9: {
			system("cls");
			viewListCourseOfStudent(lAll.tail->a.lSemester.tail->semester, User->Social_ID);
			system("pause");
		}
		case 10: {
			system("cls");
			//Semester 1
			viewListCourseOfStudent(lAll.tail->a.lSemester.tail->semester, User->Social_ID);
			system("pause");
		}
		case 11: {
			system("cls");
			//Semester 1
			viewListCourseOfStudent(lAll.tail->a.lSemester.tail->semester, User->Social_ID);
			system("pause");
		}
		case 12: {
			system("cls");
			//Cuoi Semester 1
			viewListCourseOfStudent(lAll.tail->a.lSemester.tail->semester, User->Social_ID);
			system("pause");
		}
		default: cout << "IS IT WRONG? REENTER, PLEASE!" << endl;
		}
		cout << "DO YOU WANT TO CONTINUE?" << endl;
		cout << "0. No!" << endl;
		cout << "1. Yes!" << endl;
		cin >> _temp;
	}
}

void interfaceOfStaff(List_Year& lAll, ID_User* User)
{
	int _temp = 1;
	while (_temp)
	{
		int MonthOfSystem;
		cout << "ENTER CURRENT MONTH TO CONTINUE: ";
		cin >> MonthOfSystem;
		switch (MonthOfSystem)
		{
		case 1: {
			system("cls");
			//Dau semester 2
			beginSemester(lAll);
			viewAtAnyTime(lAll);
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			//Semester 2
			viewAtAnyTime(lAll);
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			//Semester 2
			viewAtAnyTime(lAll);
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			//Cuoi Semester 2
			viewAtAnyTime(lAll);
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			//Dau semester 3
			beginSemester(lAll);
			viewAtAnyTime(lAll);
			system("pause");
			break;
		}
		case 6: {
			system("cls");
			//Semester 3
			viewAtAnyTime(lAll);
			system("pause");
			break;
		}
		case 7: {
			system("cls");
			//Semester 3
			viewAtAnyTime(lAll);
			system("pause");
			break;
		}
		case 8: {
			system("cls");
			//Cuoi Semester 3
			viewAtAnyTime(lAll);
			system("pause");
			break;
		}
		case 9: {
			system("cls");
			//Dau school year
			schoolYear(lAll);
			//Dau semester 1
			beginSemester(lAll);
			//viewAtAnyTime();
			system("pause");
			break;
		}
		case 10: {
			system("cls");
			//Semester 1
			viewAtAnyTime(lAll);
			system("pause");
			break;
		}
		case 11: {
			system("cls");
			//Semester 1
			viewAtAnyTime(lAll);
			system("pause");
			break;
		}
		case 12: {
			system("cls");
			//Cuoi Semester 1
			viewAtAnyTime(lAll);
			system("pause");
			break;
		}
		default: cout << "IS IT WRONG? REENTER, PLEASE!" << endl;
		}
		cout << "DO YOU WANT TO CONTINUE WITH UPDATING INFORMATION OF SCHOOL?" << endl;
		cout << "0. No!" << endl;
		cout << "1. Yes!" << endl;
		cin >> _temp;
	}
	
}

void schoolYear(List_Year& lAll)
{
	string temp;
	while (1)
	{
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
		int select;
		select = stoi(temp);
		switch (select)
		{
		case 1: {
			system("cls");
			string SchoolYearName;
			cout << "ENTER NAME OF THE NEW SCHOOL YEAR: ";
			cin >> SchoolYearName;
			List_School_Year _2022_2023;
			outputListYear(lAll);
			initListSchoolYear(_2022_2023, SchoolYearName);
			inputListYear(lAll, _2022_2023);
			outputListYear(lAll);
			system("pause");
			break;
		}
		case 2: {
			system("cls");
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
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			string addclass;
			cout << "ENTER NAME OF CLASS THAT YOU WANT TO ADD A STUDENT TO: ";
			cin >> addclass;
			Student extraStudent;
			extraStudent = enterOneStudent();
			add1stStudent(lAll.tail->a, addclass, extraStudent);
			outputListYear(lAll);
			system("pause");
			break;
		}
		case 4: {
			system("cls");
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
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			cout << "You don't need to add 2nd-year, 3rd-year, or 4th-year students, because these students had been added in the previous years.";
			outputListYear(lAll);
			system("pause");
			break;
		}
		default: cout << "IS IT WRONG? REENTER, PLEASE!" << endl;
		}
	}
	
}

void beginSemester(List_Year& lAll)
{
	int _temp = 1;
	while (_temp)
	{
		string temp;
		cout << "Hello! It's time to begin new semester!" << endl;
		cout << "-----------------------MENU-----------------------" << endl;
		cout << "6. Create a semester." << endl;
		cout << "7. Add a course to this semester." << endl;
		cout << "8. Upload a CSV file containing a list of student enrolled in the course." << endl;
		cout << "9. View a list of courses." << endl;
		cout << "10. Update course information." << endl;
		cout << "11. Add a student to the course." << endl;
		cout << "12. Remove a student from the course." << endl;
		cout << "13. Delete a course." << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "CHOOSE YOUR ACTION!" << endl;
		cin >> temp;
		int select;
		select = stoi(temp);
		switch (select)
		{
		case 6: {
			system("cls");
			Semester Sdemo;
			inputSemester(Sdemo);
			inputListSemster(lAll, Sdemo);
			outputListSemester(lAll);
			system("pause");
			break;
		}
		case 7: {
			system("cls");
			inputListCourse(lAll.tail->a.lSemester.tail->semester.lC);
			outputListSemester(lAll);
			system("pause");
			break;
		}
		case 8: {
			system("cls");
			string select = "1";
			while (select == "1")
			{
				fstream csvfile;
				string filename, courseid;
				cout << "ENTER COURSE ID OF THE COURSE: ";
				cin >> courseid;
				cout << "ENTER NAME OF A CSV FILE THAT YOU WANT TO UPLOAD: ";
				cin >> filename;
				filename += ".csv";
				csvfile.open(filename, ios_base::in);
				inputListStudent(csvfile, findCourse(lAll.tail->a.lSemester.tail->semester, courseid)->course.ListOfStudent);
				csvfile.close();
				cout << "DO YOU WANT TO CONTINUE?" << endl;
				cout << "0. No!" << endl;
				cout << "1. Yes!" << endl;
				cin >> select;
			}
			outputListSemester(lAll);
			system("pause");
			break;
		}
		case 9: {
			system("cls");
			cout << "-----------------------LIST OF COURSES-----------------------" << endl;
			Node_Course* p = lAll.tail->a.lSemester.tail->semester.lC.head;
			int temp = 0;
			while (p != NULL)
			{
				temp++;
				cout << temp << ". " << endl;
				outputCourseabb(p->course);
				p = p->next;
			}
			system("pause");
			break;
		}
		case 10: {
			system("cls");
			string updatingID;
			cout << "ENTER COURSE ID OF THE COURSE THAT YOU WANT TO UPDATE: ";
			cin >> updatingID;
			updateCourse(lAll.tail->a.lSemester.tail->semester, updatingID);
			outputOneSemster(lAll.tail->a.lSemester.tail->semester);
			system("pause");
			break;
		}
		case 11: {
			system("cls");
			Student Sextra = enterOneStudent();
			string addID;
			cout << "ENTER COURSE ID OF THE COURSE THAT YOU WANT TO ADD TO: ";
			cin >> addID;
			addStudenttoCourse(lAll.tail->a.lSemester.tail->semester, addID, Sextra);
			outputOneSemster(lAll.tail->a.lSemester.tail->semester);
			system("pause");
			break;
		}
		case 12: {
			system("cls");
			string removeID;
			cout << "ENTER COURSE ID OF THE COURSE THAT YOU WANT TO REMOVE A STUDENT: ";
			cin >> removeID;
			string SIDremove;
			cout << "ENTER STUDENT ID OF A STUDENT THAT YOU WANT TO REMOVE: ";
			cin >> SIDremove;
			removeStudentOfCourse(lAll.tail->a.lSemester.tail->semester, removeID, SIDremove);
			outputOneSemster(lAll.tail->a.lSemester.tail->semester);
			system("pause");
			break;
		}
		case 13: {
			system("cls");
			string deleteID;
			cout << "ENTER COURSE ID OF THE COURSE THAT YOU WANT TO DELETE: ";
			cin >> deleteID;
			deleteCourse(lAll.tail->a.lSemester.tail->semester, deleteID);
			outputOneSemster(lAll.tail->a.lSemester.tail->semester);
			system("pause");
			break;
		}
		default: cout << "IS IT WRONG? REENTER, PLEASE!" << endl;
		}
		cout << "DO YOU WANT TO CONTINUE WITH UPDATING THE NEW SEMESTER?" << endl;
		cout << "0. No!" << endl;
		cout << "1. Yes!" << endl;
		cin >> _temp;
	}
}

void viewListCourseOfStudent(Semester a, string StudentID)
{
	cout << "----------------YOUR LIST OF COURSES----------------" << endl;
	int temp = 1;
	Node_Course* p = a.lC.head;
	while (p != NULL)
	{ 
		Node_Student* q = p->course.ListOfStudent.head;
		while (q != NULL)
		{
			if (q->User.Student_ID == StudentID)
			{
				cout << temp << ". " << endl;
				temp++;
				outputCourseabb(p->course);
			}
			q = q->next;
		}
		p = p->next;
	}

}

void viewAtAnyTime(List_Year lAll)
{
	int _temp = 1;
	while (_temp)
	{
		string temp;
		cout << "Hello! What do you want to view?" << endl;
		cout << "-----------------------MENU-----------------------" << endl;
		cout << "15. View a list of classes." << endl;
		cout << "16. View a list of student in a class." << endl;
		cout << "17. View a list of courses." << endl;
		cout << "18. View a list of student in a course." << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "CHOOSE YOUR ACTION!" << endl;
		cin >> temp;
		int select;
		select = stoi(temp);
		switch (select)
		{
		case 15: {
			system("cls");
			viewListClasses(lAll);
			system("pause");
			break;
		}
		case 16: {
			system("cls");
			string classname;
			cout << "ENTER NAME OF THE CLASS THAT YOU WANT TO VIEW: ";
			cin >> classname;
			viewAClass(lAll, classname);
			system("pause");
			break;
		}
		case 17: {
			system("cls");
			string schoolyearname;
			cout << "ENTER NAME OF THE SCHOOL YEAR: ";
			cin >> schoolyearname;
			string semester;
			cout << "ENTER NUMBER'S SEMESTER OF THE SCHOOL YEAR: ";
			cin >> semester;
			viewListCourses(lAll, schoolyearname, semester);
			system("pause");
			break;
		}
		case 18: {
			system("cls");
			string courseid;
			cout << "ENTER COURSE ID OF THE COURSE THAT YOU WANT TO VIEW LIST STUDENT: ";
			cin >> courseid;
			viewListStudentOfCourse(lAll, courseid);
			system("pause");
			break;
		}
		default: cout << "IS IT WRONG? REENTER, PLEASE!" << endl;
		}
		cout << "DO YOU WANT TO CONTINUE WITH VIEW LISTS?" << endl;
		cout << "0. No!" << endl;
		cout << "1. Yes!" << endl;
		cin >> _temp;
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
		while (1)
		{
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
				system("cls");
				viewInfo(lAll, User);
				system("pause");
				break;
			}
			case 2: {
				system("cls");
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
				system("pause");
				break;
			}
			case 3: {
				system("cls");
				delete User;
				User = NULL;
				cout << "LOGGING OUT OF THE SYSTEM!" << endl;
				loginSystem(lAll);
				system("pause");
				break;
			}
			case 4: {
				system("cls");
				if (identifyUser(User) == "Staff") interfaceOfStaff(lAll, User);
				else interfaceOfStudent(lAll, User);
				system("pause");
			}
			default: cout << "IS IT WRONG? REENTER, PLEASE!" << endl;
			}

		}
		
	}
}


