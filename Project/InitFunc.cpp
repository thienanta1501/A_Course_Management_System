#include "Struct.h"
#include "Header.h"


//Cac ham tao Node bth

//Function of ListID
Node_ID* createNodeID(ID_User x)
{
	Node_ID* p = new Node_ID;
	p->User = x;
	p->next = NULL;
	return p;
}

void initListID(List_ID& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void inputOneID(ifstream& ListID, ID_User& x)
{
	getline(ListID, x.Social_ID, ',');
	getline(ListID, x.Password);
}

void inputListID(ifstream& ListID, List_ID& l)
{
	while (ListID.eof() == false)
	{
		ID_User x;
		inputOneID(ListID, x);
		Node_ID* q = createNodeID(x);
		if (l.head == NULL)
		{
			l.head = q;
			l.tail = q;
		}
		else
		{
			l.tail->next = q;
			l.tail = q;
		}
	}
}

void outputListID(List_ID l) //test inputListID
{
	Node_ID* p = l.head;
	while (p != NULL)
	{
		cout << p->User.Social_ID << ", " << p->User.Password << endl;
		p = p->next;
	}
}

//Function of Staff
Node_Staff* createNodeStaff(Staff x)
{
	Node_Staff* p = new Node_Staff;
	p->User = x;
	p->next = NULL;
	return p;
}

void initListStaff(List_Staff& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void inputOneStaff(fstream& ListStaff, Staff& x)
{
	getline(ListStaff, x.No, ',');
	getline(ListStaff, x.Staff_ID, ',');
	getline(ListStaff, x.First_Name, ',');
	getline(ListStaff, x.Last_Name, ',');
	getline(ListStaff, x.Gender, ',');
	getline(ListStaff, x.DateOfBirth, ',');
	getline(ListStaff, x.Social_ID);
}

void outputOneStaff(Staff x)
{
	cout << "---------------YOUR OWN PROFILE INFORMATION---------------" << endl;
	cout << "Number: " << x.No << endl;
	cout << "ID: " << x.Staff_ID << endl;
	cout << "First Name: " << x.First_Name << endl;
	cout << "Last Name: " << x.Last_Name << endl;
	cout << "Gender: " << x.Gender << endl;
	cout << "Date of Birth: " << x.DateOfBirth << endl;
	cout << "----------------------------------------------------------" << endl;
}

void inputListStaff(fstream& ListStaff, List_Staff& l)
{
	while (ListStaff.eof() == false)
	{
		Staff x;
		inputOneStaff(ListStaff, x);
		Node_Staff* q = createNodeStaff(x);
		if (l.head == NULL)
		{
			l.head = q;
			l.tail = q;
		}
		else
		{
			l.tail->next = q;
			l.tail = q;
		}
	}
}

void outputListStaff(List_Staff l) //test inputListStaff
{
	Node_Staff* p = l.head;
	while (p != NULL)
	{
		outputOneStaff(p->User);
		p = p->next;
	}
}

//Function of Student
Node_Student* createNodeStudent(Student x)
{
	Node_Student* p = new Node_Student;
	p->User = x;
	p->next = NULL;
	return p;
}

void initListStudent(List_Student& l, string ClassName)
{
	l.ClassName = ClassName;
	l.head = NULL;
	l.tail = NULL;
}

void inputOneStudent(fstream& ListStudent, Student& x)
{
	getline(ListStudent, x.No, ',');
	getline(ListStudent, x.Student_ID, ',');
	getline(ListStudent, x.First_Name, ',');
	getline(ListStudent, x.Last_Name, ',');
	getline(ListStudent, x.Gender, ',');
	getline(ListStudent, x.DateOfBirth, ',');
	getline(ListStudent, x.Social_ID);
}

void outputOneStudent(Student x)
{
	cout << "----------------------------------------------------------" << endl;
	//cout << "Number: " << x.No << endl;
	cout << "ID: " << x.Student_ID << endl;
	cout << "First Name: " << x.First_Name << endl;
	cout << "Last Name: " << x.Last_Name << endl;
	cout << "Gender: " << x.Gender << endl;
	cout << "Date of Birth: " << x.DateOfBirth << endl;
	cout << "----------------------------------------------------------" << endl;
}

void inputListStudent(fstream& ListStudent, List_Student& l)
{
	while (ListStudent.eof() == false)
	{
		Student x;
		inputOneStudent(ListStudent, x);
		Node_Student* q = createNodeStudent(x);
		if (l.head == NULL)
		{
			l.head = q;
			l.tail = q;
		}
		else
		{
			l.tail->next = q;
			l.tail = q;
		}
	}
}

void outputListStudent(List_Student l) //test inputListStudent
{
	Node_Student* p = l.head;
	while (p != NULL)
	{
		outputOneStudent(p->User);
		p = p->next;
	}
}

//Function of School Year
Node_School_Year* createNodeSchoolYear(List_Student x)
{
	Node_School_Year* p = new Node_School_Year;
	p->a = x;
	p->next = NULL;
	return p;
}

void initListSchoolYear(List_School_Year& l, string name)
{
	l.head = NULL;
	l.tail = NULL;
	l.Name = name;
	initListSemester(l.lSemester);
}

void inputOneSchoolYear(fstream& ListStudent, List_Student& x, string ClassName)
{
	initListStudent(x, ClassName);
	inputListStudent(ListStudent, x);
	//outputListStudent(x); //test inputListStudent
}

void inputListSchoolYear(List_School_Year& l, List_Student x)
{
	Node_School_Year* p = createNodeSchoolYear(x);
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

void outputListSchoolYear(List_School_Year l) //test inputListSchoolYear
{
	Node_School_Year* p = l.head;
	while (p != NULL)
	{
		cout << "-----------------" << p->a.ClassName << "-----------------" << endl;
		outputListStudent(p->a);
		p = p->next;
	}
}

//Function of Year
Node_Year* createNodeYear(List_School_Year x)
{
	Node_Year* p = new Node_Year;
	p->a = x;
	p->next = NULL;
	return p;
}

void initListYear(List_Year& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void inputListYear(List_Year& lAll, List_School_Year x)
{
	Node_Year* p = createNodeYear(x);
	if (lAll.head == NULL)
	{
		lAll.head = p;
		lAll.tail = p;
	}
	else
	{
		lAll.tail->next = p;
		lAll.tail = p;
	}
}

void outputListYear(List_Year lAll) //test inputListYear
{
	Node_Year* p = lAll.head;
	while (p != NULL)
	{
		cout << "-----------------" << p->a.Name << "-----------------" << endl;
		outputListSchoolYear(p->a);
		p = p->next;
	}
}


//Function of ListCourse
void inputOneCourse(Course& a)
{
	cout << "ENTER COURSE'S INFORMATION!" << endl;
	cout << "COURSE ID: ";
	cin >> a.CourseID;
	cout << "COURSE NAME: ";
	cin.ignore();
	getline(cin, a.CourseName);
	cout << "CLASS NAME: ";
	cin >> a.ClassName;
	cout << "TEACHER NAME: ";
	cin.ignore();
	getline(cin, a.TeacherName);
	cout << "NUMBER OF CREDITS: ";
	cin >> a.Credits_num;
	//cout << "THE MAXIMUM NUMBER OF STUDENTS IN THE COURSE: " << endl; DEFAULT: 50
	cin.ignore();
	cout << "DAY OF WEEK: ";
	cin >> a.DayOfWeek;
	cout << "THE SESSION:  ";
	cin >> a.Session;
	initListStudent(a.ListOfStudent, a.ClassName);
}

Node_Course* createNodeCourse(Course x)
{
	Node_Course* p = new Node_Course;
	p->course = x;
	p->next = NULL;
	return p;
}

void initListCourse(List_Course& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void outputOneCourse(Course x)
{
	cout << "Course ID: " << x.CourseID << endl;
	cout << "Course name: " << x.CourseName << endl;
	cout << "Class name: " << x.ClassName << endl;
	cout << "Teacher name: " << x.TeacherName << endl;
	cout << "Number of credits: " << x.Credits_num << endl;
	cout << "The maximum number of students in the course: " << x.Max_Student << endl;
	cout << "Day of the week: " << x.DayOfWeek << endl;
	cout << "The session: " << x.Session << endl;
	cout << "List of Student: " << endl;
	outputListStudent(x.ListOfStudent);
}

void outputCourseabb(Course x)
{
	cout << "Course ID: " << x.CourseID << endl;
	cout << "Course name: " << x.CourseName << endl;
	cout << "Class name: " << x.ClassName << endl;
	cout << "Teacher name: " << x.TeacherName << endl;
	cout << "Number of credits: " << x.Credits_num << endl;
	cout << "The maximum number of students in the course: " << x.Max_Student << endl;
	cout << "Day of the week: " << x.DayOfWeek << endl;
	cout << "The session: " << x.Session << endl;
}

void inputListCourse(List_Course& l)
{
	Course x;
	inputOneCourse(x);
	Node_Course* q = createNodeCourse(x);
	if (l.head == NULL)
	{
		l.head = q;
		l.tail = q;
	}
	else
	{
		l.tail->next = q;
		l.tail = q;
	}
}

void outputListCourse(Semester a)
{
	cout << "-----------------------LIST OF COURSES-----------------------" << endl;
	Node_Course* p = a.lC.head;
	int temp = 0;
	while (p != NULL)
	{
		temp++;
		cout << temp << ". " << endl;
		outputOneCourse(p->course);
		p = p->next;
	}
}

//Semester
Node_Semester* createNodeSemester(Semester x)
{
	Node_Semester* p = new Node_Semester;
	p->semester = x;
	p->next = NULL;
	return p;
}

void initListSemester(List_Semester& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void inputSemester(Semester& a)
{
	cout << "ENTER SEMESTER'S INFORMATION!" << endl;
	cout << "NUMBER OF SEMESTER: " << endl;
	cout << "1. Fall." << endl;
	cout << "2. Summer." << endl;
	cout << "3. Autumn." << endl;
	cin >> a.Name;
	cout << "SCHOOL YEAR: " << endl;
	cin >> a.SchoolYear;
	cout << "START DATE: " << endl;
	cin >> a.Start;
	cout << "END DATE: " << endl;
	cin >> a.End;
	initListCourse(a.lC);
}

void outputOneSemster(Semester a)
{
	cout << "-------------------------------------------" << endl;
	cout << "Number of semester: " << a.Name << endl;
	cout << "School year: " << a.SchoolYear << endl;
	cout << "Start date: " << a.Start << endl;
	cout << "End date: " << a.End << endl;
	cout << "List Of Courses: " << endl;
	outputListCourse(a);
	cout << "-------------------------------------------" << endl;
}

void inputListSemster(List_Year& lAll, Semester x)
{
	Node_Semester* q = createNodeSemester(x);
	Node_Year* p = lAll.head;
	while (p != NULL)
	{
		if (p->a.Name == x.SchoolYear)
		{
			if (p->a.lSemester.head == NULL)
			{
				p->a.lSemester.head = q;
				p->a.lSemester.tail = q;
			}
			else
			{
				p->a.lSemester.tail->next = q;
				p->a.lSemester.tail = q;
			}
		}
		p = p->next;
	}
}

void outputListSemester(List_Year& lAll)
{
	Node_Year* p = lAll.head;
	while (p != NULL)
	{
		Node_Semester* q = p->a.lSemester.head;
		cout << "------------------" << p->a.Name << "------------------" << endl;
		while (q != NULL)
		{
			outputOneSemster(q->semester);
			q = q->next;
		}
		p = p->next;
	}
}

void removeHead(List_Student& l)
{
	if (l.head == NULL) return;
	l.head = l.head->next;
}

void removeTail(List_Student& l)
{
	if (l.head == NULL) return;
	Node_Student* p = NULL;
	Node_Student* q = l.head;
	while (q->next != NULL)
	{
		p = q;
		q = q->next;
	}
	if (p == NULL) 
	{
		l.head = NULL;
		l.tail = NULL;
	}
	else 
	{
		p->next = NULL;
	}
}

void removeMiddle(List_Student& l, string IDStudent)
{
	if (l.head == NULL) return;
	Node_Student* p = NULL, * q = l.head, * temp = l.head->next;
	while (temp->next != NULL)
	{
		if (q->User.Student_ID == IDStudent) break;
		p = q; 
		q = q->next;
	}
	if (p == NULL)
	{
		l.head = NULL;
		l.tail = NULL;
	}
	else
	{
		p->next = q->next;
	}
}





