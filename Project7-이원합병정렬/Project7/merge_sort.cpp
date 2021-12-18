#include <iostream>
using namespace std;

const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };


void print_data()
{
	for (int i = 0; i < SIZE; i++)
		cout << " " << L[i] << " ";
	cout << endl;
}

void merge(int left, int right, int m)
{
	int i, j, k;
	int B[SIZE];

	for (i = left; i <= m; i++) B[i] = L[i];
	for (j = m; j < right; j++) B[right + m - j] = L[j + 1];

	i = left; j = right;
	for (k = left; k <= right; k++)
		L[k] = (B[i] < B[j]) ? B[i++] : B[j--];
}

void merge_sort(int left, int right)
{
	int m;

	if (right > left)
	{
		m = (right + left) / 2;
		merge_sort(left, m);
		merge_sort(m + 1, right);
		merge(left, right, m);
	}
}

void main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	merge_sort(0, SIZE - 1);

	cout << "\n\nSorted Data : ";
	print_data();
}