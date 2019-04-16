#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include "Pnumber.h"

using namespace std;

string const Nu = "0";

class TEditor
{
private:
	string CEdit; // строка
	string const separator = ",";
	

public:
	enum
	{
		Sign = 20,
		Erase = 21,
		RemoveAll = 22,
		Dot = 23
		
	}; // ???
	bool  NumberIsNull(); // число≈стьЌоль
	string AddSign(); // добавить«нак
	string AddPNumber(int a); //добавить–-ичную цифру
	string AddNull(); // добавитьЌоль
	string BackSpace(); // забой—имвола
	string Clear(); // ќчистить
	TEditor(string Cr = Nu); // конструтор
	string GetStore(); // читать—трока¬формате—троки
	void SetStore(string a); //писать—трока¬формате—троки
	string Edit(int a); // –едактировать
	string AddDot();
	
};
string toString(int a) { // ???  some shit  how fix?
	string str = to_string(a);
	return str;
}



