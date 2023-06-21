#include "Struct.h"
#include "Header.h"


//Khoi tao du lieu cua he thong
void loading()
{
	//A function discribe when A Academic Staff Member import all Files
	ListIDin.open("ListID.csv", ios::in);
	initListID(lID);
	inputListID(ListIDin, lID);
	outputListID(lID); //test inputListID
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
	initListSchoolYear(_2018_2019);
	inputOneSchoolYear(Class18CTT2, l18CTT2);
	inputOneSchoolYear(Class18CTT3, l18CTT3);
	inputOneSchoolYear(Class18CTT4, l18CTT4);
	inputListSchoolYear(_2018_2019, l18CTT2);
	inputListSchoolYear(_2018_2019, l18CTT3);
	inputListSchoolYear(_2018_2019, l18CTT4);
	//outputListSchoolYear(_2018_2019);
	//Create 2019 - 2020
	initListSchoolYear(_2019_2020);
	inputOneSchoolYear(Class19CTT2, l19CTT2);
	inputOneSchoolYear(Class19CTT3, l19CTT3);
	inputOneSchoolYear(Class19CTT4, l19CTT4);
	inputListSchoolYear(_2019_2020, l19CTT2);
	inputListSchoolYear(_2019_2020, l19CTT3);
	inputListSchoolYear(_2019_2020, l19CTT4);
	//outputListSchoolYear(_2019_2020);
	//Create 2020 - 2021
	initListSchoolYear(_2020_2021);
	inputOneSchoolYear(Class20CTT2, l20CTT2);
	inputOneSchoolYear(Class20CTT3, l20CTT3);
	inputOneSchoolYear(Class20CTT4, l20CTT4);
	inputListSchoolYear(_2020_2021, l20CTT2);
	inputListSchoolYear(_2020_2021, l20CTT3);
	inputListSchoolYear(_2020_2021, l20CTT4);
	//outputListSchoolYear(_2020_2021);
	//Create 2021 - 2022
	initListSchoolYear(_2021_2022);
	inputOneSchoolYear(Class21CTT2, l21CTT2);
	inputOneSchoolYear(Class21CTT3, l21CTT3);
	inputOneSchoolYear(Class21CTT4, l21CTT4);
	inputListSchoolYear(_2021_2022, l21CTT2);
	inputListSchoolYear(_2021_2022, l21CTT3);
	inputListSchoolYear(_2021_2022, l21CTT4);
	//outputListSchoolYear(_2021_2022);
	inputListYear(lAll, _2018_2019);
	inputListYear(lAll, _2019_2020);
	inputListYear(lAll, _2020_2021);
	inputListYear(lAll, _2021_2022);
	//outputListYear(lAll);  
}

//A user must log in to the system
bool checkID(List_ID l, ID_User* User)
{
	Node_ID* p = l.head;
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
Node_Staff* checkInfoInListStaff(ID_User* User)
{
	Node_Staff* p = lS.head;
	while (p != NULL)
	{
		if (User->Social_ID.compare(p->User.Social_ID) == 0) return p;
		p = p->next;
	}
	return 0;
}

Node_Student* checkInfoInListStudent(ID_User* User)
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
				if (User->Social_ID.compare(r->User.Social_ID) == 0) return r;
				r = r->next;
			}
			q = q->next;
		}
		p = p->next;
	}
}

void viewInfo(ID_User* User)
{
	if (checkInfoInListStaff(User) != 0)
	{
		outputOneStaff(checkInfoInListStaff(User)->User);
		return;
	}
	if (checkInfoInListStudent(User) != 0)
	{
		outputOneStudent(checkInfoInListStudent(User)->User);
		return;
	}
}

//Change the password
Node_ID* checkListID(List_ID l, ID_User* User)
{
	Node_ID* p = l.head;
	while (p != NULL)
	{
		if (User->Social_ID.compare(p->User.Social_ID) == 0) return p;
		p = p->next;
	}
	return 0;
}

void changePassword(ID_User* User, List_ID& l, string newPassword)
{
	Node_ID* p = checkListID(l, User);
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
	cout << "First Name: ";
	cin >> x.First_Name;
	cout << "Last Name: ";
	cin >> x.Last_Name;
	cout << "Date of Birth: ";
	cin >> x.DateOfBirth;
	cout << "Social ID: ";
	cin >> x.Social_ID;
	return x;
}

void add1stStudent(List_Student& l, Student x)
{
	Node_Student* p = createNodeStudent(x);
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

void SCHOOLYEAR(List_Year& lAll)
{
	int course_num = 3; //Bien dem cac nam hoc tính 2018-2019 la 0
	//SEPTEMBER
	//An academic staff member will
	//if user is staff will
	cout << "At the beginning of a school year (often in September), you can: " << endl;
	cout << "1. Create a school year." << endl;
	course_num++;
	List_School_Year _2022_2023;
	initListSchoolYear(_2022_2023);
	//inputListYear(lAll, _2022_2023);
	cout << "2. Create several classes for 1st-year	students." << endl;
	fstream Class22CTT2, Class22CTT3, Class22CTT4;
	List_Student l22CTT2, l22CTT3, l22CTT4;
	inputOneSchoolYear(Class22CTT2, l22CTT2);
	inputOneSchoolYear(Class22CTT3, l22CTT3);
	inputOneSchoolYear(Class22CTT4, l22CTT4);
	cout << "3. Add new 1st year students to 1st-year classes." << endl;
	add1stStudent(l22CTT2, enterOneStudent());
	cout << "4. Import a CSV file." << endl;
	Class22CTT2.open("22CTT2.csv", ios_base::in);
	Class22CTT3.open("22CTT3.csv", ios_base::in);
	Class22CTT4.open("22CTT4.csv", ios_base::in);
	//Create 2022 - 2023
	initListSchoolYear(_2022_2023);
	inputListSchoolYear(_2022_2023, l22CTT2);
	inputListSchoolYear(_2022_2023, l22CTT3);
	inputListSchoolYear(_2022_2023, l22CTT4);
	//outputListSchoolYear(_2022_2023);
	cout << "5. Not need to add 2nd-year, 3rd-year, or 4th-year students." << endl;
	Class22CTT2.close();
	Class22CTT3.close();
	Class22CTT4.close();
}

//Semester
void inputSemester(Semester& a, List_Year lAll)
{
	cout << "ENTER SEMESTER'S INFORMATION!" << endl;
	cout << "NUMBER OF SEMESTER: " << endl;
	cout << "1. Fall." << endl;
	cout << "2. Summer." << endl;
	cout << "3. Autumn." << endl;
	cin >> a.Name;
	cin.ignore();
	lAll.tail->a.semester[a.Name - 1] = a;
	a.SchoolYear = lAll.tail->a.Name;
	cout << "START DATE: " << endl;
	cin >> a.Start;
	cout << "END DATE: " << endl;
	cin >> a.End;
}

void inputCourse(Course& a)
{
	cout << "ENTER COURSE'S INFORMATION!" << endl;
	cout << "COURSE ID: ";
	cin >> a.CourseID;
	cout << "COURSE NAME: ";
	cin >> a.CourseName;
	cout << "CLASS NAME: ";
	cin >> a.ClassName;
	cout << "TEACHER NAME: ";
	cin >> a.TeacherName;
	cout << "NUMBER OF CREDITS: ";
	cin >> a.Credits_num;
	cin.ignore();
	//cout << "THE MAXIMUM NUMBER OF STUDENTS IN THE COURSE: " << endl; DEFAULT: 50
	cout << "DAY OF WEEK: ";
	cin >> a.DayOfWeek;
	cout << "THE SESSION:  ";
	cin >> a.Session;
}

void updateCourse(Semester& a, string id)
{
	Node_Course* p = a.lC.head;
	while (p != NULL)
	{
		if (p->course.CourseID == id) {
			inputCourse(p->course);
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
			p->course.ListOfStudent.tail->next = q;
			p->course.ListOfStudent.tail = q;
		}
		p = p->next;
	}
}

//void removeStudentOfCourse(Semester& a, string id, string StudentID)
//{
//	Node_Course* p = a.lC.head;
//	while (p != NULL)
//	{
//		if (p->course.CourseID == id) {
//			Node_Student* q = p->course.ListOfStudent.head;
//			while (q != NULL)
//			{
//				if (q->User.Student_ID == StudentID) {
//					p->course.ListOfStudent.tail->next = q;
//					
//				}
//				p = p->next;
//			}
//		}
//		p = p->next;
//	}
//}

// void deleteCourse(Semester & a, string id)
//{
//	Node_Course* p = a.lC.head;
//	while (p != NULL)
//	{
//		if (p->course.CourseID == id) {
//			
//		}
//		p = p->next;
//	}
//}

void SEMESTER(List_Year& lAll)
{
	cout << "6. Create a semester. " << endl;
	Semester Sdemo;
	inputSemester(Sdemo, lAll);
	cout << "7. Add a course to this semester. " << endl;
	initListCourse(Sdemo.lC);
	inputListCourse(Sdemo.lC);
	cout << "8. Upload a CSV file containing a list of student enrolled in the course." << endl;
	fstream Class22CTT2;
	List_Student lSOfCourse;
	Class22CTT2.open("22CTT2.csv", ios_base::in);
	initListStudent(lSOfCourse);
	inputListStudent(Class22CTT2, lSOfCourse);
	Sdemo.lC.tail->course.ListOfStudent = lSOfCourse;
	Class22CTT2.close();
	cout << "9. View the list of courses." << endl;
	outputListCourse(Sdemo);
	cout << "10. Update course information." << endl; //Update full information
	string updatingID;
	cout << "ENTER COURSE ID OF THE COURSE THAT YOU WANT TO UPDATE: ";
	cin >> updatingID;
	updateCourse(Sdemo, updatingID);
	cout << "11. Add a student to the course." << endl;
	Student Sextra = enterOneStudent();
	string addID;
	cout << "ENTER COURSE ID OF THE COURSE THAT YOU WANT TO ADD TO: ";
	cin >> addID;
	addStudenttoCourse(Sdemo, addID, Sextra);
	cout << "12. Remove a student from the course." << endl;
	string removeID;
	cout << "ENTER COURSE ID OF THE COURSE THAT YOU WANT TO REMOVE A STUDENT: ";
	cin >> removeID;
	string SIDremove;
	cout << "ENTER STUDENT ID OF A STUDENT THAT YOU WANT TO REMOVE: ";

	cout << "13. Delete a course." << endl;
	string deleteID;
	cout << "ENTER COURSE ID OF THE COURSE THAT YOU WANT TO DELETE: ";
	cin >> deleteID;
}

//In a semester, a student still can:
void viewListCourseOfStudent(Student a, List_Course b)
{


}

//At any time, an academic staff member can:
void viewListClasses()
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

void viewAClass(string name)
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

void viewListCourses(string name, int semester)
{
	Node_Year* p = lAll.head;
	while (p != NULL)
	{
		if (p->a.Name == name)
		{
			Semester temp = p->a.semester[semester - 1];
			Node_Course* q = temp.lC.head;
			while (q != NULL)
			{
				cout << q->course.CourseID << " - " << q->course.CourseName << endl;
				q = q->next;
			}
		}
		p = p->next;
	}
}

void viewListStudentOfCourse()
{

}

void viewAtAnyTime()
{
	cout << "15. View a list of classes." << endl;
	viewListClasses();
	cout << "16. View a list of students in a class." << endl;
	string classname;
	cout << "ENTER NAME OF THE CLASS THAT YOU WANT TO VIEW: ";
	cin >> classname;
	viewAClass(classname);
	cout << "17. View a list of courses." << endl;
	string schoolyearname;
	cout << "ENTER NAME OF THE SCHOOL YEAR: ";
	cin >> schoolyearname;
	int semester;
	cout << "ENTER NUMBER'S SEMESTER OF THE SCHOOL YEAR: ";
	cin >> semester;
	viewListCourses(schoolyearname, semester);
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


