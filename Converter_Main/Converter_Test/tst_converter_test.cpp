#include <QtTest>
#include <QCoreApplication>
#include "../Converter/PEditor.h"
#include "../Converter/Pnumber.h"
#include <string>

// add necessary includes here
using namespace std;

Q_DECLARE_METATYPE(string);
class Converter_Test : public QObject
{
	Q_OBJECT

public:
	Converter_Test();
	~Converter_Test();

private slots:
	void getString_data();
	void getString();

	void convert_data();
	void convert();
};

Converter_Test::Converter_Test()
{

}

Converter_Test::~Converter_Test()
{

}

void Converter_Test::getString_data()
{
	QTest::addColumn<double>("num");
	QTest::addColumn<int>("base");
	QTest::addColumn<string>("result");
	QTest::newRow("getString_test1") << 6.0 << 2 << string("110");
	QTest::newRow("getString_test2") << 12.2 << 8 << string("14.146");
	QTest::newRow("getString_test3") << 7.8 << 10 << string("7.799");
	QTest::newRow("getString_test4") << 3.5 << 16 << string("3.8");
}

void Converter_Test::getString()
{
	QFETCH(double, num);
	QFETCH(int, base);
	QFETCH(string, result);
	Pnumber p(num, base, 3);
	QCOMPARE(p.getString(),result);
}

void Converter_Test::convert_data()
{
	QTest::addColumn<string>("strFrom");
	QTest::addColumn<int>("baseFrom");
	QTest::addColumn<int>("baseTo");
	QTest::addColumn<string>("strTo");
	QTest::newRow("convert_test1") << string("154.255") << 10 << 2 << string("10011010.010");
	QTest::newRow("convert_test2") << string("10011010.010") << 2 << 8<< string("232.2");
	QTest::newRow("convert_test3") << string("232.2") << 8 << 16 << string("9A.4");
	QTest::newRow("convert_test4") << string("9A.4") << 16 << 10 << string("154.249");
}

void Converter_Test::convert()
{
	QFETCH(string, strFrom);
	QFETCH(int, baseFrom);
	QFETCH(int, baseTo);
	QFETCH(string, strTo);
	Pnumber p(strFrom,baseFrom, 3);
	p.setB(baseTo);
	QCOMPARE(p.getString(),strTo);
}

QTEST_MAIN(Converter_Test)

#include "tst_converter_test.moc"
