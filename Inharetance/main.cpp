#include<iostream>

using namespace std;

#define Delimeter "--------------------------"

class Human
{
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}
	//constructors
	Human(const std::string& last_name, const std::string& first_name, int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "constr" << endl;
	}
	virtual ~Human()
	{
		cout << "Hdestr " << this << endl;
	}
	//
	virtual	void print()const
	{
		cout << last_name << " " << first_name << " " << age << " years" << endl;
	}
};

class Student:public Human
{
	std::string speciality;
	std::string group;
	double rating;		//успеваемость
	double attendance;  //посещаемость
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_attendance()const
	{
		return attendance;
	}
	double get_rating()const
	{
		return rating;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	//constructors
	Student
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, const std::string& group, double rating, double attendance
	):Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "constStudent" << endl;
	}
	~Student()
	{
		cout << "Sdestr " << this << endl;
	}
	//methods
	void print()const
	{
		Human::print();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
};

class Teacher :public Human
{
	std::string specliality;
	int expirience;
public:
	const std::string& get_speciality()const
	{
		return specliality;
	}
	int get_expirience()const
	{
		return expirience;
	}
	void set_speciality(std::string specliality)
	{
		this->specliality = specliality;
	}
	void set_expirience(int expirience)
	{
		this->expirience = expirience;
	}
	//constr
	Teacher
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& specliality, int expirience
	) :Human(last_name, first_name, age)
	{
		set_speciality(specliality);
		set_expirience(expirience);
	}
	~Teacher()
	{
		cout << "TDestr " << this << endl;
	}
	
	//meth
	void print()const
	{
		Human::print();
		cout << specliality << " " << expirience << " years" << endl;
	}
};

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	//
	Graduate
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, const std::string& group, double rating, double attendance,
		const std::string& subject
	) :Student(last_name, first_name, age, speciality, group, rating, attendance)
	{
		set_subject(subject);
		cout << "GConstr" << endl;
	}
	~Graduate()
	{
		cout << "GDestr " << this << endl;
	}
	void print()const
	{
		Student::print();
		cout << subject << endl;
	}
};

//#define INHERITANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE_CHECK
	Human human("Payne", "Max", 30);
	human.print();

	Student student("Pincman", "Jessey", 20, "Chemistry", "WW_220", 95, 97);
	student.print();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.print();

	Graduate graduade("Schreder", "Hank", 40, "Criminalistic", "OBN", 90, 70, "How to catch Haisenberg");
	graduade.print();
#endif // INHERITANCE_CHECK

	Human* group[] =
	{
		new Student("Pincman", "Jessey", 20, "Chemistry", "WW_220", 95, 97),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 90, 70, "How to catch Haisenberg"),
		new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 98, 95),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20)
	};

	for (int i = 0; i < sizeof(group) / sizeof(group[0]);i++)
	{
		group[i]->print();
		cout << Delimeter << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]);i++)
	{
		cout << Delimeter << endl;
		delete group[i];
	}
}