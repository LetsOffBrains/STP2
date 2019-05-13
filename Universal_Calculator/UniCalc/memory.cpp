#include "memory.h"

void Memory::Store(AbstractNumber* v)
{
	value = v->copy();
	Enabled = true;
}

void Memory::Add(AbstractNumber* v)
{
	*value = *value + *v;
	Enabled = true;
}

void Memory::Clear()
{
	Enabled = false;
}

AbstractNumber *Memory::Get()
{
	return value->copy();
}

string Memory::toString()
{
	return value->toString();
}

Memory::Memory()
{

}

Memory::~Memory()
{
	delete value;
}
