#include <iostream>
using namespace std;

int* arr;
int len = 0;
int capacity = 0;

void init()
{
	arr = new int[1];
	capacity = 1;
}

void printArr()
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
}

void expend()
{
	int* tmp = new int[2 * capacity];
	for (int i = 0; i < len; i++) tmp[i] = arr[i]; // 데이터 옮기기

	delete[] arr;
	arr = tmp;

	capacity *= capacity;
}

void insert(int idx, int num)
{
	if (capacity == len) // 꽉찬 경우
	{
		expend();
	}

	for (int i = len; i > idx; i--)
	{
		arr[i] = arr[i - 1];
	}

	arr[idx] = num;
	len++;
}

int main()
{
	insert(0, 1);
	insert(0, 2);
	insert(0, 3);
	insert(0, 4);
	insert(0, 5);

	return 0;
}