#include <iostream>
#include <vector>
using namespace std;

class Stack
{
public:
	void Push(int item)
	{
		_vec.push_back(item);
	}

	void Pop()
	{
		_vec.pop_back();
	}

	bool IsEmpty() 
	{ 
		int size = Size();
		return size == 0;
	}

	int Top()
	{
		if (IsEmpty() == true) return -1;

		int size = Size();
		return _vec[size - 1];
	}

	int Size()
	{
		return _vec.size();
	}

private:
	vector<int> _vec;
};

// 시간 복잡도: O(2n + n^2) -- 최악의 경우
// 스택을 사용하는 방법이 중요!
// 넣기 전에 빼는 방법을 생각해보자

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Stack itemStack;
	Stack resultStack;

	Stack outPutStack;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		itemStack.Push(tmp);
	}

	for (int i = 0; i < n; i++)
	{
		int topItem = itemStack.Top();
		if (i == 0) 
		{
			resultStack.Push(topItem);
			outPutStack.Push(-1);
		}
		else
		{
			while (resultStack.Top() <= topItem && resultStack.IsEmpty() == false)
			{
				resultStack.Pop();
			}

			if (resultStack.IsEmpty()) outPutStack.Push(-1);
			else outPutStack.Push(resultStack.Top());

			resultStack.Push(topItem);
		}

		itemStack.Pop();
	}


	int size = outPutStack.Size();
	for (int i = 0; i < size; i++)
	{
		if(i == size - 1) cout << outPutStack.Top();
		else cout << outPutStack.Top() << " ";
		
		outPutStack.Pop();
	}

	return 0;
}