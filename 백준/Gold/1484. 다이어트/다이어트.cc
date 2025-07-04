#include <iostream>
#include <vector>
using namespace std;

const int maxSize = 50000;
vector<int> results;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int g;
	cin >> g;

	int right = 2;

	for (int left = 1; left < maxSize; left++)
	{
		while ((right * right) - (left * left) <= g)
		{
			int nowG = (right * right) - (left * left);
			if (nowG == g)
			{
				results.push_back(right);
			}
			right++;
		}
	}

	int resultSize = results.size();
	if (resultSize == 0)
	{
		cout << -1;
	}
	else
	{
		for (int i = 0; i < resultSize; i++)
		{
			cout << results[i];
			if (i != resultSize - 1) cout << '\n';
		}
	}

	return 0;
}