#include <iostream>
using namespace std;

int n;
int maxNum = 1;
int minNum = 1;

bool CanMod(int number)
{
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0) return true;
	}

	return false;
}

void dfs(int number)
{
	if (n == 1)
	{
		cout << number << '\n';
	}

	for (int i = 0; i <= 9; i++)
	{
		int numberMulti = number * 10;
		numberMulti += i;

		if (numberMulti >= maxNum) return;
		
		bool canMod = CanMod(numberMulti);
		if (canMod == true) continue;

		if (numberMulti >= minNum)
		{
			cout << numberMulti;
			cout << '\n';
		}

		dfs(numberMulti);
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) maxNum *= 10;
	for (int i = 1; i < n; i++) minNum *= 10;

	dfs(2);
	dfs(3);
	dfs(5);
	dfs(7);
	return 0;
}