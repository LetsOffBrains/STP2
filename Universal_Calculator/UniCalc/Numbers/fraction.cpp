#include "fraction.h"

Fraction::Fraction() {
	x = 0;
	y = 1;
}

Fraction::Fraction(int a, int b){
	if (y == 0) {
		x = 0;
		y = 1;
	}
	else {
		y = b;
		x = a;
	}
	toShorten();
}

Fraction::Fraction(string str) {
	stringstream ss{ str };
	//		(ss >> x).ignore(numeric_limits<streamsize>::max(), '/') >> y;
	ss >> x;
	if(str.find('/') != string::npos){
		char c;
		ss >> c;
		ss >> y;
	}
	if (y == 0) {
		x = 0;
		y = 1;
	}
	toShorten();
}

Fraction *Fraction::copy() {
	return new Fraction(x, y);
}

Fraction &Fraction::operator +(const Fraction &f2) {
	static Fraction f(x * f2.y + f2.x * y, y * f2.y);
	return f;
}

Fraction &Fraction::operator *(const Fraction &f2) {
	static Fraction f(x * f2.x, y * f2.y);
	return f;
}

Fraction &Fraction::operator /(const Fraction &f2) {
	static Fraction f(x * f2.y, y * f2.x);
	return f;
}

Fraction &Fraction::square() {
	static Fraction f(x * x, y * y);
	return f;
}

Fraction &Fraction::reverse() {
	static Fraction f(y, x);
	return f;
}

Fraction &Fraction::operator -()
{
	static Fraction f(x * -1, y);
	return f;
}

bool Fraction::operator ==(const Fraction &f2)
{
	if ((x == f2.x) && (y == f2.y))
		return true;
	return false;
}

string Fraction::toString() {
	stringstream ss;
	ss << x << "/" << y;
	return ss.str();
}

bool Fraction::isNull()
{
	if(x == 0) return true;
	return false;
}

Fraction &Fraction::operator -(const Fraction &f2) {
	static Fraction f(x * f2.y - f2.x * y, y * f2.y);
	return f;
}
