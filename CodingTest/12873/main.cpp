#include <iostream>
#include <list>
using namespace std;

class Queue
{
public:
	void Push(int item)
	{
		_list.push_back(item);
	}

	int Top()
	{
		return _list.front();
	}

	void Pop()
	{
		_list.pop_back();
	}

	int Size()
	{
		return _list.size();
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

	void ResetIter()
	{
		it = _list.begin();
	}

	void Remove()
	{
		it = _list.erase(it);
		if (it == _list.end()) it = _list.begin();
	}

	void Move()
	{
		it++;
		if (it == _list.end()) it = _list.begin();
	}

private:
	list<int> _list;
	list<int>::iterator it;
};

// long long int tmp = count * count * count; 3�����̹Ƿ� 125,000,000,000�̶� long long int�� �ؾ� �ð� �ʰ��� �� ���.
// ���� �� ������ �ʰ� %�� �������� �̿��ϴ� �κ��� �߿���
// ���� �������� 0�� ��� size ���� �����༭ �ʱ�ȭ ������Ѵ�.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Queue queue;

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		queue.Push(i);
	}

	long long int count = 1;
	queue.ResetIter();

	while (queue.Size() > 1)
	{
		long long int size = queue.Size();
		long long int tmp = count * count * count;
		tmp %= size;

		if (tmp == 0) tmp = size;

		for (long long int i = 1; i < tmp; i++)
		{
			queue.Move();
		}
		queue.Remove();

		count++;
	}

	cout << queue.Top();

	return 0;
}