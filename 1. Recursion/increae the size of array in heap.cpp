#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	int* p, * q;
	int i;
	p = (int*)malloc(5 * sizeof(int));
	q= (int*)malloc(10 * sizeof(int));
	p[0] = 3; p[1] = 4; p[2] = 5;
	for (i = 0; i <= 2; i++)
		q[i] = p[i];

	free(p);
	p = q;
	q = NULL;
	for (i = 0; i <= 2; i++)
		printf("%d\n", q[i]);
}