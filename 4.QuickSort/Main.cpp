#include <iostream>

using namespace std;

////퀵정렬
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
////퀵 정렬
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

//강의내의 퀵 정렬.
int Partition(int array[], int left, int right)
{
	//피벗 선택.
	int first = left;
	int pivot = array[first];

	++left;

	while (left <= right)
	{
		//left는 pivot보다 큰 값 검색.
		while (array[left] <= pivot)
		{
			++left;
		}

		//right는 pivot보다 작은값 검색.
		while (array[right] > pivot)
		{
			--right;
		}

		//left와 right가 교차하지 않았을 때만 값 교환.
		if (left < right)
		{
			swap(array[left], array[right]);
		}
		else
		{
			break;
		}
	}

	//교환
	swap(array[first], array[right]);

	//피벗 변환.
	return right;
}

void QuickSort(int array[], int left, int right)
{
	//타출 조건.
	if (left >= right)
	{
		return;
	}

	//분할.
	int partition = Partition(array, left, right);

	//왼쪽 배열 퀵 정렬.
	QuickSort(array, left, partition - 1);
	//오른쪽 배열 퀵 정렬.
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
	// 자료 집합.
	int arr[] = { 18, 19, 21, 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16, 11, 25 };

	int length = _countof(arr);

	cout << "정렬 전 : ";

	PrintArray(arr, length);

	//정렬.
	QuickSort(arr, 0, length-1);

	cout << "정렬 후 : ";

	PrintArray(arr, length);

	cin.get();
}