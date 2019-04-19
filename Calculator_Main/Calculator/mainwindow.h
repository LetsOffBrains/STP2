#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QMessageBox>

#include <QDebug>

#include "CEditor.h"
#include "complex.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	enum Operations
	{
		Nothing,
		Plus,
		Minus,
		Mul,
		Div,
		Sqrt,
		Rev,
		Result
	};

private slots:
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

	void on_pbAddSign_clicked();

	void on_pbDot_clicked();

	void on_pbMode_clicked();

	void on_pbBackspace_clicked();

	void on_pbCleanEntry_clicked();

	void on_pbClear_clicked();

	void do_Operation(Operations newOp);

	void on_pbPlus_clicked();

	void on_pMinus_clicked();

	void on_pbMul_clicked();

	void on_pbDiv_clicked();

	void on_pbSqrt_clicked();

	void on_pbReverse_clicked();

	void on_pbResult_clicked();

	void on_leNumber_editingFinished();

	void on_pbMemSave_clicked();

	void on_pbMemClear_clicked();

	void on_pbMemPlus_clicked();

	void on_pbMemResult_clicked();

	void on_pbPower_clicked();

	void on_pbRoot_clicked();

	void on_pbModule_clicked();

	void on_pbDeg_clicked();

	void on_pbRad_clicked();

	void on_historyShow_triggered();

	void on_historyClear_triggered();

	void on_Author_triggered();

	void on_saveFormat_toggled(bool arg1);

private:
	Ui::MainWindow *ui;

	CEditor Editor;

	Complex memory, left, right;
	Operations Operation;
	bool lastWasResult, saveFormat;

	QListWidget history;
};

#endif // MAINWINDOW_H
