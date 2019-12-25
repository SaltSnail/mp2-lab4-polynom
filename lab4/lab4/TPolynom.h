#pragma once
#include <iostream>
using namespace std;

struct TMonom
{
	double Coeff;
	int Power;
	TMonom* pNext;

	TMonom() :Coeff(0), Power(0), pNext(nullptr){}
	TMonom(double coeff, int power);
	TMonom(double coeff, int power, TMonom* pnext);
	TMonom(const TMonom& tm);

	TMonom& operator=(const TMonom& tm)
	{
		Coeff = tm.Coeff;
		Power = tm.Power;
		return *this;
	}

	int operator==(const TMonom& tm)
	{ 
		if (Power == tm.Power && abs(Coeff - tm.Coeff) < 0.000001) 
			return true;
		else return false;
	}

	int operator<(const TMonom& tm)
	{
		return Power < tm.Power;
	}
};

class TPolynom
{
protected:
	TMonom* pHead; // заголовок
	int ListLen; // длинна списка
public:
	TPolynom(); // конструктор
	TPolynom(const TPolynom& tp); // конструктор копирования
	~TPolynom(); // деструктор

	int GetListLength() const { return ListLen; } // к-во звеньев
	void ClearList(void); // очистить список
	void Insert(TMonom tm); // вставка в список
	void Insert(double coeff, int power);
	void Add(const TPolynom tp); // добавление монома к другому
	void InsFirst(TMonom tm); // вставка в начало
	void DelFirst(); //удаление первого элемента
	void InsLast(TMonom tm); // вставка в конец
	void DelList(TMonom tm); // удаление списка
	int IsInList(int power); // проверка на наличие в списке
	int Calculate(int val); // вычисление

	TPolynom operator+(const TPolynom& q) const; // сложение
	TPolynom operator-(TPolynom& q); // вычитание
	TPolynom operator*(const TPolynom& q); // умножение
	TPolynom operator*(const double& q) const; 
	const TPolynom& operator = (const TPolynom& q); // присваивание

	friend ostream& operator << (ostream& os, const TPolynom& object); 
};

