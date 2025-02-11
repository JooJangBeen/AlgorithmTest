#include <iostream>
#include <vector>
using namespace std;

//힙 만들기(Geapify) 함수.
void Heapify(vector<int>& array, int length, int ix)
{
	while (true)
	{
		//힙 구성을 위한 인덱스 변수.
		int largest = ix;
		//왼쪽 자손 인덱스
		int left = 2 * ix + 1;
		//오른쪽 자손 인덱스
		int right = 2 * ix + 2;

		if (left < length && array[left] > array[largest])
		{
			largest = left;
		}

		if (right < length && array[right] > array[largest])
		{
			largest = right;
		}

		if (largest == ix)//부모가 원래 더 크면 빠져나간다.
		{
			break;
		}

		swap(array[ix], array[largest]);
		ix = largest;
	}

}


//힙 정렬 함수 (GeapSort).
void HeapSort(vector<int>& array)
{
	//전체 크기.
	int length = (int)array.size();

	//힙 구성.
	for (int i = length / 2-1; i >= 0; --i)
	{
		//힙 만들기.
		Heapify(array, length, i);
	}

	//정렬.
	for (int i = length - 1; i > 0; --i)
	{
		swap(array[0], array[i]);
		Heapify(array, i, 0);
	}
}

void PrintArray(vector<int> array)
{
	for (int i = 0; i < (int)array.size(); ++i)
	{
		cout << array[i] << (i < (int)array.size() - 1 ? "," : "");
	}

	cout << "\n";
}

int main()
{
	vector<int> arr = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };


	cout << "정렬 전 : ";

	PrintArray(arr);

	//정렬.
	HeapSort(arr);

	cout << "정렬 후 : ";

	PrintArray(arr);
	cin.get();
}