#include <iostream>

using namespace std;
//trecing tree recuution

void Dscen(int x) //Dscending order 
{
	if (x > 0)
	{
		cout << x ;
		Dscen(x - 1);//call its own function
	}
}

void Ascen(int x)  //Ascending order
{
	if (x > 0)
	{
		Ascen(x - 1);
		cout << x;
	}
}

int main()
{
	int x = 3;
	Dscen(x);
	cout << endl;
	Ascen(x);
	return 0;
}