#include <bits/stdc++.h>
#include<iostream>
using namespace std;

struct term
{
	int coeff;
	int exp;
};
struct poly
{
	int n;
	struct term* term;
};
void creat(struct poly *p)
{
	int i;
	cout << "Enter number of terms";
	cin >> p->n;
	p->term = new struct term;  // terms ar in heap
	cout << "enter terms" << endl;
	for (i=0;i<p->n;i++)
		cin >> p->term[i].coeff >> p->term[i].exp;
}
void display(struct poly p)
{
	int i;
	for (i = 0; i < p.n; i++)
		cout << p.term[i].coeff << " X " << p.term[i].exp << " + ";
}

// Adding two polinomial 

struct poly* add(struct poly* p1, struct poly* p2)
{
	int i, j, k;
	struct poly* sum;
	sum = (struct poly*)malloc(sizeof(struct poly));
	sum->term = new struct term;
	i = j = k = 0;
	while (i < p1->n && j < p2->n)
	{
		if (p1->term[i].exp > p2->term[j].exp)
			sum->term[k++] = p1->term[i++];
		else if (p1->term[i].exp < p2->term[j].exp)
			sum->term[k++] = p2->term[j++];
		else
		{
			sum->term[k].exp = p1->term[i].exp;
			sum->term[k++].coeff = p1->term[i ++].coeff + p2->term[j++].coeff;
		}
	}
	for (; i < p1->n; i++)sum->term[k++] = p1->term[i];
	for (; j < p2->n; j++)sum->term[k++] = p2->term[j];
	sum->n = k;
	return sum;
}

int main()
{
	struct poly p1,p2,*p3;

	creat(&p1);
	creat(&p2);
	p3 = add(&p1, &p2);
	display(p1);
	return 0;
}