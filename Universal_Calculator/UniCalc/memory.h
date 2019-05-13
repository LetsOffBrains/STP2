#ifndef MEMORY_H
#define MEMORY_H

#include "Numbers/abstractnumber.h"

class Memory
{
public:
	AbstractNumber *value;
	bool Enabled;

	void Store(AbstractNumber* v);
	void Add(AbstractNumber* v);
	void Clear();
	AbstractNumber* Get();

	string toString();

	Memory();
	~Memory();
};

#endif // MEMORY_H
