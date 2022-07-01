#include <bits/stdc++.h>
#include<iostream>

using namespace std;

class Element
{
public:
	int i, j, x;
};
class sparse
{
private:
	int m, n, num;
	Element* ele;
public:
	sparse(int m, int n, int num)
	{
		this->m = m;
		this->n = n;
		this->num = num;
		ele = new Element[this->num];
	}
	~sparse()
	{
		delete[] ele;
	}

	sparse operator+(sparse& s);

	friend istream & operator >>(istream& is, sparse& s); // insertion operator overloading 
	friend ostream & operator <<(ostream& os, sparse& s);  // extertion operatior
}; 

istream& operator >>(istream& is, sparse& s)                // wiith out using amy referencing
{
		cout<< "Enter the non zeroelements";
		for (int i = 0; i < s.num; i++)
			cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x; 
		return is;
}
ostream& operator <<(ostream& os, sparse& s)
{
		int k = 0;
		for (int i = 0; i < s.m; i++)
		{
			for (int j = 0; j < s.n; j++)
			{
				if (s.ele[k].i == i && s.ele[k].j == j)
					cout << s.ele[k++].x << " ";
				else
					cout << "0 ";
			}
			cout << endl;
		}
		return os;
}

sparse sparse::operator+(sparse& s)   //by referenceing
{
	int i, j, k;
	if (m != s.m || n != s.n)
		return sparse(0, 0, 0);

	sparse* sum = new sparse(m, n, num + s.num);
	i = j = k = 0;
	while (i < num && j < s.num)
	{
		if (ele[i].i < s.ele[j].i)
			sum->ele[k++] = ele[i++];
		else if (ele[i].i > s.ele[j].i)
			sum->ele[k++] = s.ele[j++];
		else
		{
			if (ele[i].j < s.ele[j].j)
				sum->ele[k++] = ele[i++];
			else if (ele[i].j > s.ele[j].j)
				sum->ele[k++] = s.ele[j++];
			else
			{
				sum->ele[k] = ele[i];
				sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
			}
		}
	}
	for (; i < num; i++)sum->ele[k++] = ele[i];
	for (; j < s.num; j++)sum->ele[k++] = s.ele[j];
	sum->num = k;
	return *sum;
}
int main()
{
	sparse s1(5, 5, 5);
	sparse s2(5, 5, 5);
	cin >> s1;  // insertion 
	cout << s1;  //extertion

	sparse sum = s1 + s2;
	cout << "first matrix" << endl << s1;
	cout << "second matrix" << endl << s2;
	cout << "sum matrix" << endl << sum;
}
