#include "Pnumber.h"

Pnumber::Pnumber() {
	a = 0;
	b = 2;
	c = 0;
}

Pnumber::Pnumber(double x, int y, int z) {
	b = y;
	if (b >= 2 && b <= 16) {
		a = x;
		c = z;
	}
	else {
		a = 0;
		b = 10;
		c = 3;
	}
}

Pnumber::Pnumber(string sa, int sb, int sc){
	b = sb;
	c = sc;
	a = 0;
	int mul = 1;
	size_t dot = sa.find(sep);
	if(dot == string::npos){
		for(unsigned int i = sa.length() - 1; i >= 0; --i){
			a += ch_to_int(sa[i]) * mul;
			mul *= b;
		}
	}
	else{
		for(unsigned int i = dot - 1; i >= 0; --i){
			a += ch_to_int(sa[i]) * mul;
			mul *= b;
		}

		double dmul = 1.0 / b;
		for(unsigned int i = dot + 1; i < sa.length(); ++i){
			a += ch_to_int(sa[i]) * dmul;
			//				qDebug() << ch_to_int(sa[i]) * dmul << ":" << a;
			dmul /= b;
		}
	}
}

Pnumber *Pnumber::copy()
{
	return new Pnumber(a, b, c);
}

Pnumber& Pnumber::operator +(const Pnumber &Other) {
	if (b == Other.b && c == Other.c){
		static Pnumber p(a + Other.a, b, c);
		return p;
	}
	else{
		static Pnumber p(0, 10, 0);
		return p;
	}
}

Pnumber& Pnumber::operator *(const Pnumber &Other) {
	static Pnumber p(a * Other.a, b, c);
	return p;
}

Pnumber& Pnumber::operator -(const Pnumber &Other) {
	static Pnumber p(a - Other.a, b, c);
	return p;
}

Pnumber& Pnumber::operator /(const Pnumber &Other) {
	static Pnumber p(a / Other.a, b, c);
	return p;
}

Pnumber& Pnumber::reverse() {
	static Pnumber p(1/a, b, c);
	return p;
}

Pnumber& Pnumber::square() {
	static Pnumber p(a * a, b, c);
	return p;
}

bool Pnumber::operator ==(const Pnumber &Other)
{
	if ((a == Other.a) && (b == Other.b))
		return true;
	return false;
}

string Pnumber::toString(){
	stringstream ss;

	int top = (int)(a);

	if(top < 0){
		ss << '-';
		top *= -1;
	}

	string str = "";
	while(top){
		unsigned int i = top % b;
		str.insert(0, 1, int_to_ch(i));
		top /= b;
	}
	ss << str;

	double bot = a - (int)a;
	if(bot > 0){
		ss << sep;
		int i = 0;
		double dmul = 1.0 / b;
		while(i < c && bot > 0){
			int n = 0;
			while(bot >= dmul){
				bot -= dmul;
				++n;
			}
			ss << int_to_ch(n);
			++i;
			dmul /= b;
		}
	}

	return ss.str();
}

Pnumber& Pnumber::operator -() {
	static Pnumber p(-a, b, c);
	return p;
}

bool Pnumber::isNull()
{
	if(a == 0) return true;
	return false;
}
