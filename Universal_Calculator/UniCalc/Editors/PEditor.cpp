#include "PEditor.h"

using namespace std;

bool PEditor::isNull()
{
	regex pNumreg("-?0,?0*");
	if (regex_match(CEdit, pNumreg)){
		return true;
	}
	else {
		return false;
	}
}

string PEditor::AddSign()
{

	if (CEdit[0] == '-') {
		CEdit.erase(CEdit.find('-'), 1);
	}
	else {
		CEdit = "-" + CEdit;
	}
	return CEdit; // ???
}



string  PEditor::AddNumber(int a)
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

string PEditor::AddNull()
{
	return AddNumber(0);
}
string PEditor::BackSpace()
{
	int n;
	n = CEdit.length();
	CEdit.erase(n - 1, 1);//CEdit.erase(CEdit.length(), 2);
	if ((CEdit == "") || (CEdit == "-")) { // work
		CEdit = Nu;
	}
	
	return CEdit;
}
string PEditor::Clear()
{
	CEdit = Nu;
	return CEdit;

}

PEditor::PEditor(string Cr)
{
	regex pNumreg("-?(0|[1-9A-F][0-9A-F]*)" + separator + "?[0-9A-F]*");
	if (regex_match(Cr, pNumreg))
	CEdit = Cr;
}
string PEditor::GetStore() {
	return CEdit;
}
void PEditor::SetStore(string a) {
	regex pNumreg("-?(0|[1-9A-F][0-9A-F]*)" + separator + "?[0-9A-F]*");
	if (regex_match(a, pNumreg))
	CEdit = a;
}

string PEditor::Edit(int a)
{
	string Result;
	switch (a) {
	case 0:
		Result = AddNull();
		break;
	case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:
	case 9:case 10:case 11:case 12:case 13:case 14:case 15: // some shit again
		Result = AddNumber(a);
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

string PEditor::AddDot()
{
	if (CEdit.find(separator) == string::npos) {
		CEdit += separator;
	}
	return CEdit;
}









