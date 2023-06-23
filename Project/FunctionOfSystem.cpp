#include "Struct.h"
#include "Header.h"


//Khoi tao du lieu cua he thong
void loading(List_Year& lAll)
{
	//A function discribe when A Academic Staff Member import all Files
	ListIDin.open("ListID.csv", ios::in);
	initListID(lID);
	inputListID(ListIDin, lID);
	//outputListID(lID); //test inputListID
	ListStaff.open("ListStaff.csv", ios_base::in);
	initListStaff(lS);
	inputListStaff(ListStaff, lS);
	//outputListStaff(lS); //test inputListStaff
	Class18CTT2.open("18CTT2.csv", ios_base::in);
	Class18CTT3.open("18CTT3.csv", ios_base::in);
	Class18CTT4.open("18CTT4.csv", ios_base::in);
	Class19CTT2.open("19CTT2.csv", ios_base::in);
	Class19CTT3.open("19CTT3.csv", ios_base::in);
	Class19CTT4.open("19CTT4.csv", ios_base::in);
	Class20CTT2.open("20CTT2.csv", ios_base::in);
	Class20CTT3.open("20CTT3.csv", ios_base::in);
	Class20CTT4.open("20CTT4.csv", ios_base::in);
	Class21CTT2.open("21CTT2.csv", ios_base::in);
	Class21CTT3.open("21CTT3.csv", ios_base::in);
	Class21CTT4.open("21CTT4.csv", ios_base::in);
	initListYear(lAll);
	//Create 2018 - 2019
	initListSchoolYear(_2018_2019, "2018-2019");
	inputOneSchoolYear(Class18CTT2, l18CTT2, "18CTT2");
	inputOneSchoolYear(Class18CTT3, l18CTT3, "18CTT3");
	inputOneSchoolYear(Class18CTT4, l18CTT4, "18CTT4");
	inputListSchoolYear(_2018_2019, l18CTT2);
	inputListSchoolYear(_2018_2019, l18CTT3);
	inputListSchoolYear(_2018_2019, l18CTT4);
	//outputListSchoolYear(_2018_2019);
	//Create 2019 - 2020
	initListSchoolYear(_2019_2020, "2019-2020");
	inputOneSchoolYear(Class19CTT2, l19CTT2, "19CTT2");
	inputOneSchoolYear(Class19CTT3, l19CTT3, "19CTT3");
	inputOneSchoolYear(Class19CTT4, l19CTT4, "19CTT4");
	inputListSchoolYear(_2019_2020, l19CTT2);
	inputListSchoolYear(_2019_2020, l19CTT3);
	inputListSchoolYear(_2019_2020, l19CTT4);
	//outputListSchoolYear(_2019_2020);
	//Create 2020 - 2021
	initListSchoolYear(_2020_2021, "2020-2021");
	inputOneSchoolYear(Class20CTT2, l20CTT2, "20CTT2");
	inputOneSchoolYear(Class20CTT3, l20CTT3, "20CTT3");
	inputOneSchoolYear(Class20CTT4, l20CTT4, "20CTT4");
	inputListSchoolYear(_2020_2021, l20CTT2);
	inputListSchoolYear(_2020_2021, l20CTT3);
	inputListSchoolYear(_2020_2021, l20CTT4);
	//outputListSchoolYear(_2020_2021);
	//Create 2021 - 2022
	initListSchoolYear(_2021_2022, "2021-2022");
	inputOneSchoolYear(Class21CTT2, l21CTT2, "21CTT2");
	inputOneSchoolYear(Class21CTT3, l21CTT3, "21CTT3");
	inputOneSchoolYear(Class21CTT4, l21CTT4, "21CTT4");
	inputListSchoolYear(_2021_2022, l21CTT2);
	inputListSchoolYear(_2021_2022, l21CTT3);
	inputListSchoolYear(_2021_2022, l21CTT4);
	//outputListSchoolYear(_2021_2022);
	inputListYear(lAll, _2018_2019);
	inputListYear(lAll, _2019_2020);
	inputListYear(lAll, _2020_2021);
	inputListYear(lAll, _2021_2022);
	//outputListYear(lAll);  
	ListIDin.close();
	ListStaff.close();
}

//A user must log in to the system
bool checkID(ID_User* User)
{
	Node_ID* p = lID.head;
	while (p != NULL)
	{
		if ((p->User.Social_ID == User->Social_ID) && (p->User.Password == User->Password))
			return 1;
		p = p->next;
	}
	return 0;
}

//He/she can view his/her own profile info, change the password, or log out the system.

//View his/her own profile info
Node_Staff* checkInfoInListStaff(List_Year lAll, ID_User* User)
{
	Node_Staff* p = lS.head;
	while (p != NULL)
	{
		if (User->Social_ID.compare(p->User.Social_ID) == 0) return p;
		p = p->next;
	}
	return 0;
}

Node_Student* checkInfoInListStudent(List_Year lAll, ID_User* User)
{
	Node_Year* p = lAll.head;
	while (p != NULL)
	{
		Node_School_Year* q = p->a.head;
		while (q != NULL)
		{
			Node_Student* r = q->a.head;
			while (r != NULL)
			{
				if (User->Social_ID == r->User.Social_ID) return r;
				r = r->next;
			}
			q = q->next;
		}
		p = p->next;
	}
}

void viewInfo(List_Year lAll, ID_User* User)
{
	if (checkInfoInListStaff(lAll, User) != 0)
	{
		outputOneStaff(checkInfoInListStaff(lAll, User)->User);
		return;
	}
	if (checkInfoInListStudent(lAll, User) != 0)
	{
		outputOneStudent(checkInfoInListStudent(lAll, User)->User);
		return;
	}
}

//Change the password
Node_ID* checkListID(ID_User* User)
{
	Node_ID* p = lID.head;
	while (p != NULL)
	{
		if (User->Social_ID.compare(p->User.Social_ID) == 0) return p;
		p = p->next;
	}
	return 0;
}

void changePassword(ID_User* User, List_ID& l, string newPassword)
{
	Node_ID* p = checkListID(User);
	p->User.Password = newPassword;
}

void outputFileListID(ofstream& ListID, List_ID l)
{
	Node_ID* p = l.head;
	while (p != NULL)
	{
		ListID << p->User.Social_ID << ", " << p->User.Password << endl;
		p = p->next;
	}
}

//At the beginning of the school year (often in September), an academic staff member will
//Create a school year (2021-2022...)

//Create a school year
Student enterOneStudent()
{
	Student x;
	cout << "ENTER HIS/HER PROFILE INFORMATION!" << endl;
	cout << "No: ";
	cin >> x.No;
	cout << "Student ID: ";
	cin >> x.Student_ID;
	cin.ignore();
	getline(cin, x.First_Name);
	cin >> x.First_Name;
	cout << "Last Name: ";
	cin >> x.Last_Name;
	cout << "Gender: ";
	cin >> x.Gender;
	cout << "Date of Birth: ";
	cin >> x.DateOfBirth;
	cout << "Social ID: ";
	cin >> x.Social_ID;
	return x;
}

void add1stStudent(List_School_Year& l, string addclass, Student x)
{
	Node_Student* q = createNodeStudent(x);
	Node_School_Year* p = l.head;
	while (p != NULL)
	{
		if (p->a.ClassName == addclass) {
			if (p->a.head == NULL)
			{
				p->a.head = q;
				p->a.tail = q;
			}
			else
			{
				p->a.tail->next = q;
				p->a.tail = q;
			}
		}
		p = p->next;
	}
}

Node_School_Year* findListStudent(List_School_Year l, string classname)
{
	Node_School_Year* p = l.head;
	while (p != NULL)
	{
		if (p->a.ClassName == classname) {
			return p;
		}
		p = p->next;
	}
}


//Semester
Node_Course* findCourse(Semester a, string courseid)
{
	Node_Course* p = a.lC.head;
	while (p != NULL)
	{
		if (p->course.CourseID == courseid) {
			return p;
		}
		p = p->next;
	}
}




void updateCourse(Semester& a, string id)
{
	Node_Course* p = a.lC.head;
	while (p != NULL)
	{
		if (p->course.CourseID == id) {
			inputOneCourse(p->course);
			return;
		}
		p = p->next;
	}
}

void addStudenttoCourse(Semester& a, string id, Student extra)
{
	Node_Student* q = createNodeStudent(extra);
	Node_Course* p = a.lC.head;
	while (p != NULL)
	{
		if (p->course.CourseID == id) {
			if (p->course.ListOfStudent.head == NULL)
			{
				p->course.ListOfStudent.head = q;
				p->course.ListOfStudent.tail = q;
			}
			else
			{
				p->course.ListOfStudent.tail->next = q;
				p->course.ListOfStudent.tail = q;
			}
		}
		p = p->next;
	}
}



void removeStudentOfCourse(Semester& a, string id, string StudentID)
{
	Node_Course* p = a.lC.head;
	while (p != NULL)
	{
		if (p->course.CourseID == id) { 
			if (p->course.ListOfStudent.head->User.Student_ID == StudentID) removeHead(p->course.ListOfStudent);
			else if (p->course.ListOfStudent.tail->User.Student_ID == StudentID) removeTail(p->course.ListOfStudent);
			else removeMiddle(p->course.ListOfStudent, StudentID);
		}
		p = p->next;
	}
}

void deleteCourse(Semester & a, string id)
{
	if (a.lC.head == NULL) return;
	if (a.lC.head->course.CourseID == id) {
		a.lC.head = a.lC.head->next;
	}
	else if (a.lC.tail->course.CourseID == id) {
		Node_Course* p = NULL;
		Node_Course* q = a.lC.head;
		while (q->next != NULL)
		{
			p = q;
			q = q->next;
		}
		if (p == NULL)
		{
			a.lC.head = NULL;
			a.lC.tail = NULL;
		}
		else
		{
			p->next = NULL;
		}
	}
	else {
		Node_Course* p = NULL, * q = a.lC.head, * temp = a.lC.head->next;
		while (temp->next != NULL)
		{
			if (q->course.CourseID == id) break;
			p = q;
			q = q->next;
		}
		if (p == NULL)
		{
			a.lC.head = NULL;
			a.lC.tail = NULL;
		}
		else
		{
			p->next = q->next;
		}
	}
}

//In a semester, a student still can:
void viewListCourseOfStudent()
{


}

//At any time, an academic staff member can:
void viewListClasses(List_Year lAll)
{
	Node_Year* p = lAll.head;
	while (p != NULL)
	{
		Node_School_Year* q = p->a.head;
		while (q != NULL)
		{
			cout << q->a.ClassName << endl;
			q = q->next;
		}
		p = p->next;
	}
}

void viewAClass(List_Year lAll, string name)
{
	Node_Year* p = lAll.head;
	while (p != NULL)
	{
		Node_School_Year* q = p->a.head;
		while (q != NULL)
		{
			if (q->a.ClassName == name) outputListStudent(q->a);
			q = q->next;
		}
		p = p->next;
	}
}

//void viewListCourses(List_Year lAll, string name, int semester)
//{
//	Node_Year* p = lAll.head;
//	while (p != NULL)
//	{
//		if (p->a.Name == name)
//		{
//			Semester temp = p->a.semester[semester - 1];
//			Node_Course* q = temp.lC.head;
//			while (q != NULL)
//			{
//				cout << q->course.CourseID << " - " << q->course.CourseName << endl;
//				q = q->next;
//			}
//		}
//		p = p->next;
//	}
//}

void viewListStudentOfCourse()
{

}

void viewAtAnyTime(List_Year lAll)
{
	cout << "15. View a list of classes." << endl;
	viewListClasses(lAll);
	cout << "16. View a list of students in a class." << endl;
	string classname;
	cout << "ENTER NAME OF THE CLASS THAT YOU WANT TO VIEW: ";
	cin >> classname;
	viewAClass(lAll, classname);
	cout << "17. View a list of courses." << endl;
	string schoolyearname;
	cout << "ENTER NAME OF THE SCHOOL YEAR: ";
	cin >> schoolyearname;
	int semester;
	cout << "ENTER NUMBER'S SEMESTER OF THE SCHOOL YEAR: ";
	cin >> semester;
	//viewListCourses(lAll, schoolyearname, semester);
	cout << "18. View a list of student in a course." << endl;
	string courseid;
	cout << "ENTER COURSE ID OF THE COURSE THAT YOU WANT TO VIEW LIST STUDENT: ";
	cin >> courseid;
	viewListStudentOfCourse();
}

//At the end of a semester, an academic staff member can:
void endSemester()
{
	cout << "19. Export a list of students in a course to a CSV file." << endl;

	cout << "20. Import the scoreboard of a course.";


}

//When 


