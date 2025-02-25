#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class cmp
{
	// -1�� ���� �켱������ �����Ƿ�
	// cmp(�ٸ� ��, -1) == true�� ������ �ڵ带 �ۼ��ؾ��Ѵ�.

	// ���⼭ �����ؾ��ϴ� ���� �� ���ڰ� ���� ��� false�� ��ȯ�ؾ��Ѵ�.
public:
	bool operator()(int a, int b) const
	{
		if (abs(a) == abs(b))
		{
			return a > b;
		}
		else
		{
			return abs(a) > abs(b);
		}
	}
};

priority_queue<int, vector<int>, cmp> pQ;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (num == 0)
		{
			if (pQ.empty() == true)
			{
				cout << 0;
			}
			else
			{
				int top = pQ.top();
				cout << top;

				pQ.pop();
			}

			cout << '\n';
		}
		else
		{
			pQ.push(num);
		}
	}

	return 0;
}