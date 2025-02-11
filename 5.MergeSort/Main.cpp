#include <iostream>

using namespace std;

void Merge(int array[],
	int leftArray[], int leftArrayLength,
	int rightArray[], int rightArrayLength)
{
	//인덱스 변수 선언.
	int leftIndex = 0;
	int rightIndex = 0;
	int mergedIndex = 0;

	//왼쪽/오른쪽 배열의 요소를 비교하면서 작은 순서로 array에 값 할당.
	while (leftIndex < leftArrayLength && rightIndex < rightArrayLength)
	{
		//왼쪽/오른쪽 비교.
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

	//위 과정에서 남은 외쪽 배열 요소를 최종 배열에 복사.
	while (leftIndex < leftArrayLength)
	{
		array[mergedIndex] = leftArray[leftIndex];
		++mergedIndex;
		++leftIndex;
	}
	//위 과정에서 남은 오른쪽 배열 요소를 최종 배열에 복사.
	while (rightIndex < rightArrayLength)
	{
		array[mergedIndex] = rightArray[rightIndex];
		++mergedIndex;
		++rightIndex;
	}
}

//정렬 함수.
void MergeSort(int array[], int length)
{
	//탈출 조건이 필요(재귀함수로 만들거라.).
	if (length <= 1)
	{
		return;
	}

	//배열 분할.
	int mid = length / 2;
	//왼쪽/오른쪽 배열의 공간 확보.
	int* leftArray = new int[mid];
	int* rightArray = new int[length - mid];

	//값 복사.
	memcpy(leftArray, array, sizeof(int) * mid);
	memcpy(rightArray, array + mid, sizeof(int) * (length - mid));

	//재귀적 호출.
	//왼쪽 배열에 대해 재귀 호출.
	MergeSort(leftArray, mid);
	//오른쪽 배열에 대해 재귀 호출.
	MergeSort(rightArray, length - mid);

	//병합(재귀 탈출조건에 나오면 타진다.).
	Merge(array, leftArray, mid, rightArray, length - mid);

	//메모리 해제.
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

	//길이 계산.
	int length = _countof(arr);

	cout << "정렬 전 : ";

	PrintArray(arr, length);

	//정렬.
	MyMergeSort(arr,length);

	cout << "정렬 후 : ";

	PrintArray(arr, length);
	cin.get();
}