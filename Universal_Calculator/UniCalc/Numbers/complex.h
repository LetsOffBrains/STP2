#pragma once
#include <string>
#include <cmath>
#include <sstream>

#include "abstractnumber.h"

#define M_PI 3.14159265358979323846

using namespace std;

class Complex: public AbstractNumber{
public:
	double a, b;

	Complex();

	Complex(double x, double y);

	Complex(string str) {
		stringstream ss{ str };
		ss >> a;
		if(str.find("+i*") != string::npos){
			char c;
			ss >> c >> c >> c;
			ss >> b; //numeric_limits<streamsize>::max(), "+i*"
		}
	}

	virtual Complex* copy() override;

	virtual void Add (Complex *Other);
	virtual void Minus (Complex *Other);
	virtual void Mul (Complex *Other);
	virtual void Div (Complex *Other);

//	virtual Complex& operator + (const Complex &Other);

//	virtual Complex& operator * (const Complex &Other);

	virtual Complex& square();

	virtual Complex& reverse();

//	virtual Complex& operator - (const Complex &Other);

//	virtual Complex& operator / (const Complex &Other);

	virtual Complex& operator - ();
	
	double cmod() {
		return sqrt(a * a + b * b);
	}

	double crad() {
		if (a > 0) {
			return atan(b / a);
		}
		else if(a == 0 && b > 0) {
			return M_PI / 2;
		}
		else if (a < 0) {
			return atan(b / a) + M_PI;
		}
		else {
			return -M_PI / 2;
		}
	}

	double cdeg() {
		return crad() * 180 / M_PI;
	}

	Complex& cpow(int n) {
		static Complex c(pow(cmod(), n) * cos(n * crad()),
			pow(cmod(), n) * sin(n * crad()));
		return c;
	}

	Complex& csqrt(int n, int i) {
		static Complex c(sqrt(cmod()) * (cos((crad() + 2 * i * M_PI) / n)),
			sqrt(cmod()) * (sin((crad() + 2 * i * M_PI) / n)));
		return c;
	}
	
	virtual bool operator == (const Complex &Other);

	bool operator != (const Complex &Other) {
		return !(*this == Other);
	}

	double getRe() {
		return a;
	}

	string getReString() {
		stringstream ss;
		ss << a;
		return ss.str();
	}

	double getIm() {
		return b;
	}

	string getImString() {
		stringstream ss;
		ss << b;
		return ss.str();
	}

	virtual string toString();

	void setNull(){
		a = 0;
		b = 0;
	}

	virtual bool isNull();

	bool IsReal(){
		if(b == 0) return true;
		return false;
	}

	string toReal() {
		stringstream ss;
		ss << a;
		return ss.str();
	}
};


