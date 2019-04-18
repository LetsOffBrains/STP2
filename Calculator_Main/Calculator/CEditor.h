#pragma once
#include <string>
#include <regex>

using namespace std;
string const Nu = "0+i*0";

enum EditMode
{
	LEFT,
	RIGHT
};
class CEditor
{
private:
	string CEdit;
	EditMode mode = LEFT;
	string separator = ".";

public:
	enum 
	{
		Sign = 100,
		Erase,
		RemoveAll,
		Mode
		
	};
	
	CEditor(string Cr = Nu);
	~CEditor();
	bool IsNull();
	string AddSign();
	string AddComplexNumber(int a);
	string AddNull();
	string BackSpace();
	string Clear();
	void setStore(string a);
	string getStore();
	string Edit(int a);
	void SetMode(EditMode m);
};
string toString(int a) {
	string str = to_string(a);
	return str;
}

