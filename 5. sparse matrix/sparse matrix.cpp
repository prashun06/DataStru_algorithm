#include <bits/stdc++.h>


using namespace std;

struct Elements
{
	int i, j, x;
};
struct Sparse
{
	int m, n, num;
	struct Elements* ele;
};
void creat(struct Sparse* s)
{
	int i;
	printf("Eneter Dimensions");
	scanf("%d%d", &s->m, &s->n);
	printf("Number of non-zero");
	scanf("%d", &s->num);
	s->ele = new struct Elements(s->num);
	printf("Eneter non-zero Elements");
	for (i = 0; i < s->num; i++)
		scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);  //non zero elements
}

void display(struct Sparse s)
{
	int i, j, k = 0;
	for (i = 0; i < s.m; i++)
	{
		for (j = 0; j < s.n; j++)
		{
			if (i == s.ele[k].i && j == s.ele[k].j)
				printf("%d ", s.ele[k++].x);  // k= last elemantary array
			else
				printf("0 ");
		}
		printf("\n");
	}
}

struct Sparse* add(struct Sparse* s1, struct Sparse* s2)
{
	struct Sparse* sum;
	int i, j, k;
	i = j = k = 0;
	sum = new struct Sparse;  // a new sum 4 box in heap
	sum->ele = new struct Elements(s1->num + s2->num); // a element array is created under a sum array in heap
	while (i < s1->num && j < s2->num)
	{
		if (s1->ele[i].i < s2->ele[j].i)    // chaek the row
			sum->ele[k++] = s1->ele[i++];
		else if (s1->ele[i].i > s2->ele[j].i)
			sum->ele[k++] = s2->ele[j++];
		else
		{
			if (s1->ele[i].j < s2->ele[j].j)  // chaek the coloum 
				sum->ele[k++] = s1->ele[i++];
			else if (s1->ele[i].j > s2->ele[j].j)
				sum->ele[k++] = s2->ele[j++];
			else
			{
				sum->ele[k] = s1->ele[i];   //make the sum
				sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;  // sum of the same row and coloum
			}
		}
	}
	for (; i < s1->num; i++)sum->ele[k++] = s1->ele[i];  // rest of all other 
	for (; j < s2->num; j++)sum->ele[k++] = s2->ele[j];
	sum->m = s1->m;             // other dimention information
	sum->n = s1->n;
	sum->num = k;
}

int main()
{
	struct Sparse s1, s2, * s3;
	creat(&s1);
	creat(&s2);

	s3 = add(&s1, &s2);


	cout << "first matrix";
	display(s1);
	cout << "seconf matrix";
	display(s2);
	cout << "sum matrix";
	display(*s3);
	return 0;

}