#include <iostream>
#include <list>
using namespace std;

struct Zombie
{
public:
	int _pos, _hp;
};

class Queue
{
public:
	void Push(Zombie item)
	{
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

	bool CanDie()
	{
		return _list.front()._pos == 0;
	}

	void Move()
	{
		for (list<Zombie>::iterator iter = _list.begin(); iter != _list.end(); iter++)
		{
			iter->_pos -= 1;
		}
	}

	void ApplyDamage(int damage, int range)
	{
		for (list<Zombie>::iterator iter = _list.begin(); iter != _list.end(); iter++)
		{
			if (iter->_pos <= range) iter->_hp -= damage;
		}
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

	Zombie Front() { return _list.front(); }

	Zombie Back() { return _list.back(); }


private:
	list<Zombie> _list;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Queue queue;

	int l;
	cin >> l;

	int mL, mK;
	cin >> mL >> mK;

	int c;
	cin >> c;

	for (int i = 0; i < l; i++)
	{
		Zombie zombie;
		zombie._pos = i + 1;
		cin >> zombie._hp;

		queue.Push(zombie);
	}

	while (1)
	{
		bool closeToTarget = queue.Front()._pos == 1; // 바로 앞에 있는 경우

		if (closeToTarget)
		{
			if (c > 0)
			{
				c--;
				queue.Pop();

				if (queue.IsEmpty() == true)
				{
					cout << "YES";
					return 0;
				}
			}
			else
			{
				queue.ApplyDamage(mL, mK);

				while (1)
				{
					if (queue.IsEmpty() == true)
					{
						cout << "YES";
						return 0;
					}

					if (queue.Front()._hp <= 0) queue.Pop();
					else break;
				}
			}
		}
		else
		{
			queue.ApplyDamage(mL, mK);

			while (1)
			{
				if (queue.IsEmpty() == true)
				{
					cout << "YES";
					return 0;
				}

				if (queue.Front()._hp <= 0) queue.Pop();
				else break;
			}
		}

		queue.Move();

		if (queue.CanDie())
		{
			cout << "NO";
			return 0;
		}
		
	}

	return 0;
}