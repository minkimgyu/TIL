#include<iostream>
#include<list>
using namespace std;

struct Truck
{
public:
	int _weight = 0;
	int _pos = 0;
};

class Queue
{
public:
	void Push(Truck truck)
	{
		_list.push_back(truck);
		_weight += truck._weight;
	}

	void Move(int length)
	{
		if (IsEmpty() == true) return;

		for (list<Truck>::iterator it = _list.begin(); it != _list.end(); it++)
		{
			it->_pos += 1;
		}

		if (Top()._pos > length) Pop();
	}

	Truck Top()
	{
		return _list.front();
	}

	void Pop()
	{
		_weight -= Top()._weight;
		_list.pop_front();
	}

	int Size()
	{
		return _list.size();
	}

	bool IsFull(int weight, int additive)
	{
		return _weight + additive > weight;
	}

	bool IsEmpty()
	{
		return _list.size() == 0;
	}

private:
	list<Truck> _list;
	int _weight = 0;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Queue tmpQueue;
	Queue queue;

	int time = 0;
	int n, w, l;
	cin >> n >> w >> l;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		Truck truck;
		truck._pos = 0;
		truck._weight = tmp;

		tmpQueue.Push(truck);
	}


	while (1)
	{
		queue.Move(w);

		if (tmpQueue.IsEmpty() == false)
		{
			Truck top = tmpQueue.Top();

			if (queue.IsFull(l, top._weight) == false)
			{
				top._pos += 1;
				queue.Push(top);
				tmpQueue.Pop();
			}
		}

		time++;
		if (queue.IsEmpty() == true) break;
	}

	cout << time;

	return 0;
}