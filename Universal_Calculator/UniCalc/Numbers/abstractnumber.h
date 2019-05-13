#ifndef ABSTRACTNUMBER_H
#define ABSTRACTNUMBER_H

#include "string"

using namespace std;

class AbstractNumber
{
public:
	virtual ~AbstractNumber() = 0;

	virtual AbstractNumber* copy() = 0;

	virtual void Add (AbstractNumber *Other) = 0;
	virtual void Mul (AbstractNumber *Other) = 0;
	virtual void Minus (AbstractNumber *Other) = 0;
	virtual void Div (AbstractNumber *Other) = 0;

//	virtual AbstractNumber& operator + (const AbstractNumber &Other) = 0;
//	virtual AbstractNumber& operator * (const AbstractNumber &Other) = 0;
//	virtual AbstractNumber& operator - (const AbstractNumber &Other) = 0;
//	virtual AbstractNumber& operator / (const AbstractNumber &Other) = 0;

	virtual AbstractNumber& square() = 0;

	virtual AbstractNumber& reverse() = 0;

	virtual AbstractNumber& operator - () = 0;

	virtual bool operator == (const AbstractNumber &Other);

	virtual string toString() = 0;

	virtual bool isNull() = 0;
};

#endif // ABSTRACTNUMBER_H
