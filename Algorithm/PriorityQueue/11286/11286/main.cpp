#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class cmp
{
	// -1이 가장 우선순위가 높으므로
	// cmp(다른 값, -1) == true가 나오게 코드를 작성해야한다.

	// 여기서 주의해야하는 점은 비교 인자가 같은 경우 false를 반환해야한다.
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