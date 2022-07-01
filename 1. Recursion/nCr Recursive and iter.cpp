#include <iostream>

using namespace std;
//nCr iterator 
int fact(int n) // factorial function
{
	if (n == 0) return 1;
	return fact(n - 1)* n;
}
int c(int n, int r) //itaretor type
{
	int num, den;
	num = fact(n);
	den = fact(r) * fact(n - r);
	return num / den;
}
int ncr(int n, int r) //recursive function
{
	if (n == r || r == 0)
		return 1;
	return ncr(n - 1, r - 1) + ncr(n - 1, r);
}

int main()
{
	cout << ncr(6, 4) << endl;
	cout << c(6, 4) << endl;
	return 0;
}
	