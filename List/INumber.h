#pragma once

//интерфейс чисел
class INumber
{
	virtual void print() = 0;
	virtual void read() = 0;
	//virtual bool less(INumber*);
};