#include <iostream>

using namespace std;

void Merge(int array[],
	int leftArray[], int leftArrayLength,
	int rightArray[], int rightArrayLength)
{
	//�ε��� ���� ����.
	int leftIndex = 0;
	int rightIndex = 0;
	int mergedIndex = 0;

	//����/������ �迭�� ��Ҹ� ���ϸ鼭 ���� ������ array�� �� �Ҵ�.
	while (leftIndex < leftArrayLength && rightIndex < rightArrayLength)
	{
		//����/������ ��.
		if (leftArray[leftIndex] <= rightArray[rightIndex])
		{
			array[mergedIndex] = leftArray[leftIndex];
			++leftIndex;
		}
		else
		{
			array[mergedIndex] = rightArray[rightIndex];
			++rightIndex;
		}

		++mergedIndex;
	}

	//�� �������� ���� ���� �迭 ��Ҹ� ���� �迭�� ����.
	while (leftIndex < leftArrayLength)
	{
		array[mergedIndex] = leftArray[leftIndex];
		++mergedIndex;
		++leftIndex;
	}
	//�� �������� ���� ������ �迭 ��Ҹ� ���� �迭�� ����.
	while (rightIndex < rightArrayLength)
	{
		array[mergedIndex] = rightArray[rightIndex];
		++mergedIndex;
		++rightIndex;
	}
}

//���� �Լ�.
void MergeSort(int array[], int length)
{
	//Ż�� ������ �ʿ�(����Լ��� ����Ŷ�.).
	if (length <= 1)
	{
		return;
	}

	//�迭 ����.
	int mid = length / 2;
	//����/������ �迭�� ���� Ȯ��.
	int* leftArray = new int[mid];
	int* rightArray = new int[length - mid];

	//�� ����.
	memcpy(leftArray, array, sizeof(int) * mid);
	memcpy(rightArray, array + mid, sizeof(int) * (length - mid));

	//����� ȣ��.
	//���� �迭�� ���� ��� ȣ��.
	MergeSort(leftArray, mid);
	//������ �迭�� ���� ��� ȣ��.
	MergeSort(rightArray, length - mid);

	//����(��� Ż�����ǿ� ������ Ÿ����.).
	Merge(array, leftArray, mid, rightArray, length - mid);

	//�޸� ����.
	delete[] leftArray;
	delete[] rightArray;
}

void MyMerge(int arr[], int leftArr[], int leftLen, int rightArr[], int rightLen)
{
	int leftIdx = 0;
	int rightIdx = 0;
	int mergeIdx = 0;

	while (leftIdx < leftLen && rightIdx < rightLen)
	{
		if (leftArr[leftIdx] <= rightArr[rightIdx])
		{
			arr[mergeIdx] = leftArr[leftIdx];
			++leftIdx;
		}
		else
		{
			arr[mergeIdx] = rightArr[rightIdx];
			++rightIdx;
		}

		++mergeIdx;
	}

	while (leftIdx < leftLen)
	{
		arr[mergeIdx] = leftArr[leftIdx];
		++leftIdx;
		++mergeIdx;
	}
	while (rightIdx < rightLen)
	{
		arr[mergeIdx] = rightArr[rightIdx];
		++rightIdx;
		++mergeIdx;
	}
}
void MyMergeSort(int arr[], int length)
{
	if (length <= 1)
	{
		return;
	}

	int mid = length / 2;

	int* leftArr = new int[mid];
	int* rightArr = new int[length - mid];

	memcpy(leftArr, arr, sizeof(int) * mid);
	memcpy(rightArr, arr + mid, sizeof(int) * (length - mid));

	MyMergeSort(leftArr, mid);
	MyMergeSort(rightArr, length - mid);

	MyMerge(arr, leftArr, mid, rightArr, length - mid);

	delete[] leftArr;
	delete[] rightArr;
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
	int arr[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	//���� ���.
	int length = _countof(arr);

	cout << "���� �� : ";

	PrintArray(arr, length);

	//����.
	MyMergeSort(arr,length);

	cout << "���� �� : ";

	PrintArray(arr, length);
	cin.get();
}