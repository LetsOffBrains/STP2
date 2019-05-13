#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <regex>

#include "abstracteditor.h"

using namespace std;

string const Nu = "0";

class PEditor : public AbstractEditor
{
private:
	string CEdit; // строка
	string const separator = ".";
	

public:
	enum
	{
		Sign = 20,
		Erase = 21,
		RemoveAll = 22,
		Dot = 23
		
	};

	PEditor(string Cr = Nu);
	~PEditor();

	bool  isNull();
	string AddSign();
	string AddNumber(int a);
	string AddNull();
	string BackSpace();
	string Clear();
	void SetStore(string a);
	string GetStore();
	string Edit(int a);

	string AddDot();
};



