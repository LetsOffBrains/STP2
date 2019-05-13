#pragma once
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <sstream>

#include "abstractnumber.h"

using namespace std;

class Pnumber: public AbstractNumber {
public:
	double a;
	int b, c;

	char const sep = '.';

	Pnumber();

	Pnumber(double x, int y, int z);

	int ch_to_int(char c){
		if(c >= '0' && c <= '9'){
			return c - '0';
		}
		if(c >= 'A' && c <= 'Z'){
			return c - 'A' + 10;
		}
		if(c >= 'a' && c <= 'z'){
			return c - 'a' + 10;
		}
		return -1;
	}

	Pnumber(string sa, int sb, int sc);

	virtual Pnumber *copy() override;

	virtual Pnumber& operator + (const Pnumber &Other);

	virtual Pnumber& operator * (const Pnumber &Other);

	virtual Pnumber& operator - (const Pnumber &Other);

	virtual Pnumber& operator / (const Pnumber &Other);

	virtual Pnumber& reverse();

	virtual Pnumber& square();

	virtual bool operator == (const Pnumber &Other);

	double getA() {
		return a;
	}

	char int_to_ch(unsigned int i){
		if(i >= 0 && i <= 9){
			return '0' + i;
		}
		else{
			return 'A' + (i - 10);
		}
	}

	virtual string toString();

	int getB(){
		return b;
	}

	string getBstring() {
		stringstream ss;
		ss << b;
		return ss.str();
	}

	int getC() {
		return c;
	}

	string getCstring() {
		stringstream ss;
		ss << c;
		return ss.str();
	}
	void setB(int x) {
		b = x;
	}

	void setBstring(string str) {
		stringstream ss{ str };
		ss >> b;
	}

	void setC(int y) {
		c = y;
	}

	void setCstring(string str) {
		stringstream ss{ str };
		ss >> c;
	}

	virtual Pnumber& operator -();

	virtual bool isNull();
};
