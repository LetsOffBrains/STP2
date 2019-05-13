#ifndef ABSTRACTEDITOR_H
#define ABSTRACTEDITOR_H

#include "string"

using namespace std;

class AbstractEditor
{
public:
	virtual ~AbstractEditor() = 0;

	virtual bool  isNull() = 0;
	virtual string AddSign() = 0;
	virtual string AddNumber(int a) = 0;
	virtual string AddNull() = 0;
	virtual string BackSpace() = 0;
	virtual string Clear() = 0;
	virtual void SetStore(string a) = 0;
	virtual string GetStore() = 0;
	virtual string Edit(int a) = 0;
};

#endif // ABSTRACTEDITOR_H
