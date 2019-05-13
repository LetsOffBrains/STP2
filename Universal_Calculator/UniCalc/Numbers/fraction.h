#pragma once
#include <string>
#include <cmath>
#include <sstream>

#include "abstractnumber.h"

using namespace std;

class Fraction: public AbstractNumber {
private:
	int x, y;
public:
	Fraction();

	Fraction(int a, int b);
	
	Fraction(double d){
		x = d * 100000;
		y = 100000;
		toShorten();
	}

	Fraction(string str);

	int GCD(int a, int b) {
		return b ? GCD(b, a%b) : a;
	}

	void toShorten() {
		int k = GCD(x, y);
		x /= k;
		y /= k;
		if (y < 0) {
			y *= -1;
			x *= -1;
		}
	}

	int getA() {
		return x;
	}
	int getB() {
		return y;
	}

	virtual Fraction *copy() override;

	virtual Fraction& operator + (const Fraction &f2);

	virtual Fraction& operator * (const Fraction &f2);

	virtual Fraction& operator - (const Fraction &f2);

	virtual Fraction& operator / (const Fraction &f2);
	
	virtual Fraction& square();

	virtual Fraction& reverse();

	virtual Fraction& operator - ();

	virtual bool operator == (const Fraction &f2);

	bool operator > (const Fraction &f2)
	{
		double d1 = x / y;
		double d2 = f2.x / f2.y;

		return d1 > d2;
	}

	string getAstring() {
		stringstream ss;
		ss << x;
		return ss.str();
	}

	string getBstring() {
		stringstream ss;
		ss << y;
		return ss.str();
	}

	virtual string toString();

	operator double() const
	{
		return double(this->x / this->y);
	}

	Fraction operator = (const double &d)
	{
		this->x = d * 100000;
		this->y = 100000;
		toShorten();
		return *this;
	}

	virtual bool isNull();
};
