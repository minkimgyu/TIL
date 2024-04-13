#include <iostream>
#include <list>
using namespace std;

struct Student
{
	char name[4];
	int num;
};

template <typename T>
class Queue
{
public:
	void Push(T item)
	{
		_list.push_back(item);
	}

	void Pop()
	{
		_list.pop_front();
	}

	T Top()
	{
		return _list.front();
	}

	int Size()
	{
		return _list.size();
	}

	void Move()
	{
		Student student = _list.front();
		Pop();
		Push(student);
	}

	bool IsEmpty()
	{
		return _list.size() == 0;
	}

private:
	list<T> _list;
};

// 문자열 함수 공부를 좀 해봐야할 듯
// 큐를 사용하는 기초적인 문제

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Queue<Student> queue;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Student student;

		char arr[4];
		int num;
		cin >> arr >> num;
		
		for (int i = 0; i < 4; i++) student.name[i] = arr[i];
		student.num = num;
		queue.Push(student);
	}

	while (queue.Size() > 1)
	{
		Student student = queue.Top();
		queue.Pop();

		for (int i = 1; i < student.num; i++)
		{
			queue.Move();
		}

		queue.Pop();
	}

	cout << queue.Top().name;


	return 0;
}