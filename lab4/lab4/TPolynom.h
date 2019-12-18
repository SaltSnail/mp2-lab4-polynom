#pragma once
#include <iostream>
using namespace std;

struct TMonom
{
	int Coeff;
	int Power;
	TMonom* pNext;

	TMonom() :Coeff(0), Power(0), pNext(0){}
	TMonom(int coeff, int power);
	TMonom(int coeff, int power, TMonom* pnext);
	TMonom(const TMonom& tm);

	TMonom& operator=(const TMonom& tm)
	{
		Coeff = tm.Coeff;
		Power = tm.Power;
		return *this;
	}

	int operator==(const TMonom& tm)
	{ 
		return (Coeff == tm.Coeff) && (Power == tm.Power);
	}

	int operator<(const TMonom& tm)
	{
		return Power < tm.Power;
	}
};

class TPolynom
{
protected:
	TMonom* pHead;
	int ListLen;
public:
	TPolynom();
	TPolynom(const TPolynom& tp);
	~TPolynom();

	int GetListLength() const { return ListLen; } // к-во звеньев
	void ClearList(void); // очистить список
	void Insert(TMonom tm);
	void Insert(double coeff, int power);
	void Add(const TPolynom tp);
	void InsFirst(TMonom tm);
	void DelFirst();
	void InsLast(TMonom tm);
	void DelList(TMonom tm);
	int IsInList(int power);
	int Calculate(int val);

	TPolynom operator+(const TPolynom& q) const;
	TPolynom operator-(TPolynom& q);
	TPolynom operator*(const TPolynom& q);
	TPolynom operator*(const double& q) const;
	const TPolynom& operator = (const TPolynom& q);

	friend ostream& operator << (ostream& os, const TPolynom& object);
};

