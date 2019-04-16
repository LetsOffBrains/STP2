#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	pbNumbers[0] = ui->pb0;
	pbNumbers[1] = ui->pb1;
	pbNumbers[2] = ui->pb2;
	pbNumbers[3] = ui->pb3;
	pbNumbers[4] = ui->pb4;
	pbNumbers[5] = ui->pb5;
	pbNumbers[6] = ui->pb6;
	pbNumbers[7] = ui->pb7;
	pbNumbers[8] = ui->pb8;
	pbNumbers[9] = ui->pb9;
	pbNumbers[10] = ui->pbA;
	pbNumbers[11] = ui->pbB;
	pbNumbers[12] = ui->pbC;
	pbNumbers[13] = ui->pbD;
	pbNumbers[14] = ui->pbE;
	pbNumbers[15] = ui->pbF;


}

MainWindow::~MainWindow()
{
	delete ui;
}

int MainWindow::char_to_int(char c)
{
	if((c >= 'a' && c <= 'f')){
		return c - 'a' + A;
	}
	else if(c >= 'A' && c <='F'){
		return c - 'A' + A;
	}
	else if(c >= '0' && c <='9'){
		return c - '0';
	}
	else if(c == '.') return Dot;
	else return -1;
}

void MainWindow::on_sbFrom_valueChanged(int arg1)
{
	for(int i = 0; i < 16; ++i){
		pbNumbers[i]->setEnabled( (i < arg1) ? true : false );
	}
	check_leFrom();
}

void MainWindow::on_leFrom_textEdited()
{
	check_leFrom();
//	PEditor.SetStore(ui->leFrom->text().toStdString());
}

void MainWindow::check_leFrom()
{
	QString text = ui->leFrom->text().toUpper();
	int i = 0, to = ui->sbFrom->value();
	bool hasDot = false;
	while (i < text.size()){
		int num = char_to_int(text[i].toLatin1());
		if(num >= 0 && num < to){
			++i;
		}
		else if(num == Dot){
			if(hasDot){
				text.remove(i, 1);
			}
			else{
				hasDot = true;
				++i;
			}
		}
		else{
			text.remove(i, 1);
		}
	}
	ui->leFrom->setText(text);
	PEditor.SetStore(ui->leFrom->text().toStdString());
}

void MainWindow::on_pb0_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + '0');
	if(ui->sbFrom->value() >= 0){
		PEditor.Edit(0);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}
void MainWindow::on_pb1_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + '1');
	if(ui->sbFrom->value() >= 1){
		PEditor.Edit(1);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}
void MainWindow::on_pb2_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + '2');
	if(ui->sbFrom->value() >= 2){
		PEditor.Edit(2);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}
void MainWindow::on_pb3_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + '3');
	if(ui->sbFrom->value() >= 3){
		PEditor.Edit(3);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}
void MainWindow::on_pb4_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + '4');
	if(ui->sbFrom->value() >= 4){
		PEditor.Edit(4);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}
void MainWindow::on_pb5_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + '5');
	if(ui->sbFrom->value() >= 5){
		PEditor.Edit(5);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}
void MainWindow::on_pb6_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + '6');
	if(ui->sbFrom->value() >= 6){
		PEditor.Edit(6);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}
void MainWindow::on_pb7_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + '7');
	if(ui->sbFrom->value() >= 7){
		PEditor.Edit(7);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}
void MainWindow::on_pb8_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + '8');
	if(ui->sbFrom->value() >= 8){
		PEditor.Edit(8);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}
void MainWindow::on_pb9_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + '9');
	if(ui->sbFrom->value() >= 9){
		PEditor.Edit(9);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}
void MainWindow::on_pbA_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + 'A');
	if(ui->sbFrom->value() >= A){
		PEditor.Edit(A);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}
void MainWindow::on_pbB_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + 'B');
	if(ui->sbFrom->value() >= B){
		PEditor.Edit(B);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}
void MainWindow::on_pbC_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + 'C');
	if(ui->sbFrom->value() >= C){
		PEditor.Edit(C);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}
void MainWindow::on_pbD_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + 'D');
	if(ui->sbFrom->value() >= D){
		PEditor.Edit(D);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}
void MainWindow::on_pbE_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + 'E');
	if(ui->sbFrom->value() >= E){
		PEditor.Edit(E);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}
void MainWindow::on_pbF_clicked(){
//	ui->leFrom->setText(ui->leFrom->text() + 'F');
	if(ui->sbFrom->value() >= F){
		PEditor.Edit(F);
		ui->leFrom->setText(PEditor.GetStore().c_str());
	}
}

void MainWindow::on_pbDot_clicked()
{
//	if(!ui->leFrom->text().contains('.'))
//		ui->leFrom->setText(ui->leFrom->text() + '.');
	PEditor.Edit(PEditor.Dot);
	ui->leFrom->setText(PEditor.GetStore().c_str());
}

void MainWindow::on_pbBackspace_clicked()
{
//	QString text = ui->leFrom->text();
//	text.chop(1);
//	ui->leFrom->setText(text);

	PEditor.Edit(PEditor.Erase);
	ui->leFrom->setText(PEditor.GetStore().c_str());
}

void MainWindow::on_pbClear_clicked()
{
//	ui->leFrom->clear();
	PEditor.Edit(PEditor.RemoveAll);
	ui->leFrom->setText(PEditor.GetStore().c_str());
}

void MainWindow::on_pbExec_clicked()
{
	//Massive work ahead
	qDebug() << "Construct: " << PEditor.GetStore().c_str() << " " << ui->sbFrom->value() << " " << 3;
	Pnumber number(PEditor.GetStore(), ui->sbFrom->value(), 3);
	number.setB(ui->sbTo->value());
	ui->leTo->setText(number.getString().c_str());
}

void MainWindow::on_leFrom_returnPressed()
{
	on_pbExec_clicked();
}
