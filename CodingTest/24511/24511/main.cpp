#include <iostream>
#include <vector>
#include <list>
using namespace std;

class QueueStack
{
private:
	list<int> _list;
	int _type;

public:
	void PushBack(int item)
	{
		_list.push_back(item);
	}

	void PushFront(int item)
	{
		_list.push_front(item);
	}

	int Pop()
	{
		int item;
		item = _list.back();
		_list.pop_back();

		return item;
	}
};

// ��ǻ� ������ Ǫ�� ����
// Stack�� �ǹ̰� ���� Queue�� ���̴� ������� ���� Ǯ�� �����ؾ���

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* arr = new int[n];

	QueueStack queueStack;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		if (arr[i] == 1) continue;
		queueStack.PushBack(tmp);
	}
	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;

		queueStack.PushFront(tmp);
		int result = queueStack.Pop();

		if(i == m - 1) cout << result;
		else cout << result << " ";
	}

	delete[] arr;

	return 0;
}