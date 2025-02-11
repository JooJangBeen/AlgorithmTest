#include <iostream>


using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int array[], int length)
{
	//정렬

	for (int i = 0; i < length-1; ++i)
	{
		for (int j = 0; j < length-1 - i; ++j)
		{
			if (array[j] > array[j+1])
			{
				Swap(array[j], array[j+1]);
			}
		}
	}
}

//출력함수.
void PrintArray(int array[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << array[i] << " ";
	}

	cout << "\n";
}

int main()
{
	int arr[] = { 5, 2, 8, 4, 1 ,9, 6, 7, 3, 10};

	int length = sizeof(arr) / sizeof(int);

	cout << "정렬 전 : ";

	PrintArray(arr, length);

	BubbleSort(arr, length);

	cout << "정렬 후 : ";

	PrintArray(arr, length);

	cin.get();
}