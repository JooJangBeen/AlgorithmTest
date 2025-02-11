#include <iostream>

using namespace std;

void SelectionSort(int arr[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		//�ּҰ� ������ ����.
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
	// �ڷ� ����.
	int arr[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	int length = sizeof(arr) / sizeof(int);

	cout << "���� �� : ";

	PrintArray(arr, length);

	SelectionSort(arr, length);

	cout << "���� �� : ";

	PrintArray(arr, length);

	cin.get();
}