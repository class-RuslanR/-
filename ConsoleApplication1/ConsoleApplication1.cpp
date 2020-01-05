#include "pch.h"
#include <iostream>

using namespace std;

class A
{
protected:
	int count, b[5];
public:
	virtual void Set(int mass[])
	{
		for (int i = 0; i < 5; i++)
		{
			b[i] = mass[i];
		}
	}
	void print()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << b[i] << endl;
		}
	}
};

class A_int_ch : public A
{
public:
	void Set(int mass[])
	{
		count = 0;
		for  ( int i = 0; i< 5; i ++)
		{
			if (mass[i] % 2 == 0)
			{
				b[count] = mass[i];
				count++;
			}
			else 
			{
				b[count] = 0;
				count++;
			}
		}
	}
	void printCh()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << b[count] << endl;
		}
	}
};

class A_int_nch : public A
{
public:
	void Set(int mass[])
	{
		count = 0;
		for (int i = 0; i < 5; i ++)
		{
			if (mass[i] % 2 != 0)
			{
				b[count] = mass[i];
				count++;
			}

			else 
			{
				b[count] = 0;
				count++;
			}
		}
	}
	void printNch()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << b[count] << endl;
		}
	}
};

int main()
{
	A objA;
	int mass[5] = { 1,2,3,4,5 };
	//objA.Set(mass);
	//objA.print();

	A *pr = &objA;
	A_int_ch objCh;
	A_int_nch objNch;
	pr = &objCh;
	pr->Set(mass);
	pr-> print();

	cout << "\n\n";

	pr = &objNch;
	pr->Set(mass);
	pr->print();

	return 0;
}

