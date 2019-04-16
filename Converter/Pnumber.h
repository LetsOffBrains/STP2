#pragma once
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

class Pnumber {
public:
	double a;
	int b, c;

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

	Pnumber(string sa, string sb, string sc) {
		std::istringstream(sb) >> b;
		std::istringstream(sc) >> c;
		if (b == 8 || b == 16) {
			int top;
			stringstream ss(sa);
			ss >> std::setbase(b) >> top;

			if (c) {
				double bot = 0.0;
				int tmp = 1;
				char ch;
				ch = ss.get();
				ch = ss.get();
				//string str = ss.str();

				while (ch != EOF) {
					double t = 0;
					tmp *= b;
					switch (ch){
						case '0': t = 0.0; break;
						case '1': t = 1.0; break;
						case '2': t = 2.0; break;
						case '3': t = 3.0; break;
						case '4': t = 4.0; break;
						case '5': t = 5.0; break;
						case '6': t = 6.0; break;
						case '7': t = 7.0; break;
						case '8': t = 8.0; break;
						case '9': t = 9.0; break;
						case 'a': t = 10.0; break;
						case 'b': t = 11.0; break;
						case 'c': t = 12.0; break;
						case 'd': t = 13.0; break;
						case 'e': t = 14.0; break;
						case 'f': t = 15.0; break;
						case 'A': t = 10.0; break;
						case 'B': t = 11.0; break;
						case 'C': t = 12.0; break;
						case 'D': t = 13.0; break;
						case 'E': t = 14.0; break;
						case 'F': t = 15.0; break;
						default: break;
					}
					bot += t / (double)tmp;
					//str = str.substr(1);
					ch = ss.get();
				}
				a = (double)top + bot;
			}
			else {
				a = top;
			}
		}
		else if (b == 10) {
			a = stod(sa);
		}
		else if (b == 2) {
			a = fromBin(sa);
		}
		else{
			a = 0;
			b = 0; 
			c = 0;
		}
	};

	double fromBin(string str) {
		int top = 0, tmp = 1, dot;
		double bot = 0;
		
		if (dot = str.find('.')) {
			if (dot > 0) {
				string t = str.substr(0, dot);
				string b = str.substr(dot + 1);
				while (!t.empty()) {
					top = top << 1;
					top += (t.front() == '1') ? 1 : 0;
					t = t.substr(1);
				}

				while (!b.empty()) {
					tmp *= 2;
					bot += (b.front() == '1') ? (1.0/(double)tmp) : 0;
					b = b.substr(1);
				}
			}
		}
		else {
			stringstream ss(str);
			ss >> tmp;
			vector<int> v;
			while (tmp > 0) {
				v.push_back(tmp % 2);
				tmp /= 10;
			}

			while (!v.empty()) {
				top = top << 1;
				top += v.back();
				v.pop_back();
			}
		}
		
		return (double)top + bot;
	}

	Pnumber operator + (const Pnumber &p2) {
		if (b == p2.b && c == p2.c)
			return Pnumber(a + p2.a, b, c);
		else
			return Pnumber(0, 10, 0);
	};

	Pnumber operator * (const Pnumber &p2) {
		return Pnumber(a * p2.a, b, c);
	};

	Pnumber operator - (const Pnumber &p2) {
		return Pnumber(a - p2.a, b, c);
	};

	Pnumber operator / (const Pnumber &p2) {
		return Pnumber(a / p2.a, b, c);
	};

	Pnumber reverse() {
		return Pnumber(1/a, b, c);
	};

	Pnumber square() {
		return Pnumber(a * a, b, c);
	};

	double getA() {
		return a;
	}

	string getAstring() {
		stringstream ss;
		if (a == 0) ss << "0";
		int top;
		float ttop, bot;
		unsigned int bs;
		bot = modf((float)a, &ttop);
		top = ttop;

		if (b == 2) {
			string str;
			while (top) {
				str.insert(0, (top % 2) ? "1" : "0");
				top /= 2;
			}
			ss << str;

			if (c) {
				ss << '.';
				str.clear();

				int count = 0;
				while (bot != 0 && count < c) {
					bot *= b;
					int tmp = bot;
					str.append(tmp ? "1" : "0");
					bot -= tmp;
					++count;
				}

				while (str.length() < c) {
					str += "0";
				}
				while (str.length() > c) {
					str.pop_back();
				}

				ss << str;
			}
		}
		else if (b == 8 || b == 16) {
			ss << std::setbase(b) << top;
			if (c) {
				ss << '.';
				stringstream tss;
				int count = 0;
				while (bot != 0 && count < c) {
					bot *= b;
					int tmp = bot;
					tss << (tmp < 10 ? tmp : (char)(87 + tmp));
					bot -= tmp;
					++count;
				}

				string str = tss.str();
				while(str.length() < c) {
					str += "0";
				}
				while (str.length() > c) {
					str.pop_back();
				}

				ss << str;
			}
		}
		else if (b == 10) {
			ss << fixed << setprecision(c) << a; // << fixed << setprecision(4)
		}

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
		if (x == 2 || x == 8 || x == 10 || x == 16)
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
