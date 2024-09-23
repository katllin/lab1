#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
char bufRus[256];
char* Rus(const char* text) {
	CharToOemA(text, bufRus);
	return bufRus;
}




using namespace std;

class Bank
{
public:

	Bank() : name("Noname"), vkladovCount(0), vklad(0), procent(0) {};
	Bank(string n, int c, double p, int pr)
	{
		name = n;
		if (c < 0) 
		{
			vkladovCount = 0;
		}
		else
		{
			vkladovCount = c;
		}
		if (p < 0) 
		{
			vklad = 0;
		}
		else
		{
			vklad = p;
		}
		if (pr < 0) 
		{
			procent = 0;
		}
		else
		{
			procent = pr;
		}
	};
	double getRevenue() 
	{
		return vklad * (vkladovCount + vkladovCount * procent/100.0);
	}

	string getName()
	{
		return name;
	}

	void setVkladovCount(int count) 
	{
		if (count < 0) 
		{
			vkladovCount = 0;
		}
		else
		{
			vkladovCount = count;
		}
	}
	void setProcent(int count)
	{
		if (count < 0)
		{
			procent = 0;
		}
		else 
		{
			procent = count;
		}
	}
	void setVklad(double p)
	{
		if (p < 0)
		{
			vklad = 0;
		}
		else
		{
			vklad = p;
		}
	}

	void setName(string n)
	{
		name = n;
	}

private:
	string name;
	double vklad;
	int vkladovCount;
	int procent;

};




int main() {
	Bank Sber("Sber", 10, 1500, 5);
	printf(Rus("Для банка %s выплата: %f"), Sber.getName().c_str(), Sber.getRevenue());
	return 0;
}