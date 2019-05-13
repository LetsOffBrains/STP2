#pragma once
#include <string>

#include "abstracteditor.h"

using namespace std;
string const Nu = "0/1";

class FEditor : public AbstractEditor
{
private:

	string FEdit;
	string const separator = "/";

public:

	enum
	{
		Sign = 100,
		Erase,
		RemoveAll,
		Separator
	};

	FEditor(string Cr = Nu);
	~FEditor();

	bool isNull();
	string AddSign();
	string AddNumber(int a);
	string AddNull();
	string Backspace();
	string Clear();
	void SetStore(string a);
	string GetStore();
	string Edit(int a);

	string AddSeparator();
};
string toString(int a) { 
	string str = to_string(a);
	return str;
}



