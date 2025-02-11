#include <iostream>

using namespace std;

////������
//int	Partition(int arr[], int start, int end)
//{
//	int iPivot = arr[(start + end) / 2];
//
//	while (start <= end)
//	{
//		while (arr[start] < iPivot)
//			++start;
//		while (arr[end] > iPivot)
//			--end;
//
//		if (start <= end)
//		{
//			int iTemp = arr[start];
//			arr[start] = arr[end];
//			arr[end] = iTemp;
//			++start;
//			--end;
//		}
//	}
//
//	return start;
//}
////�� ����
//void	QuickSort(int arr[], int start, int end, int length)
//{
//	int iPart = Partition(arr, start, end);
//
//	if (start < iPart - 1)
//	{
//		QuickSort(arr, start, iPart - 1, length);
//	}
//	if (end > iPart)
//	{
//		QuickSort(arr, iPart, end, length);
//	}
//
//	//for (int i = 0; i < length; ++i)
//	//{
//	//	cout << arr[i] << " ";
//	//}
//	//cout << endl;
//}

//���ǳ��� �� ����.
int Partition(int array[], int left, int right)
{
	//�ǹ� ����.
	int first = left;
	int pivot = array[first];

	++left;

	while (left <= right)
	{
		//left�� pivot���� ū �� �˻�.
		while (array[left] <= pivot)
		{
			++left;
		}

		//right�� pivot���� ������ �˻�.
		while (array[right] > pivot)
		{
			--right;
		}

		//left�� right�� �������� �ʾ��� ���� �� ��ȯ.
		if (left < right)
		{
			swap(array[left], array[right]);
		}
		else
		{
			break;
		}
	}

	//��ȯ
	swap(array[first], array[right]);

	//�ǹ� ��ȯ.
	return right;
}

void QuickSort(int array[], int left, int right)
{
	//Ÿ�� ����.
	if (left >= right)
	{
		return;
	}

	//����.
	int partition = Partition(array, left, right);

	//���� �迭 �� ����.
	QuickSort(array, left, partition - 1);
	//������ �迭 �� ����.
	QuickSort(array, partition + 1, right);
}


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
	int arr[] = { 18, 19, 21, 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16, 11, 25 };

	int length = _countof(arr);

	cout << "���� �� : ";

	PrintArray(arr, length);

	//����.
	QuickSort(arr, 0, length-1);

	cout << "���� �� : ";

	PrintArray(arr, length);

	cin.get();
}