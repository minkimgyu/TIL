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
			while (st.empty() == false && st.top().second < arr[i]) // 현재 높이보다 작은 것들을 다 뽑아준다.
			{
				st.pop();
			}

			if (st.empty() == false) // 값이 들어있는 경우를 확인해서 넣어준다.
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