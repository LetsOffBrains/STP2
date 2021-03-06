//#include <iostream>
#include "PEditor.h"

using namespace std;

bool TEditor::NumberIsNull()
{
	regex pNumreg("-?0,?0*");
	if (regex_match(CEdit, pNumreg)){
		return true;
	}
	else {
		return false;
	}
}

string TEditor::AddSign()
{

	if (CEdit[0] == '-') {
		CEdit.erase(CEdit.find('-'), 1);
	}
	else {
		CEdit = "-" + CEdit;
	}
	return CEdit; // ???
}



string  TEditor::AddPNumber(int a)
{
	string d;
	
	if (CEdit == "0") {
		CEdit = "";
	}
	switch (a)
	{
	case 0: case 1: case 2: case 3: 
	case 4: case 5: case 6: 
	case 7: case 8: case 9:
		char ch[2];
		ch[0] = '0' + a;
		ch[1] = '\0';
		d = string(ch);
		break;
	case 10:
		d = "A";
		break;
	case 11:
		d = "B";
		break;
	case 12:
		d = "C";
		break;
	case 13:
		d = "D";
		break;
	case 14:
		d = "E";
		break;
	case 15:
		d = "F";
		break;

	default:
		//cout << "РџРµСЂРµРґР°РЅ РЅРµРІРµСЂРЅС‹Р№ С‡РёСЃР»РѕРІРѕР№ РєРѕРґ" << toSString(a) << " СЃС‚СЂРѕРєР° РЅРµ РёР·РјРµРЅРёР»Р°СЃСЊ" << endl;
		d = "";
		break;
	}
	//CEdit.insert(CEdit.length(), d);
	CEdit.append(d);
	return CEdit;

}

string TEditor::AddNull()
{
	return AddPNumber(0);
}
string TEditor::BackSpace()
{
	int n;
	n = CEdit.length();
	CEdit.erase(n - 1, 1);//CEdit.erase(CEdit.length(), 2);
	if ((CEdit == "") || (CEdit == "-")) { // work
		CEdit = Nu;
	}
	
	return CEdit;
}
string TEditor::Clear()
{
	CEdit = Nu;
	return CEdit;

}

TEditor::TEditor(string Cr)
{
	regex pNumreg("-?(0|[1-9A-F][0-9A-F]*)" + separator + "?[0-9A-F]*");
	if (regex_match(Cr, pNumreg))
	CEdit = Cr;
}
string TEditor::GetStore() {
	return CEdit;
}
void TEditor::SetStore(string a) {
	regex pNumreg("-?(0|[1-9A-F][0-9A-F]*)" + separator + "?[0-9A-F]*");
	if (regex_match(a, pNumreg))
	CEdit = a;
}

string TEditor::Edit(int a)
{
	string Result;
	switch (a) {
	case 0:
		Result = AddNull();
		break;
	case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:
	case 9:case 10:case 11:case 12:case 13:case 14:case 15: // some shit again
		Result = AddPNumber(a);
		break;
	case Sign: // + or -
		Result = AddSign();
		break;
	case Erase: // backSpace
		Result = BackSpace();
		break;
	case RemoveAll: //clear
		Result = Clear();
		break;
	case Dot: //Dot
		Result = AddDot();
		break;
	default:
//		cout << "Р—Р°РґР°РЅР° РЅРµ РєРѕСЂСЂРµРєС‚РЅР°СЏ РєРѕРјР°РЅРґР°" << endl;
		Result = CEdit;
		break;

	}
	return Result;

}

string TEditor::AddDot()
{
	if (CEdit.find(separator) == -1) {
		CEdit += separator;
	}
	return CEdit;
}

string TEditor::convert(int from, int to)
{
	Pnumber num(CEdit, from, 3);
	num.setB(to);
	return num.getString();
}









