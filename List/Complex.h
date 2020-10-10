#pragma once
#include "Inumber.h"

//����� ����������� �����
template<typename T>
class Complex : public INumber
{
public:
	Complex(T real, T im);
	virtual void print() override;
	virtual void read() override;
	
private:
	T real;
	T im;
};