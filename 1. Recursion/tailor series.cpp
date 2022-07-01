#include <iostream>

using namespace std;
//trecing tree recuution

double e (int x , int n)
{
	double r;
	static double p = 1, f = 1;
	if (n == 0)
		return 1;
	else r = e(x, n - 1);
	     p = p * x;
		 f = f * n;
		 return r + (p / f);
}
int main()
{
	cout << e(3, 10);
	return 0;
}