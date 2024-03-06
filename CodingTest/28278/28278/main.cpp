#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Stack
{
private:
	vector<int> vec;

public:
	void Push(int num)
	{
		vec.push_back(num);
	}

	int Top()
	{
		return vec.back();
	}

	void Pop()
	{
		vec.pop_back();
	}

	int Count()
	{
		return vec.size();
	}

	bool IsClear()
	{
		return Count() == 0;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Stack stack;

	const int size = 10;
	int n = 0;
	cin >> n;
	cin.ignore(); // ���� ���ڸ� ���������

	for (int i = 0; i < n; i++)
	{
		char arr[size];
		cin.getline(arr, size);

		// ���ڿ� ������ ��Ʈ �� �˾Ƶα�
		
		istringstream ss(arr);
		string stringBuffer;
		vector<string> x;

		while (getline(ss, stringBuffer, ' ')) {
			x.push_back(stringBuffer);
		}

		// ���ڿ� ������ ��Ʈ �� �˾Ƶα�

		int selectNum = stoi(x[0]); // ������ ��ȯ�ϴ� �κ� �� �˾Ƶα�

		if (selectNum == 1)
		{
			int addNum = stoi(x[1]);
			stack.Push(addNum);
		}
		else if (selectNum == 2)
		{
			if (stack.IsClear() == true) 
			{
				cout << -1 << '\n'; 
				continue; 
			}

			int top = stack.Top();
			stack.Pop();
			cout << top << '\n';
		}
		else if (selectNum == 3)
		{
			cout << stack.Count() << '\n';
		}
		else if (selectNum == 4)
		{
			if (stack.IsClear()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (selectNum == 5)
		{
			if (stack.IsClear()) cout << -1 << '\n';
			else cout << stack.Top() << '\n';
		}
	}

	return 0;
}