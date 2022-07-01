#include <stdio.h>
#include <iostream>

//data type of array
struct array //array inputs
{
	int A [10];
	int size;
	int length;
};

//1. array display function
void dispaly(struct array arr)//arr is the object to call
{
	int i;
	printf("Elements are\n");
	for (i = 0; i < arr.length; i++)
		printf("%d", arr.A[i]);
}

//2. append or  add value in end
void append(struct array* arr, int x)//call by arr , the entering value
{
	if (arr->length < arr->size) //check is there any free space here 
		arr->A[arr->length++] = x;
}

//3. value insert at any place
void insert(struct array* arr, int index, int x) //index is the array location and x is the value
{
	int i;
	if (index >= 0 && index <= arr->length)
	{
		for (i = arr->length; i > index; i--)
			arr->A[i] = arr->A[i - 1]; //first the move place then the value place
		arr->A[index] = x;
		arr->length++;
	}
}
// 4. delete any value from array
int Delete(struct array* arr, int index)
{
	int x=0;
	int i;
	if (index >= 0 && index < arr->length)
	{
		x = arr->A[index];
		for (i = index; i < arr->length - 1; i++)
		    arr->A[i] = arr->A[i + 1];  //shift the value in empty space
		arr->length--;
		return x;//return the delete value
	}
	return 0;//if not work the function it will return nothing
}
//5. Linear search
// swap func with change the location of the value
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
//real linear algol
int LineraS(struct array *arr, int key)
{
	int i;
	for (i = 0; i <= arr->length-1; i++)//  -> to accessing the member
	{
		if (key == arr->A[i]) //to match all the element with key value
		{
			swap (&arr->A[i], &arr->A[i - 1]); //A[0] instade of A[i-1] will shift it first
				return i;
		}
	}
	return -1;
}
//6.Binary Search
int binaryS(struct array arr, int key)
{
	int l, h, mid;
	l = 0;
	h = arr.length - 1;

	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr.A[mid])
			return mid; // result will be the array number 
		else if (key < arr.A[mid])
			h = mid - 1;
		else
			l = mid + 1;			
	}
	return -1;
}

// Recursive Binary Search
int RbinaryS(int a[], int l, int h, int key)
{
	int mid;

	if (l <= h)
	{
		mid = (l + h) / 2;
		if (key == a[mid])
			return mid; // result will be the array number 
		else if (key < a[mid])
			return RbinaryS(a, l, mid - 1, key);
		else
			return RbinaryS(a, mid+1, h, key);
	}
	return -1;
}

// Get a value from array
int get(struct array arr, int index)
{
	if (index >= 0 && index < arr.length)
		return arr.A[index];
	return -1;
}

//Set a value in a spacific place of array
int set(struct array* arr, int index, int x) //call by address to change then value of address
{
	if (index >= 0 && index < arr->length)
	arr->A[index] = x;
	return x;
}

//Max number will bring in front
int max(struct array arr)
{
	int max = arr.A[0];  // take first value as max
	int i;
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] > max)
			max = arr.A[i];
	}
	return max;
}

//Min number will bring in front
int min(struct array arr)
{
	int min = arr.A[0];  // take first value as max
	int i;
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] < min)
			min = arr.A[i];
	}
	return min;
}


//sum all the element of array
int sum(struct array arr)
{
	int i,s=0;
	for (i = 0; i < arr.length; i++)
	s += arr.A[i];
	return s;
}

// average of all arrays uusing sum function
float Avg (struct array arr)
{
	return (float)sum(arr) / arr.length; //float type casted
}

//Reverse operation or array
void Reverse(struct array *arr)
{
	int *B;
	int i, j;

	B = new int[arr->length]; //creat an array in heap
	for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
	{
		B[i] = arr->A[j];
	}
	for (i = 0; i < arr->length; i++)
	{
		arr->A[i] = B[i];
	}
}

// Reverse 2nd version
void Reverse2(struct array* arr)
{
	int i, j, temp;
	for (i = 0, j = arr->length-1; i < j; i++, j--)
	{
		temp = arr->A[i];
		arr->A[i] = arr->A[j]; //just copy 
		arr->A[j] = temp;
	}
}

//shifting operation
void LeftShift(struct array *arr)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		arr->A[i] = arr->A[i + 1];
	}
}

void RightShift(struct array* arr)
{
	int i;
	for (i = arr->length-1; i >= 0; i--)
	{
		arr->A[i+1] = arr->A[i];
	}
}
void rotate (struct array* arr)
{
	int temp;
	temp = arr->A[0];
	LeftShift(arr);
	arr->A[arr->length - 1] = temp;
}

//Sorting operation
//1.insert with sorting order
void insertS(struct array* arr, int x)
{
	int i= arr->length-1;
	while (arr->A[i] > x) {
		arr->A[i+1] = arr->A[i];
		i--;
	}
	arr->A[i+1] = x;
	arr->length++;
}

//soting algorithom off array
void sort(struct array* arr)
{
	int temp1;
	int i,j;
	for (i = 0; i < arr->length; i++)
	{
		for (j = i + 1; j < arr->length; j++)
		{
			if (arr->A[i] > arr->A[j])//condition
			{
				temp1 = arr->A[i];
				arr->A[i] = arr->A[j];//transfer process
				arr->A[j] = temp1;
			}
		}
	}
}

//-Ve --+Ve sorting (polarity)
void PoleSort(struct array* arr)
{
	int i = 0, j = arr->length - 1;
	while(i<j)
	{
		while (arr->A[i] < 0) { i++; }
		while (arr->A[j] >= 0) { j--; }
		if(i<j)
		{
			swap(&arr->A[i], &arr->A[j]);
		}
	}
	sort(arr);
}

// Merge of 2 array 
struct array* merge(struct array* arr1, struct array* arr2)
{
	int i=0, j=0,k=0;

	struct array *arr3 = new struct array [10]; //3rd array construct
	
	while (i < arr1->length && j < arr2->length)//copy to 3rd array with sorted form
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else
			arr3->A[k++] = arr2->A[j++];
	}

	for (; i < arr1->length; i++) //copy rest of all            
		arr3->A[k++] = arr1->A[i];
	for (; j < arr2->length; j++)
		arr3->A[k++] = arr2->A[j];

	arr3->size = 10;
	arr3->length = arr1->length + arr2->length;

	return arr3; //return the whole array
}

// Union of 2 array 
struct array* Union(struct array* arr1, struct array* arr2)
{
	int i = 0, j = 0, k = 0;

	struct array* arr3 = new struct array[10]; //3rd array construct

	while (i < arr1->length && j < arr2->length)//copy to 3rd array with sorted form
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr1->A[i] > arr2->A[j])
			arr3->A[k++] = arr2->A[j++];
		else
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}	
	}
	arr3->size = 10;
	arr3->length = k;

	return arr3; //return the whole array
}

//  Intersection oparetion of 2 array
struct array* Intersection (struct array* arr1, struct array* arr2)
{
	int i = 0, j = 0, k = 0;

	struct array* arr3 = new struct array[10]; //3rd array construct

	while (i < arr1->length && j < arr2->length)//copy to 3rd array with sorted form
	{
		if (arr1->A[i] < arr2->A[j])
			i++;
		else if (arr1->A[i] > arr2->A[j])
			j++;
		else
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}
	arr3->size = 10;
	arr3->length = k;

	return arr3; //return the whole array
}

//Difference of 2 array
struct array* Difference(struct array* arr1, struct array* arr2)
{
	int i = 0, j = 0, k = 0;

	struct array* arr3 = new struct array[10]; //3rd array construct

	while (i < arr1->length && j < arr2->length)//copy to 3rd array with sorted form
	{
		if (arr1->A[i] < arr2->A[j])  //greater will take and rest will ignore
			arr3->A[k++] = arr1->A[i++]; 
		else if (arr1->A[i] > arr2->A[j])
			j++;
		else
		{
			i++;
			j++;
		}
	}
	for (; i < arr1->length; i++) //copy rest of all            
		arr3->A[k++] = arr1->A[i];
	arr3->size = 10;
	arr3->length = k;

	return arr3; //return the whole array
}
int main()
{
	struct array arr1 = { {2,4,7,9,0},10,5}; //array inputs
//20 is size and 5 is data length

	struct array arr2 = { {3,4,5,1,6},10,5};
	struct array* arr3;// this array for merge
	
	//append(&arr1, 10);     //call by address as parameter
	//insert(&arr1, 4, 9);   //          ,,
	//printf("\n%d\n", Delete(&arr1, 4)); 
	//printf("\n%d\n", LineraS(&arr1, 4));
	//printf("\n%d\n", binaryS(arr1, 9));
	//printf("\n%d\n", RbinaryS(arr1.A, 0, arr.length, 5));
	//printf("\n%d\n", get(arr1, 3));
	//printf("\n%d\n", set(&arr1, 3, 9));
	//printf("\n%d\n", max(arr1));
	//printf("\n%d\n", min(arr1));
	//printf("\n%d\n", sum(arr1));
	//printf("\n%d\n", Avg(arr1));
	//Reverse(&arr1);
	//Reverse2(&arr1);
	//LeftShift(&arr1);
	//RightShift(&arr1);
	//rotate(&arr1);
	//insertS(&arr1, 5);
	//sort(&arr1);
	//PoleSort(&arr1); 
	//arr3 = merge(&arr1, &arr2); 
	//arr3 = Union(&arr1, &arr2);
	//arr3 = Intersection(&arr1, &arr2);
	//arr3 = Difference(&arr1, &arr2);
	dispaly(*arr3);
	
	return 0;
} 
	