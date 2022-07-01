#include <iostream>

using namespace std;
//Fibonacci number itaretive 
int fib(int n)
{
	int t0 = 0, t1 = 1, s = 0, i;
	if (n <= 1)
		return n;
	else
	for (i = 2; i <= n; i++)
	{
		s = t0 + t1;
		t0 = t1;
		t1 = s;
	}
	return s;
}
//recursive with array mamorization function 
int f[10];
int fib1(int n)
{
	if (n <= 1)
	{
		f[n] = n;
		return n;
	}
	else
	{
		if (f[n - 2] == -1) //dont know the value
		{
			f[n - 2] = fib1(n - 2); //call the value
		}
		if (f[n - 1] == -1)
			f[n - 1] = fib1(n - 1);
		f[n] = f[n - 2] + f[n - 1];
		return f[n - 2] + f[n - 1];
	}
}
int main()
{
	int i;
	for (i = 0; i < 10; i++)
		f[i] = -1; //creat 10 arraw then modify by the function
	cout << fib1(10) << endl;
	cout << fib(10);
	return 0;
}