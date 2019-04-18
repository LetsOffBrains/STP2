#include "CEditor.h"
#include <regex>


CEditor::CEditor(string Cr)
{
	setStore(Cr);
}

CEditor::~CEditor()
{
}

bool CEditor::IsNull()
{
	regex cNumbereg("0[+,-]i\\*0");
	if (regex_match(CEdit, cNumbereg)) {
		return true;
	}
	else {
		return false;
	}
}

string CEditor::AddSign()
{
	if (mode == LEFT) {
		if (CEdit[0] == '-') {
			CEdit.erase(0, 1);
		}
		else if (CEdit[0] != '0') {
			CEdit = "-" + CEdit;
		}
	}
	else {
		int n = CEdit.find('i');
		if (CEdit[n - 1] == '-') {
			CEdit[n - 1] = '+';
		}
		else {
			CEdit[n - 1] = '-';
		}
	}
	return CEdit;
}

string CEditor::AddComplexNumber(int a)
{
	if (mode == LEFT) {
		if ( CEdit[0] == '0' && CEdit[1] != ',') {
			CEdit.erase(0,1);
			CEdit = toString(a) + CEdit;
		}
		else {
			int n = CEdit.find('i');
			CEdit.insert(n - 1, toString(a));
		}
	}
	else {
		string d;
		int n = CEdit.find('i');
		if (CEdit[n + 2] == '0') {
			CEdit.pop_back();
			CEdit.append(toString(a));
		}
		else {
			d = toString(a);
			CEdit.append(d);
		}
	}
	return CEdit;
}

string CEditor::AddNull()
{
	return AddComplexNumber(0);
}

string CEditor::BackSpace()
{
	if (mode == LEFT) {
		int n = CEdit.find('i');
		CEdit.erase(n - 2, 1);
	}
	else {
		CEdit.pop_back();
	}
	return CEdit;
}

string CEditor::Clear()
{
	CEdit = Nu;
	return CEdit;
}

void CEditor::setStore(string a)
{
	regex cNumbereg("(0|-?[1-9][0-9]*)[+,-]i\\*(0|[1-9][0-9]*)");
	if (regex_match(a, cNumbereg)) {
		CEdit = a;
	}
	else {
		CEdit = Nu;
	}
}

string CEditor::getStore()
{
	return CEdit;
}

string CEditor::Edit(int a)
{
	string Result;
	if (a == 0) {
		Result = AddNull();
	}
	else if (a > 0 && a < 10) {
		Result = AddComplexNumber(a);
	}
	else {
		Result = CEdit;
	}
	switch (a)
	{
	case Sign:
		Result = AddSign();
		break;
	case Erase:
		Result = BackSpace();
		break;
	case RemoveAll:
		Result = Clear();
		break;
	default:
		break;
	}
	return Result;
}

void CEditor::SetMode(EditMode m)
{
	mode = m;
}
