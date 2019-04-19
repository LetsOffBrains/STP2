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
	char separator = '.';


public:
	EditMode mode = LEFT;
	enum 
	{
		Sign = 100,
		Erase,
		RemoveAll,
		Mode,
		Dot
	};
	
	CEditor(string Cr = Nu);
	~CEditor();
	bool IsNull();
	string AddSign();
	string AddComplexNumber(int a);
	string AddNull();
	string AddDot();
	string BackSpace();
	string Clear();
	void setStore(string a);
	string getStore();
	string Edit(int a);
	void SetMode(EditMode m);
	void SwitchMode();
};

