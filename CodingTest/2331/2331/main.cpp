#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool visit[1000002]{ false };

int ReturnAfterValue(int input, int multiply)
{
	int sum = 1;
	int gap = 10;

	int returnValue = 0;

	while (sum < input)
	{
		int after = sum * 10;
		int value = (input % after - (input % sum)) / sum;

		int afterValue = 1;
		for (int i = 0; i < multiply; i++) afterValue *= value;
		returnValue += afterValue;

		sum = after;
	}

	// 한번도 못 돈 경우
	if (returnValue == 0) return input;
	else return returnValue;

	/*int next = 0;

	while (input > 0) {
		next += (int)pow(input % 10, multiply);
		input /= 10;
	}

	return next;*/
}

long long int dfs(long long int value, int p, vector<long long int>* vec)
{
	if (visit[value] == true) return value;
	visit[value] = true;
	vec->push_back(value);

	int multipleValue = ReturnAfterValue(value, p);
	return dfs(multipleValue, p, vec);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, p;
	cin >> a >> p;

	vector<long long int> _vec;
	long long int item = dfs(a, p, &_vec);

	int size = _vec.size();
	for (int i = 0; i < size; i++)
	{
		if (_vec[i] == item)
		{
			cout << i;
			break;
		}
	}

	return 0;
}