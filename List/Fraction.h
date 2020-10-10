#pragma once
#include"INumber.h"

//класс дробных
template<typename T>
class Fraction : public INumber
{
public:
	Fraction(T numerator, T denominator);
	virtual void print() override;
	virtual void read() override;

private:
	T numerator;
	T denominator;
};