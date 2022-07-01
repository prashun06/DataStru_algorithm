#include <bits/stdc++.h>

using namespace std;

// brute force algorithom
//permutation ....all possible steps

// Using recursive function
void perm1(char s[], int k)
{
	static int A[10] = { 0 };   //hash table
	static char res[10];       //result array
	int i;

	if (s[k] == '\0')           //end array 
	{
		res[k] = '\0';
		cout << res << endl;    // print after full array build
	}
	else
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			if (A[i] == 0)     //if the hash is 0
			{
				res[k] = s[i]; //copy that from S to result arraay
				A[i] = 1;      // make that hash 1
				perm1(s, k + 1);//recursive call 
				A[i] = 0;      //end that hash array will 0 for next perfome
			}
		}
	}
}

//using swap function and recurtion with low and high
void perm2(char s[], int l, int h)
{
	int i;
	if (l == h)  //out put condition
	{
		cout << s << endl;
	}
	else
	{
		for (i = l; i <= h; i++) 
		{
		    swap(s[l], s[i]);      //interchage to i and l 
			perm2(s, l + 1, h);    //recursion 
			swap(s[l], s[i]);      //interchage to i and l for next operation 
		}
	}
}

int main()
{
	char s[] = "ABC";
	perm1(s, 0);  // 0=intial of K
	perm2(s, 0, 2); // array  A B C '\0'
	                 //       l   h   
					  //      0 1 2
	return 0;
}

