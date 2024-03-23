#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Car 
{
public:
	int _index, _weight;
};

template <typename T>
class Queue
{
public:
	void Push(T item)
	{
		if (IsFull() == true) return;

		_list.push_back(item);
	}

	void Pop()
	{
		_list.pop_front();
	}

	int Size() 
	{
		return _list.size();
	}

	bool IsFull()
	{
		return Size() == _maxSize;
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

	T Top()
	{
		return *_list.begin();
	}

public:
	int _cost;
	int _maxSize = 1;

private:
	list<T> _list;
};

// ������ ���ٸ� ���� ť�� �־ �����ϰ� ������ �ٽ� �ű⿡ �ִ´� --> �߿�
// ���� �дµ� �ð��� ���� �ɸ��� ����

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<Car> startCars;
	vector<Queue<Car>> parkings;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int cost;
		cin >> cost;

		Queue<Car> parking;
		parking._cost = cost;
		parkings.push_back(parking);
	}

	for (int i = 1; i <= m; i++)
	{
		int weight;
		cin >> weight;

		Car car;
		car._index = i;
		car._weight = weight;
		startCars.push_back(car);
	}

	int sum = 0;
	Queue<int> carIndexQueue;
	carIndexQueue._maxSize = m;

	for (int i = 0; i < 2 * m; i++)
	{
		int index;
		cin >> index;

		if (index < 0)
		{
			int resetIndex = index * -1;

			int size = parkings.size();
			for (int i = 0; i < size; i++)
			{
				if (parkings[i].IsEmpty() == true) continue;

				if (parkings[i].Top()._index != resetIndex) continue;

				parkings[i].Pop();

				if (carIndexQueue.IsEmpty() == false) // ť�� ������� �ʴٸ�
				{
					int carIndex = carIndexQueue.Top();
					Car car = startCars[carIndex - 1];

					sum += car._weight * parkings[i]._cost;
					parkings[i].Push(car);

					carIndexQueue.Pop(); // ť���� ��������
				}

				break;
			}
		}
		else
		{
			carIndexQueue.Push(index);
			Car car = startCars[index - 1];

			int size = parkings.size();
			for (int i = 0; i < size; i++)
			{
				if (parkings[i].IsFull()) continue;

				sum += car._weight * parkings[i]._cost;
				parkings[i].Push(car);

				carIndexQueue.Pop(); // ť���� ��������
				break;
			}
		}
	}

	cout << sum;

	return 0;
}