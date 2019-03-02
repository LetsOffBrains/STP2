#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include <QDebug>

enum{
	A = 10,
	B = 11,
	C = 12,
	D = 13,
	E = 14,
	F = 15,
	Dot = 16
};

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	int char_to_int(char c);

private slots:
	void on_sbFrom_valueChanged(int arg1);

	void on_leFrom_textEdited();

	void check_leFrom();

	void on_pb0_clicked();
	void on_pb1_clicked();
	void on_pb2_clicked();
	void on_pb3_clicked();
	void on_pb4_clicked();
	void on_pb5_clicked();
	void on_pb6_clicked();
	void on_pb7_clicked();
	void on_pb8_clicked();
	void on_pb9_clicked();
	void on_pbA_clicked();
	void on_pbB_clicked();
	void on_pbC_clicked();
	void on_pbD_clicked();
	void on_pbE_clicked();
	void on_pbF_clicked();

	void on_pbDot_clicked();

	void on_pbBackspace_clicked();

	void on_pbClear_clicked();

private:
	Ui::MainWindow *ui;

	QPushButton* pbNumbers[16];
};

#endif // MAINWINDOW_H
