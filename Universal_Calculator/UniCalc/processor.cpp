#include "processor.h"

template<class C>
Processor<C>::Processor()
{
	Lop_Res = L->copy();
	Rop = R->copy();
	Operation = None;
	Error = "";
}

template<class C>
Processor<C>::~Processor()
{
	delete L;
	delete R;
}

template<class C>
void Processor<C>::reset()
{
	Lop_Res = C();
	Rop = C();
	Operation = None;
	Error = "";
}

template<class C>
void Processor<C>::OptnClear()
{
	Operation = None;
}

template<class C>
void Processor<C>::OptnRun()
{
	switch (Operation)
	{
	case Add: {
		Lop_Res = Lop_Res + Rop;
		break;
	}
	case Sub: {
		Lop_Res = Lop_Res - Rop;
		break;
	}
	case Mul: {
		Lop_Res = Lop_Res * Rop;
		break;
	}
	case Dvd: {
		Lop_Res = Lop_Res / Rop;
		break;
	}
	default:
		Error = "Unknown operation";
		break;
	}
}

template<class C>
void Processor<C>::FuncRun()
{
	switch (Operation)
	{
	case Rev: {
		Rop = Rop.reverse();
		break;
	}
	case Sqr: {
		Rop = sqrt(Rop);
		break;
	}
	default:
		break;
	}
}

template<class C>
C Processor<C>::getLeft()
{
	return Lop_Res;
}

template<class C>
void Processor<C>::setLeft(C Operand)
{
	Lop_Res = Operand;
}

template<class C>
C Processor<C>::getRight()
{
	return Rop;
}

template<class C>
void Processor<C>::setRight(C Operand)
{
	Rop = Operand;
}

template<class C>
int Processor<C>::getOptn()
{
	return Operation;
}

template<class C>
void Processor<C>::setOptn(Operations Oprtn)
{
	Operation = Oprtn;
}
