#include <iostream>


using namespace std;

//���� ���� �Լ�.
void InsertionSort(int array[], int length)
{
	//�迭 ��ȸ
	for (int i = 1; i < length; ++i)
	{
		//Ű �̱�.
		int keyValue = array[i];
		int j = i - 1;


		//���ø�(��ȯ)
		while (j >= 0 && array[j] > keyValue)
		{
			array[j + 1] = array[j];
			--j;
		}

		//�� �����.
		array[j + 1] = keyValue;
	}
}

//�迭 ����Լ�.
void PrintArray(int array[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << array[i] << (i < length - 1 ? "," : "");
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

	InsertionSort(arr, length);

	cout << "���� �� : ";

	PrintArray(arr, length);

	cin.get();
}