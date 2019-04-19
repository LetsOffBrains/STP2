#include "CEditor.h"

CEditor::CEditor(string Cr)
{
	setStore(Cr);
}

CEditor::~CEditor()
{
}

bool CEditor::IsNull()
{
	regex cNumbereg("0(.0*)?\\+i\\*0(.0*)?");
	if (regex_match(CEdit, cNumbereg) || CEdit == Nu) {
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
		size_t n = CEdit.find('i');
		string str = CEdit.substr(n + 2);
		if (str[0] == '-') {
			CEdit.erase(n + 2, 1);
			return CEdit;
		}
		if (str[0] != '0') {
			CEdit.insert(n + 2, 1, '-');
			return CEdit;
		}
		if(str.length() > 1){
			if(str[0] == '0' && str[1] != '.'){
				return CEdit;
			}
			if(str[0] == '0' && str[1] == '.'){
				CEdit.insert(n + 2, 1, '-');
				return CEdit;
			}
		}
	}
	return CEdit;
}

string CEditor::AddComplexNumber(int a)
{
	if (mode == LEFT) {
		if ( CEdit[0] == '0' && CEdit[1] != separator) {
			CEdit.erase(0, 1);
			CEdit = (char)('0' + a) + CEdit;
		}
		else {
			size_t n = CEdit.find('i');
			CEdit.insert(n - 1, 1, '0' + a);
		}
	}
	else {
		string d;
		size_t n = CEdit.find('i');
		if (CEdit[n + 2] == '0' && CEdit[n + 3] != separator) {
			CEdit.pop_back();
			CEdit.push_back('0' + a);
		}
		else {
			CEdit.push_back('0' + a);
		}
	}
	return CEdit;
}

string CEditor::AddNull()
{
	return AddComplexNumber(0);
}

string CEditor::AddDot()
{
	size_t n = CEdit.find('i');
	string str;
	if (mode == LEFT) {
		str = CEdit.substr(0, n - 1);
		if(str.find(separator) == string::npos){
			CEdit.insert(n - 1, 1, separator);
		}
	}
	else {
		str = CEdit.substr(n + 2);
		if(str.find(separator) == string::npos){
			CEdit.push_back(separator);
		}
	}
	return CEdit;
}

string CEditor::BackSpace()
{
	size_t n = CEdit.find('i');
	if (mode == LEFT) {
		CEdit.erase(n - 2, 1);
		if(CEdit[0] == '+' ){
			CEdit.insert(0, 1, '0');
		}
		else if(CEdit[0] == '-' ){
			CEdit[0] = '0';
		}
	}
	else {
		CEdit.pop_back();
		if(CEdit.length() <= n + 2){
			CEdit.append("0");
		}
		else if(CEdit.length() <= n + 3 && CEdit[n + 2] == '-'){
			CEdit[n + 2] = '0';
		}
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
	regex cNumbereg("(0|-?[1-9][0-9]*(.[0-9]*[1-9])?)\\+i\\*(0|-?[1-9][0-9]*(.[0-9]*[1-9])?)");
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
	case Dot:
		Result = AddDot();
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

void CEditor::SwitchMode()
{
	if(mode == LEFT)
		mode = RIGHT;
	else
		mode = LEFT;
}
