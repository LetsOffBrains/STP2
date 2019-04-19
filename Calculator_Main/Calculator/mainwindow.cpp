#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	Operation = Nothing;
	lastWasResult = false;
	saveFormat = true;
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pb0_clicked()
{
	Editor.Edit(0);
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pb1_clicked()
{
	Editor.Edit(1);
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pb2_clicked()
{
	Editor.Edit(2);
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pb3_clicked()
{
	Editor.Edit(3);
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pb4_clicked()
{
	Editor.Edit(4);
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pb5_clicked()
{
	Editor.Edit(5);
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pb6_clicked()
{
	Editor.Edit(6);
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pb7_clicked()
{
	Editor.Edit(7);
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pb8_clicked()
{
	Editor.Edit(8);
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pb9_clicked()
{
	Editor.Edit(9);
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pbAddSign_clicked()
{
	Editor.Edit(CEditor::Sign);
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pbDot_clicked()
{
	Editor.Edit(CEditor::Dot);
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pbMode_clicked()
{
	Editor.SwitchMode();
	if(Editor.mode == LEFT){
		ui->lLeft->setEnabled(true);
		ui->lRight->setEnabled(false);
	}
	else{
		ui->lLeft->setEnabled(false);
		ui->lRight->setEnabled(true);
	}
}

void MainWindow::on_pbBackspace_clicked()
{
	Editor.Edit(CEditor::Erase);
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pbCleanEntry_clicked()
{
	Editor.Edit(CEditor::RemoveAll);
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pbClear_clicked()
{
	Editor.Edit(CEditor::RemoveAll);
	ui->leNumber->setText(Editor.getStore().c_str());
	left.setNull();
	right.setNull();
	Operation = Nothing;
	memory.setNull();
	ui->lMem->setText("( )");
}

void MainWindow::do_Operation(Operations newOp)
{
	bool wasNull = false;

	qDebug() << "Before \t{ Left:" << left.toString().c_str() << "; Right: " << right.toString().c_str() << " }" << (lastWasResult ? "lwr = true" : "lwr = false");

	if(newOp != Sqrt && newOp != Rev){
		if(Operation == Nothing || (lastWasResult && newOp != Result)){
			if(Operation == Nothing){
				Complex tmp(Editor.getStore());
				left = tmp;
			}
			Operation = newOp;
			lastWasResult = false;
			Editor.Clear();
			Editor.SetMode(LEFT);
			ui->lLeft->setEnabled(true);
			ui->lRight->setEnabled(false);
			qDebug() << "Early \t{ Left:" << left.toString().c_str() << "; Right: " << right.toString().c_str() << " }" << (lastWasResult ? "lwr = true" : "lwr = false");
			return;
		}
	}

	if(newOp != Result){
		Operation = newOp;
		lastWasResult = false;
	}

	if(!Editor.IsNull()){
		qDebug() << "Editor is not Null, right = Editor.getStore";
		Complex tmp(Editor.getStore());
		right = tmp;
		qDebug() << "right = " << right.toString().c_str();
	}
	else
		qDebug() << "Editor is Null: " << Editor.getStore().c_str();

	if(right.isNull()){
		qDebug() << "right is null, making right = left";
		right = left;
		wasNull = true;
	}

	QString str("(");
	str += left.toString().c_str();

	switch(Operation){
	case Plus:{
		str += ") + (";
		str += right.toString().c_str();
		left = left + right;
	}break;
	case Minus:{
		str += ") - (";
		str += right.toString().c_str();
		left = left - right;
	}break;
	case Mul:{
		str += ") * (";
		str += right.toString().c_str();
		left = left * right;
	}break;
	case Div:{
		str += ") / (";
		str += right.toString().c_str();
		left = left / right;
	}break;
	case Sqrt:{
		str = "Sqrt(" + str;
		left = left.csqrt(2, 1);
	}break;
	case Rev:{
		str = "Rev(" + str;
		left = left.reverse();
	}break;
	default:{
		qDebug() << "No operation";
	}break;
	}

	if(newOp == Result)
		lastWasResult = true;

	str += ") = ";
	str += left.toString().c_str();

	history.addItem(str);
	qDebug() << str;

	if(wasNull){
		right.setNull();
	}

	Editor.Clear();
	Editor.SetMode(LEFT);
	ui->lLeft->setEnabled(true);
	ui->lRight->setEnabled(false);

	qDebug() << "After \t{ Left:" << left.toString().c_str() << "; Right: " << right.toString().c_str() << " }" << (lastWasResult ? "lwr = true" : "lwr = false");

	if(saveFormat){
		ui->leNumber->setText(left.toString().c_str());
	}
	else{
		if(left.IsReal()){
			ui->leNumber->setText(left.getReString().c_str());
		}
		else{
			ui->leNumber->setText(left.toString().c_str());
		}
	}
}

void MainWindow::on_pbPlus_clicked()
{
	do_Operation(Plus);
}

void MainWindow::on_pMinus_clicked()
{
	do_Operation(Minus);
}

void MainWindow::on_pbMul_clicked()
{
	do_Operation(Mul);
}

void MainWindow::on_pbDiv_clicked()
{
	do_Operation(Div);
}

void MainWindow::on_pbSqrt_clicked()
{
	do_Operation(Sqrt);
}

void MainWindow::on_pbReverse_clicked()
{
	do_Operation(Rev);
}

void MainWindow::on_pbResult_clicked()
{
	do_Operation(Result);
}
// Need to test by hand
void MainWindow::on_leNumber_editingFinished()
{
	Editor.setStore(ui->leNumber->text().toStdString());
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pbMemSave_clicked()
{
	if(!Editor.IsNull()){
		Complex tmp(Editor.getStore());
		memory = tmp;
		ui->lMem->setText("(M)");
		qDebug() << "Memory = " << memory.toString().c_str();
	}
}

void MainWindow::on_pbMemClear_clicked()
{
	memory.setNull();
	ui->lMem->setText("( )");
	qDebug() << "Memory = " << memory.toString().c_str();
}

void MainWindow::on_pbMemPlus_clicked()
{
	memory = memory + left;
	if(!memory.isNull()){
		ui->lMem->setText("(M)");
	}
	qDebug() << "Memory = " << memory.toString().c_str();
}

void MainWindow::on_pbMemResult_clicked()
{
	qDebug() << "Memory = " << memory.toString().c_str();
	Editor.setStore(memory.toString());
	//	ui->leNumber->setText(memory.toString().c_str());
	ui->leNumber->setText(Editor.getStore().c_str());
}

void MainWindow::on_pbPower_clicked()
{
	Complex tmp = left.cpow(ui->sbPow->value());
	ui->leFunct->setText(tmp.toString().c_str());
}

void MainWindow::on_pbRoot_clicked()
{
	Complex tmp = left.csqrt(ui->sbPow->value(), 1);
	ui->leFunct->setText(tmp.toString().c_str());
}

void MainWindow::on_pbModule_clicked()
{
	ui->leFunct->setText(QString::number(left.cmod()));
}

void MainWindow::on_pbDeg_clicked()
{
	ui->leFunct->setText(QString::number(left.cdeg()));
}

void MainWindow::on_pbRad_clicked()
{
	ui->leFunct->setText(QString::number(left.crad()));
}

void MainWindow::on_historyShow_triggered()
{
	history.show();
}

void MainWindow::on_historyClear_triggered()
{
	history.clear();
}

void MainWindow::on_Author_triggered()
{
	QMessageBox::about(this, "Об Авторе",
					   "Красильников Антон\n"
					   "Студент группы ИП-512");
}

void MainWindow::on_saveFormat_toggled(bool arg1)
{
	saveFormat = arg1;
}
