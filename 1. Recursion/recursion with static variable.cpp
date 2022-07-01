#include <iostream>

using namespace std;
//trecing tree recursion with static variable 

int x = 0;
int fun(int n)
{
	if (n > 0)
	{
		x++;
		return fun(n - 1) + x;
	}
	return 0;
}
int main()
{
	int x = 5;
	cout << fun(x);
	return 0;
}