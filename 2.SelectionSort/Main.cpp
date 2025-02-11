#include <iostream>

using namespace std;

void SelectionSort(int arr[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		//최소값 저장할 변수.
		int minIndex = i;

		for (int j = i + 1; j < length; ++j)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		swap<int>(arr[i], arr[minIndex]);
	}
}

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
	// 자료 집합.
	int arr[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	int length = sizeof(arr) / sizeof(int);

	cout << "정렬 전 : ";

	PrintArray(arr, length);

	SelectionSort(arr, length);

	cout << "정렬 후 : ";

	PrintArray(arr, length);

	cin.get();
}