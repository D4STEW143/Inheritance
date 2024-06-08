#include<iostream>

using namespace std;

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
			cout << "+";
		}
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
			cout << "+";
			for (int j = 0; j < get_side_x() - 2; j++) { cout << " "; }
			cout << "+";
			cout << endl;
		}
		for (int i = 0; i < get_side_x(); i++)
		{
			cout << "+";
		}
		cout << endl;
	}
};

class Rectangle : public Square
{
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
};

void main()
{
	setlocale(LC_ALL, " ");
	Square sqr1(5);
	sqr1.print();
	Rectangle rec1(10, 5);
	rec1.print();


}