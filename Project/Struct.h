#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;

struct Course;
struct List_Course;

struct ID_User {
	string Social_ID;
	string Password;
};

struct Node_ID {
	ID_User User;
	Node_ID* next;
};

struct List_ID {
	Node_ID* head;
	Node_ID* tail;
};



struct Staff {
	string No;
	string Staff_ID;
	string First_Name;
	string Last_Name;
	string Gender;
	string DateOfBirth;
	string Social_ID;
};

struct Node_Staff {
	Staff User;
	Node_Staff* next;
};

struct List_Staff {
	Node_Staff* head;
	Node_Staff* tail;
};



struct Student {
	string No;
	string Student_ID;
	string First_Name;
	string Last_Name;
	string Gender;
	string DateOfBirth;
	string Social_ID;
	//List_Course lCOfStudent;
};

struct Node_Student {
	Student User;
	Node_Student* next;
};

struct List_Student {
	string ClassName;
	Node_Student* head;
	Node_Student* tail;
};



struct StudentMark {
	string No;
	string Student_ID;
	string StudentFullName;
	float TotalMark;
	float FinalMark;
	float MidtermMark;
	float OtherMark;
};

struct Node_StudentMark {
	StudentMark a;
	Node_StudentMark* next;
};

struct Scoreboard {
	Node_Student* head;
	Node_Student* tail;
};

struct Course {
	string CourseID;
	string CourseName;
	string ClassName;
	string TeacherName;
	int Credits_num;
	int Max_Student = 50;
	string DayOfWeek; //string Day[6] = {MON, TUE, WED, THU, FRI, SAT};
	string Session; //string Session[4] = { S1 (07:30), S2 (09:30), S3 (13:30), S4 (15:30)}; 
	List_Student ListOfStudent;
	Scoreboard MarksOfClass;
};

struct Node_Course {
	Course course;
	Node_Course* next;
};

struct List_Course {
	Node_Course* head;
	Node_Course* tail;
};

struct Semester {
	int Name;
	string SchoolYear;
	string Start;
	string End;
	List_Course lC;
};


struct Node_School_Year {
	List_Student a;
	Node_School_Year* next;
};

struct List_School_Year {
	string Name;
	Semester semester[3];
	Node_School_Year* head;
	Node_School_Year* tail;
};

struct Node_Year {
	List_School_Year a;
	Node_Year* next;
};

struct List_Year {
	Node_Year* head;
	Node_Year* tail;
};


static ifstream ListIDin;
static fstream ListStaff, Class18CTT2, Class18CTT3, Class18CTT4, Class19CTT2, Class19CTT3, Class19CTT4, Class20CTT2, Class20CTT3, Class20CTT4, Class21CTT2, Class21CTT3, Class21CTT4;
static List_ID lID;
static List_Staff lS;
static List_Student l18CTT2, l18CTT3, l18CTT4, l19CTT2, l19CTT3, l19CTT4, l20CTT2, l20CTT3, l20CTT4, l21CTT2, l21CTT3, l21CTT4;
static List_School_Year _2018_2019, _2019_2020, _2020_2021, _2021_2022;


