#include <iostream>
#include <vector>
using namespace std;

//�� �����(Geapify) �Լ�.
void Heapify(vector<int>& array, int length, int ix)
{
	while (true)
	{
		//�� ������ ���� �ε��� ����.
		int largest = ix;
		//���� �ڼ� �ε���
		int left = 2 * ix + 1;
		//������ �ڼ� �ε���
		int right = 2 * ix + 2;

		if (left < length && array[left] > array[largest])
		{
			largest = left;
		}

		if (right < length && array[right] > array[largest])
		{
			largest = right;
		}

		if (largest == ix)//�θ� ���� �� ũ�� ����������.
		{
			break;
		}

		swap(array[ix], array[largest]);
		ix = largest;
	}

}


//�� ���� �Լ� (GeapSort).
void HeapSort(vector<int>& array)
{
	//��ü ũ��.
	int length = (int)array.size();

	//�� ����.
	for (int i = length / 2-1; i >= 0; --i)
	{
		//�� �����.
		Heapify(array, length, i);
	}

	//����.
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


	cout << "���� �� : ";

	PrintArray(arr);

	//����.
	HeapSort(arr);

	cout << "���� �� : ";

	PrintArray(arr);
	cin.get();
}