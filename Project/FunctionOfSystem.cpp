#include "Struct.h"
#include "Header.h"

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
	Class19CTT2.open("ListClass/19CTT2.csv", ios_base::in);
	Class19CTT3.open("ListClass/19CTT3.csv", ios_base::in);
	Class19CTT4.open("ListClass/19CTT4.csv", ios_base::in);
	Class20CTT2.open("ListClass/20CTT2.csv", ios_base::in);
	Class20CTT3.open("ListClass/20CTT3.csv", ios_base::in);
	Class20CTT4.open("ListClass/20CTT4.csv", ios_base::in);
	Class21CTT2.open("ListClass/21CTT2.csv", ios_base::in);
	Class21CTT3.open("ListClass/21CTT3.csv", ios_base::in);
	Class21CTT4.open("ListClass/21CTT4.csv", ios_base::in);
	initListYear(lAll);
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
	Class19CTT2.close();
	Class19CTT3.close();
	Class19CTT4.close();
	Class20CTT2.close();
	Class20CTT3.close();
	Class20CTT4.close();
	Class21CTT2.close();
	Class21CTT3.close();
	Class21CTT4.close();
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
		Student x = checkInfoInListStudent(lAll, User)->User;
		cout << "---------------YOUR OWN PROFILE INFORMATION---------------" << endl;
		cout << "Number: " << x.No << endl;
		cout << "ID: " << x.Student_ID << endl;
		cout << "First Name: " << x.First_Name << endl;
		cout << "Last Name: " << x.Last_Name << endl;
		cout << "Gender: " << x.Gender << endl;
		cout << "Date of Birth: " << x.DateOfBirth << endl;
		cout << "----------------------------------------------------------" << endl;
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

//Create a school year
Student enterOneStudent()
{
	Student x;
	cout << "ENTER HIS/HER PROFILE INFORMATION!" << endl;
	cout << "Student ID: ";
	cin >> x.Student_ID;
	cout << "Last Name: ";
	cin.ignore();
	getline(cin, x.Last_Name);
	cout << "First Name: ";
	getline(cin, x.First_Name);
	cout << "Gender: ";
	cin >> x.Gender;
	cout << "Date of Birth: ";
	cin >> x.DateOfBirth;
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

Node_School_Year* findListStudent(List_Year lAll, string classname)
{
	Node_Year* p = lAll.head;
	while (p != NULL)
	{
		Node_School_Year* q = p->a.head;
		while (q != NULL)
		{
			if (q->a.ClassName == classname) {
				return q;
			}
			q = q->next;
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
		if (p->course.CourseID == courseid)	return p;
		p = p->next;
	}
	return 0;
}

Course enterOneCourse(string id)
{
	Course x;
	x.CourseID = id;
	cout << "COURSE NAME: ";
	cin.ignore();
	getline(cin, x.CourseName);
	cout << "CLASS NAME: ";
	cin >> x.ClassName;
	cout << "TEACHER NAME: ";
	cin.ignore();
	getline(cin, x.TeacherName);
	cout << "NUMBER OF CREDITS: ";
	cin >> x.Credits_num;
	//cout << "THE MAXIMUM NUMBER OF STUDENTS IN THE COURSE: " << endl; DEFAULT: 50
	cin.ignore();
	cout << "DAY OF WEEK: ";
	cin >> x.DayOfWeek;
	cout << "THE SESSION:  ";
	cin >> x.Session;
	initListStudent(x.ListOfStudent, x.ClassName);
	initScoreboard(x.MarksOfCourse);
	return x;
}

void updateCourse(Semester& a, string id)
{
	Node_Course* p = a.lC.head;
	while (p != NULL)
	{
		if (p->course.CourseID == id) {
			p->course = enterOneCourse(id);
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
		Node_Course* p = NULL, * q = a.lC.head;
		while (q->next != NULL)
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

//At any time, an academic staff member can
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

void viewListCourses(List_Year lAll, string name, string semester)
{
	Node_Year* p = lAll.head;
	while (p != NULL)
	{
		if (p->a.Name == name)
		{
			Node_Semester* q = p->a.lSemester.head;
			while (q != NULL)
			{
				if (q->semester.Name == semester)
				{
					Node_Course* r = q->semester.lC.head;
					while (r != NULL)
					{
						outputCourseabb(r->course);
						r = r->next;
					}
				}
				q = q->next;
			}
		}
		p = p->next;
	}
}

void viewListStudentOfCourse(List_Year lAll, string courseid)
{
	Node_Year* p = lAll.head;
	while (p != NULL)
	{
		Node_Semester* q = p->a.lSemester.head;
		while (q != NULL)
		{
			Node_Course* r = q->semester.lC.head;
			while (r != NULL)
			{
				if (r->course.CourseID == courseid)
				{
					outputListStudent(r->course.ListOfStudent);
					return;
				}
				r = r->next;
			}
			q = q->next;
		}
		p = p->next;
	}
}

//End Semester of Staff
void outputFileListStudent(ofstream& ListStudent, Semester a, string id)
{
	Node_Course* p = findCourse(a, id);
	Node_Student* q = p->course.ListOfStudent.head;
	while (q != NULL)
	{
		ListStudent << q->User.No << "," << q->User.Student_ID << "," << q->User.First_Name << "," << q->User.Last_Name << endl;
		q = q->next;
	}
	return;
}

void reenterOneStudentMark(StudentMark& x)
{
	cout << "ENTER " << x.StudentFullName << "'S RESULT!" << endl;
	cout << "Total Mark: ";
	cin >> x.TotalMark;
	cout << "Final Mark: ";
	cin >> x.FinalMark;
	cout << "Midterm Mark: ";
	cin >> x.MidtermMark;
	cout << "Other Mark: ";
	cin >> x.OtherMark;
}

void updateStudentResult(Course& a, string studentid)
{
	Node_StudentMark* p = a.MarksOfCourse.head;
	while (p != NULL)
	{
		if (p->a.Student_ID == studentid) {
			reenterOneStudentMark(p->a);
			return;
		}
		p = p->next;
	}
}

float findFinalMark(Course a, string studentid)
{
	Node_StudentMark* p = a.MarksOfCourse.head;
	while (p != NULL)
	{
		if (p->a.Student_ID == studentid)
		{
			return p->a.TotalMark;
		}
		p = p->next;
	}
	return 0;
}

void viewListFinalMark(List_Course a, string studentid)
{
	int temp = 1;
	Node_Course* p = a.head;
	while (p != NULL)
	{
		if (findFinalMark(p->course, studentid) != 0)
		{
			cout << temp << ". " << endl;
			temp++;
			outputCourseabb(p->course);
			cout << "Final Mark: " << findFinalMark(p->course, studentid) << endl;
		}
		p = p->next;
	}
}

int countNumberCreditsOneSemester(Semester a, string studentid)
{
	int Num = 0;
	Node_Course* p = a.lC.head;
	while (p != NULL)
	{
		Node_StudentMark* q = p->course.MarksOfCourse.head;
		while (q != NULL)
		{
			if (q->a.Student_ID == studentid) {
				Num += p->course.Credits_num;
			}
			q = q->next;
		}
		p = p->next;
	}
	return Num;
}

float calGPAInOneSemester(Semester a, string studentid)
{
	float GPA = 0;
	Node_Course* p = a.lC.head;
	while (p != NULL)
	{
		Node_StudentMark* q = p->course.MarksOfCourse.head;
		while (q != NULL)
		{
			if (q->a.Student_ID == studentid)
			{
				GPA += q->a.TotalMark * p->course.Credits_num;
			}
			q = q->next;
		}
		p = p->next;
	}
	if (countNumberCreditsOneSemester(a, studentid) != 0) GPA /= countNumberCreditsOneSemester(a, studentid);
	else GPA = 0;
	//Neu Num = 0 cout << "Khong co hoc mon nao trong ky nay!" << endl;
	return GPA;
}

int countNumberCreditsAllSemester(List_Year lAll, string studentid)
{
	int Num = 0;
	Node_Year* p = lAll.head;
	while (p != NULL)
	{
		Node_Semester* q = p->a.lSemester.head;
		while (q != NULL)
		{
			Node_Course* r = q->semester.lC.head;
			while (r != NULL)
			{
				Node_StudentMark* w = r->course.MarksOfCourse.head;
				while (w != NULL)
				{
					if (w->a.Student_ID == studentid) {
						Num += r->course.Credits_num;
					}
					w = w->next;
				}
				r = r->next;
			}
			q = q->next;
		}
		p = p->next;
	}
	return Num;
}

float calOverallGPA(List_Year lAll, string studentid)
{
	float GPA = 0;
	Node_Year* p = lAll.head;
	while (p != NULL)
	{
		Node_Semester* q = p->a.lSemester.head;
		while (q != NULL)
		{
			Node_Course* r = q->semester.lC.head;
			while (r != NULL)
			{
				Node_StudentMark* w = r->course.MarksOfCourse.head;
				while (w != NULL)
				{
					if (w->a.Student_ID == studentid) {
						GPA += w->a.TotalMark * r->course.Credits_num;
					}
					w = w->next;
				}
				r = r->next;
			}
			q = q->next;
		}
		p = p->next;
	}
	GPA /= countNumberCreditsAllSemester(lAll, studentid);
	return GPA;
}