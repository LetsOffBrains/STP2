#pragma once
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <sstream>

#include <QDebug>

using namespace std;

class Pnumber {
public:
	double a;
	int b, c;

	char const sep = '.';

	Pnumber() {
		a = 0;
		b = 2;
		c = 0;
	}

	Pnumber(double x, int y, int z) {
		b = y;
		if (b == 2 || b == 8 || b == 10 || b == 16) {
			a = x;
			c = z;
		}
		else {
			a = 0;
			b = 0;
			c = 0;
		}
	}

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

	Pnumber(string sa, int sb, int sc){
		b = sb;
		c = sc;
		a = 0;
		int mul = 1;
		unsigned int dot = sa.find(sep);
		if(dot == string::npos){
			qDebug() << "Only Top:";
			for(int i = sa.length() - 1; i >= 0; --i){
				qDebug() << "[" << i << "] " << sa[i];
				a += ch_to_int(sa[i]) * mul;
				mul *= b;
			}
			qDebug() << "Result:" << a;
		}
		else{
			qDebug() << "Top:";
			for(int i = dot - 1; i >= 0; --i){
				qDebug() << "[" << i << "] " << sa[i];
				a += ch_to_int(sa[i]) * mul;
				mul *= b;
			}
			qDebug() << "Middle:" << a;

			qDebug() << "Bot:";
			double dmul = 1.0 / b;
			for(int i = dot + 1; i < sa.length(); ++i){
				qDebug() << "[" << i << "] " << sa[i] << "\t" << dmul;
				a += ch_to_int(sa[i]) * dmul;
//				qDebug() << ch_to_int(sa[i]) * dmul << ":" << a;
				dmul /= b;
			}
			qDebug() << "Result:" << a;
		}
	}

	Pnumber operator + (const Pnumber &p2) {
		if (b == p2.b && c == p2.c)
			return Pnumber(a + p2.a, b, c);
		else
			return Pnumber(0, 10, 0);
	}

	Pnumber operator * (const Pnumber &p2) {
		return Pnumber(a * p2.a, b, c);
	}

	Pnumber operator - (const Pnumber &p2) {
		return Pnumber(a - p2.a, b, c);
	}

	Pnumber operator / (const Pnumber &p2) {
		return Pnumber(a / p2.a, b, c);
	}

	Pnumber reverse() {
		return Pnumber(1/a, b, c);
	}

	Pnumber square() {
		return Pnumber(a * a, b, c);
	}

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

	string getString(){
		stringstream ss;

		int top = (int)(a);

		qDebug() << a << " " << b << " "<< c;
		qDebug() << "Top:" << top;
		string str = "";
		while(top){
			int i = top % b;
			qDebug() << "[" << i << "] " << int_to_ch(i);
			str.insert(0, 1, int_to_ch(i));
			top /= b;
		}
		ss << str;

		qDebug() << ss.str().c_str();

		double bot = a - (int)a;
		if(bot > 0){
			qDebug() << "Bot:" << bot;
			ss << sep;
			int i = 0;
			double dmul = 1.0 / b;
			while(i < c && bot > 0){
				int n = 0;
				qDebug() << bot << " - " << dmul;
				while(bot >= dmul){
					bot -= dmul;
					++n;
				}
				qDebug() << "[" << n << "] " << int_to_ch(n);
				ss << int_to_ch(n);
				++i;
				dmul /= b;
			}
		}

		qDebug() << a << " " << b << " "<< c << " = " << ss.str().c_str();
		return ss.str();
	}

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
		//if (x == 2 || x == 8 || x == 10 || x == 16)
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
};
