#include <iostream>
#include <list>
using namespace std;

struct Pass
{
public :
	Pass(int pos, int time)
	{
		_pos = pos;
		_time = time;
	}

public:
	int _pos = 0;
	int _time = 0;
};

class Queue
{
public:
	void Push(Pass* item)
	{
		_list.push_back(item);
	}

	void Pop()
	{
		_list.pop_front();
	}

	Pass* Front()
	{
		return _list.front();
	}

	Pass* Back()
	{
		return _list.back();
	}

	int Size()
	{
		return _list.size();
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

private:
	list<Pass*> _list;
};

const int arrSize = 100001;
bool arr[arrSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	Pass* startPass = new Pass(n, 0);
	if (startPass->_pos == k)
	{
		cout << 0;
		return 0;
	}

	Queue queue;
	queue.Push(startPass);
	int minTime = 0;

	while (1)
	{
		Pass* pass = queue.Front();
		queue.Pop();

		int time = pass->_time + 1;

		if (pass->_pos - 1 >= 0 && arr[pass->_pos - 1] == false)
		{
			Pass* leftPass = new Pass(pass->_pos - 1, time);
			arr[pass->_pos - 1] = true;

			if (leftPass->_pos == k)
			{
				minTime = leftPass->_time;
				break;
			}

			queue.Push(leftPass);
		}

		if (pass->_pos + 1 < arrSize && arr[pass->_pos + 1] == false)
		{
			Pass* rightPass = new Pass(pass->_pos + 1, time);
			arr[pass->_pos + 1] = true;

			if (rightPass->_pos == k)
			{
				minTime = rightPass->_time;
				break;
			}

			queue.Push(rightPass);
		}

		if (pass->_pos * 2 < arrSize && arr[pass->_pos * 2] == false)
		{
			Pass* teleportPass = new Pass(pass->_pos * 2, time);
			arr[pass->_pos * 2] = true;

			if (teleportPass->_pos == k)
			{
				minTime = teleportPass->_time;
				break;
			}

			queue.Push(teleportPass);
		}
	}

	cout << minTime;

	return 0;
}