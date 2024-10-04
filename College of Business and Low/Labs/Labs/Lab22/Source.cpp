#include <iostream>

using namespace std;

class Dot
{
protected:
	int x, y;
public:
	virtual void show()
	{
		cout << "Dot with coordinates: " << "\nX: " << x << "\nY: " << y << endl;
	}
	Dot(int x0,int y0) :x(x0), y(y0){}
	Dot(){}
};

class Line : public Dot
{
protected:
	int x1, y1;
public:
	void show() override
	{
		cout << "Line Bbetween 1";
		Dot::show();
		cout << "\tand 2Dot with coordinates X1: " << x1 << ",Y1:" << y1 << endl;
	}
	Line(int x0, int y0, int x2, int y2) : Dot(x0, y0), x1(x2), y1(y2){}
};

class Youth
{
protected:
	int x, y;
public:
	virtual void show()
	{
		cout << "Youth with weight: " << x << " и ростом: " << y << endl;
	}
	Youth(int x0, int y0) : x(x0), y(y0){}
	Youth(){}
};

class Student : public Youth
{
protected:
	int x1, y1;
public:
	void show() override
	{
		cout << "ёноша: ";
		Youth::show();
		cout << "\nStudent: " << x1 << "\t" << y1 << endl;
	}
	Student(int x0, int y0, int x2, int y2) : Youth(x0, y0), x1(x2), y1(y2){}
};

int main()
{
	setlocale(LC_ALL, "");

}
