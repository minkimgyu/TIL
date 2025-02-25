#include <iostream>
#include <stack>
using namespace std;

int n;
int arr[500001];
int result[500001];

stack<pair<int, int>> st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (st.empty())
		{
			st.push({ i, arr[i] });
		}
		else
		{
			while (st.empty() == false && st.top().second < arr[i]) // ���� ���̺��� ���� �͵��� �� �̾��ش�.
			{
				st.pop();
			}

			if (st.empty() == false) // ���� ����ִ� ��츦 Ȯ���ؼ� �־��ش�.
			{
				result[i] = st.top().first;
			}

			st.push({ i, arr[i] });
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << result[i];
		if (i != n) cout << " ";
	}

	return 0;
}