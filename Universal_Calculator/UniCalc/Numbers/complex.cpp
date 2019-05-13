#include "complex.h"

Complex::Complex() {
	a = 0;
	b = 0;
}

Complex::Complex(double x, double y){
	a = x;
	b = y;
}

Complex *Complex::copy() {
	return new Complex(a, b);
}

void Complex::Add(Complex *Other)
{
	a = a + Other->a;
	b = b + Other->b;
}

void Complex::Minus(Complex *Other)
{
	a = a - Other->a;
	b = b - Other->b;
}

void Complex::Mul(Complex *Other)
{
	a = a * Other->a - b * Other->b;
	b = a * Other->b + Other->a * b;
}

void Complex::Div(Complex *Other)
{
	a = (a * Other->a + b * Other->b) / ( Other->a * Other->a + Other->b * Other->b);
	b = (Other->a * b - a * Other->b) / (Other->a * Other->a + Other->b * Other->b);
}
/*
Complex &Complex::operator +(const Complex &Other) {
	static Complex c(a + Other.a, b + Other.b);
	return c;
}

Complex &Complex::operator -(const Complex &Other) {
	static Complex c(a - Other.a, b - Other.b);
	return c;
}

Complex &Complex::operator *(const Complex &Other) {
	static Complex c(a * Other.a - b * Other.b, a * Other.b + Other.a * b);
	return c;
}

Complex &Complex::operator /(const Complex &Other) {
	static Complex c((a * Other.a + b * Other.b) / ( Other.a * Other.a + Other.b * Other.b),
				   (Other.a * b - a * Other.b) / (Other.a * Other.a + Other.b * Other.b));
	return c;
}
*/
Complex &Complex::square() {
	static Complex c(a * a - b * b, a * b + a * b);
	return c;
}

Complex &Complex::reverse() {
	static Complex c(a / (a * a + b * b), b / (a * a + b * b));
	return c;
}

Complex &Complex::operator -()
{
	static Complex c(0, 0);
	return c - *this;
}

bool Complex::operator ==(const Complex &Other)
{
	if ((a == Other.a) && (b == Other.b))
		return true;
	return false;
}

string Complex::toString() {
	stringstream ss;
	ss << a << "+i*" << b;
	return ss.str();
}

bool Complex::isNull(){
	if(a == 0 && b == 0) return true;
	return false;
}
