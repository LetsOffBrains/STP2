#pragma once
#include <string>
#include <regex>

#include "abstracteditor.h"

using namespace std;

string const Nu = "0+i*0";
enum EditMode
{
	LEFT,
	RIGHT
};

class CEditor : public AbstractEditor
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

	bool isNull();
	string AddSign();
	string AddNumber(int a);
	string AddNull();
	string BackSpace();
	string Clear();
	void setStore(string a);
	string getStore();
	string Edit(int a);

	string AddDot();
	void SetMode(EditMode m);
	void SwitchMode();
};

