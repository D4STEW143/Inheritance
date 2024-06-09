#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>

using namespace std;

#define M_PI 3.14
#define Delimeter "--------------------------"


class Line
{protected:
	int side_x;
public:
	int get_side_x()const { return side_x; }
	void set_side_x(int side_x) { this->side_x = side_x; }
	Line(int side_x)
	{
		set_side_x(side_x);
		//set_side_y(side_y);
		cout << "L-Constr by\t" << this << endl;
	}
	virtual ~Line()
	{
		cout << "L-Destr by\t" << this << endl;
	}
	virtual void print()const
	{
		for (int i = 0; i < get_side_x(); i++)
		{
			cout << "*";
		}
	}
	virtual int side_size()
	{
		return side_x;
	}
	virtual void get_data()
	{
		cout << "Length of side = " << side_size() << endl;
	}
};

class Square : public Line
{
	int side_y;
public:
	int get_side_y()const { return side_y; }
	void set_side_y(int side_y) { this->side_y = side_y; }
	Square(int side_x) :Line(side_x)
	{
		set_side_y(side_x);
		cout << "S-Constr by\t" << this << endl;
	}
	~Square()
	{
		cout << "S-Destr by\t" << this << endl;
	}
	void print()const
	{
		Line::print();
		cout << endl;
		for (int i = 0; i < get_side_y() - 2; i++)
		{
			cout << "*";
			for (int j = 0; j < get_side_x() - 2; j++) { cout << "*"; }
			cout << "*";
			cout << endl;
		}
		for (int i = 0; i < get_side_x(); i++)
		{
			cout << "*";
		}
		cout << endl;
	}
	int side_size() {return Line::side_size(); }
	int square() { return side_x * 2; }
	int perimeter() { return side_x * 4; }
	void get_data()
	{
		Line::get_data();
		cout << "Perimeter of this figure =\t" << perimeter() << endl;
		cout << "Square of this figure =\t" << square() << endl;
	}
};

class Rectangle : public Square
{
	//Накосячил с ориентацией осей х и у, поэтому в примерах они поменяны местами.
public:
	Rectangle(int side_x, int side_y) :Square(side_x)
	{
		set_side_y(side_y);
		cout << "R-Constr by\t" << this << endl;
	}
	~Rectangle()
	{
		cout << "R-Destr by\t" << this << endl;
	}
	void print()const
	{
		Square::print();
	}
	int square() { return get_side_x() * get_side_y(); }
	int perimeter() { return (get_side_x() * 2) + (get_side_y() * 2); }
	void get_data() 
	{
		cout << "Height of this figure=\t" << get_side_y() << endl;
		cout << "Width of this figure=\t" << get_side_x() << endl;
		Square::get_data();
	}
};

class Circle : public Line
{
	//side_x - radius
public:
	Circle(int side_x) :Line(side_x)
	{
		cout << "C-Constr by\t" << this << endl;
	}
	~Circle()
	{
		cout << "C-Destr by\t" << this << endl;
	}
	int radius() { return Line::side_size(); }
	int diameter() { return side_x * 2; }
	int square() { return (M_PI * pow(side_x, 2.0)); }
	int circumference() { return (2 * M_PI * side_x); }
	void get_data()
	{
		cout << "Radius of this figure =\t" << radius() << endl;
		cout << "Diameter of this figure=\t" << diameter() << endl;
		cout << "Square of this figure =\t" << square() << endl;
		cout << "Length of this figure =\t" << circumference() << endl;
	}
	void print()const
	{
		for (int i = 0; i < 2 * side_x; i++)
		{
			for (int j = 0; j < 2 * side_x; j++)
			{
				if ((i - side_x) * (i - side_x) + (j - side_x) * (j - side_x) < side_x * side_x)
					cout << "*";
				else cout << " ";
			}
			cout << endl;
		}
	}
	
};

class Triangle :public Line
{
public:
	Triangle(int side_x) : Line(side_x)
	{
		cout << "T-Constr by\t" << this << endl;
	}
	~Triangle()
	{
		cout << "T\Destr by\t" << this << endl;
	}
	void print()const
	{
		for (int i = 0; i < side_x; i++) 
		{
			for (int j = 1; j < side_x - i; j++)
			{
				cout << ' ';
			}
			for (int j = side_x - 2 * i; j <= side_x; j++)
			{
				cout << '*';
			}
			cout << endl;
		}
	}
	int side_size() {return Line::side_size(); }
	int height() { return ((side_size() * sqrt(3)) / 2); }
	int square() { return 0.5 * side_size() * height(); }
	int perimeter() { return side_size() * 3; }
	void get_data()
	{
		Line::get_data();
		cout << "Height of this figure =\t" << height() << endl;
		cout << "Square of this figure =\t" << square() << endl;
		cout << "Perimeter of this figure =\t" << perimeter() << endl;
	}
};

//#define SINGLE_CHECK

void main()
{

	setlocale(LC_ALL, " ");
	
	srand(time(nullptr));

#ifdef SINGLE_CHECK
	Square sqr1(5);
	sqr1.get_data();
	sqr1.print();
	Rectangle rec1(10, 5);
	rec1.get_data();
	rec1.print();
	Circle cir1(5);
	cir1.get_data();
	cir1.print();
	Triangle tri1(6);
	tri1.get_data();
	tri1.print();
#endif // SINGLE_CHECK

	Line* group [] =
	{
		new Square(7),
		new Rectangle(14,7),
		new Circle(7),
		new Triangle(7)
	};

	random_shuffle(begin(group),end(group));

	for (int i = 0; i < sizeof(group) / sizeof(group[0]);i++)
	{
		group[i]->get_data();
		group[i]->print();
		cout << Delimeter << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]);i++)
	{
		cout << Delimeter << endl;
		delete group[i];
	}
}




