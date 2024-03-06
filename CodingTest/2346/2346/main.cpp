#include <iostream>
#include <list>

struct Balloon
{
public:
	Balloon(int index, int value) : _index(index), _value(value) {}

	int GetValue() { return _value; }
	int GetIndex() { return _index; }

private:
	int _index, _value;
};

/// <summary>
/// 원형 리스트로 풀이하는 문제
/// 풍선을 터트리고 움직여야 맞게 값이 나온다!!
/// 왼쪽으로 이동할 때랑 오른쪽으로 이동할 때 이동해야하는 값이 다르다
/// 오른쪽은 삭제 시 한 칸 이동하게 되므로 -1 해서 계산해주기
/// </summary>

class CircleList
{
private:
	std::list<Balloon*> list;
	std::list<Balloon*>::iterator iter;

public:
	void Init()
	{
		iter = list.begin();
	}

	bool IsClear()
	{
		return list.size() == 0;
	}

	void Move(int offset)
	{
		int tmp = 0;

		if (offset < 0)
		{
			offset *= -1;
			while (tmp < offset)
			{
				if (iter == list.begin()) iter = --list.end();
				else iter--;
				tmp++;
			}
		}
		else
		{
			while (tmp < offset - 1)
			{
				if (iter == --list.end()) iter = list.begin();
				else iter++;
				tmp++;
			}
		}
	}

	Balloon* GetIterValue()
	{
		Balloon* tmp = *iter;
		return tmp;
	}

	void Pop()
	{
		iter = list.erase(iter);
		if (iter == list.end()) iter = list.begin();
	}

	void Push(Balloon* ballon)
	{
		list.push_back(ballon);
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	std::cin >> n;

	CircleList circleList;

	for (int i = 1; i <= n; i++)
	{
		int tmp;
		std::cin >> tmp;
		circleList.Push(new Balloon(i, tmp));
	}

	circleList.Init();

	for (int i = 0; i < n; i++)
	{
		Balloon* balloon = circleList.GetIterValue();
		circleList.Pop();

		if (circleList.IsClear() == false) circleList.Move(balloon->GetValue());

		if (i == n - 1) std::cout << balloon->GetIndex();
		else std::cout << balloon->GetIndex() << " ";

		delete balloon;
	}

	return 0;
}