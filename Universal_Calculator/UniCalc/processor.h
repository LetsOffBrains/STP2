#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "Numbers/abstractnumber.h"

template<class C>
class Processor
{
public:
	enum Operations{
		None = 0,
		Add = 1,
		Sub = 2,
		Mul = 3,
		Dvd = 4,
		Rev = 5,
		Sqr = 6
	};

	AbstractNumber *L, *R;
	C Lop_Res, Rop;
	Operations Operation;
	string Error;

	Processor<C>();
	~Processor<C>();

	/*Сброс процессора.
	Поля объекта процессор: Lop_Res, Rop
	инициализируются объектами (тип T) со
	значениями по умолчанию. Например, для
	простых дробей - 0/1. Процессор
	устанавливается в состояние: «операция не
	установлена»: (Operation = None).*/
	void reset();

	/*Сброс операции.
	Процессор устанавливается в состояние:
	«операция не установлена»: (Operation = None).*/
	void OptnClear();

	/*Выполнить операцию.
	Вызывает выполнение текущей операции
	(записанной в поле Operation). Операция
	(Operation) выполняется над значениями,
	хранящимися в полях Rop и Lop_Res.
	Результат сохраняется в поле Lop_Res.
	Если Operation = None, никакие действия
	не выполняются. Состояние объекта не
	изменяется.*/
	void OptnRun();

	/*Вычислить функцию.
	Вызывает выполнение текущей функции
	(Func). Функция (Func) выполняется над
	значением, хранящимся в поле Rop.
	Результат сохраняется в нём же. Состояние
	объекта не изменяется.*/
	void FuncRun();

	/*Читать левый операнд.
	Создаёт и возвращает копию объекта,
	который хранится в поле Lop_Res.*/
	C getLeft();

	/*Записать левый операнд.
	Создаёт копию объекта Operand и заносит
	её в поле Lop_Res.*/
	void setLeft(C Operand);

	/*Читать правый операнд.
	Создаёт и возвращает копию объекта,
	который хранится в Rop.*/
	C getRight();

	/*Записать правый операнд.
	Создаёт копию объекта Operand и заносит
	её в поле Rop.*/
	void setRight(C Operand);

	/*Читать состояние.
	Копирует и возвращает значение поля
	Operation.*/
	int getOptn();

	/*Записать состояние.
	Заносит значение Oprtn в поле Operation.*/
	void setOptn(Operations Oprtn);

};

#endif // PROCESSOR_H
