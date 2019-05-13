#include "FEditor.h"
#include <regex>
#include <string>

bool FEditor::isNull()
{
	regex fNumreg("-?0/?[1-9]*");
	if (regex_match(FEdit, fNumreg)) {
		return true;
	}
	else {
		return false;
	}
}

string FEditor::AddSign()
{
	if (FEdit[0] == '-') {
		FEdit.erase(0, 1);
	}
	else if(FEdit[0] != '0'){
		FEdit = "-" + FEdit;
	}
	return FEdit;
}

string FEditor::AddNumber(int a)
{
	if (FEdit.length() == 2) {
		if (FEdit[0] == '-' && FEdit[1] == 0) {
			FEdit.pop_back();
		}
	}
	else if(FEdit.length() == 1 && FEdit[0] == '0'){
		FEdit.pop_back();
	}

	FEdit.append(toString(a));
	return FEdit;
}

string FEditor::AddNull()
{
	return AddNumber(0);
}

string FEditor::Backspace()
{
	if (FEdit.length() > 0) {
		FEdit.pop_back();
	}
	if ((FEdit == "") || (FEdit == "-")) {
		FEdit = Nu;
	}
	return FEdit;
}

string FEditor::Clear()
{
	FEdit = Nu;
	return FEdit;
}

FEditor::FEditor(string Cr)
{
	regex fNumreg("(0|-?[1-9][0-9]*)/[1-9][0-9]*");
	if (regex_match(Cr, fNumreg))
		FEdit = Cr;
}

string FEditor::GetStore()
{
	return FEdit;
}

void FEditor::SetStore(string a)
{
	regex fNumreg("(0|-?[1-9][0-9]*)/[1-9][0-9]*");
	if (regex_match(a, fNumreg))
		FEdit = a;
}

string FEditor::Edit(int a)
{
	string Result;

	if (a == 0) {
		Result = AddNull();
	}
	else if (a > 0 && a < 10) {
		Result = AddNumber(a);
	}
	else{ 
		Result = FEdit;
	}

	switch (a)
	{
	case Sign: //  + or -
		Result = AddSign();
		break;
	case Erase: // backSpace
		Result = Backspace();
		break;
	case RemoveAll:
		Result = Clear();
		break;
	case Separator:
		Result = AddSeparator();
	default:
		break;
	}

	return Result;
}

string FEditor::AddSeparator()
{
	if (FEdit.find('/') == -1) {
		FEdit += "/";
	}
	return FEdit;
}



int main() {

 }
