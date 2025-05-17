#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int k = 1; k <= n; k++)
	{
		queue<pair<pair<int, int>, int>> q;
		map<pair<pair<int, int>, int>, bool> visit;

		string firstWord, secondWord, thirdWord;
		cin >> firstWord >> secondWord >> thirdWord;

		q.push({ {0, 0}, 0 });
		visit[{ {0, 0}, 0 }] = true;

		bool canFind = false;

		while (q.empty() == false)
		{
			pair<pair<int, int>, int> top = q.front(); q.pop();

			if (firstWord[top.first.first] == thirdWord[top.second] &&
				secondWord[top.first.second] == thirdWord[top.second])
			{
				if (top.first.first + 1 <= firstWord.size())
				{
					pair<pair<int, int>, int> firstIndex = { {top.first.first + 1, top.first.second}, top.second + 1 };

					if (firstIndex.second == thirdWord.size()) // 3번째 단어가 마지막에 도달한 경우
					{
						canFind = true;

						cout << "Data set " << k << ":" << " yes";
						if (k != n) cout << "\n";
						break;
					}

					if (visit[firstIndex] == false)
					{
						q.push(firstIndex);
						visit[firstIndex] = true;
					}
				}

				if (top.first.second + 1 <= secondWord.size())
				{
					pair<pair<int, int>, int> secondIndex = { {top.first.first, top.first.second + 1}, top.second + 1 };

					if (secondIndex.second == thirdWord.size()) // 3번째 단어가 마지막에 도달한 경우
					{
						canFind = true;
						cout << "Data set " << k << ":" << " yes";
						if (k != n) cout << "\n";
						break;
					}

					if (visit[secondIndex] == false)
					{
						q.push(secondIndex);
						visit[secondIndex] = true;
					}
				}
			}
			else if (firstWord[top.first.first] == thirdWord[top.second])
			{
				if (top.first.first + 1 <= firstWord.size())
				{
					pair<pair<int, int>, int> firstIndex = { {top.first.first + 1, top.first.second}, top.second + 1 };

					if (firstIndex.second == thirdWord.size()) // 3번째 단어가 마지막에 도달한 경우
					{
						canFind = true;
						cout << "Data set " << k << ":" << " yes";
						if (k != n) cout << "\n";
						break;
					}

					if (visit[firstIndex] == false)
					{
						q.push(firstIndex);
						visit[firstIndex] = true;
					}
				}
			}
			else if (secondWord[top.first.second] == thirdWord[top.second])
			{
				if (top.first.second + 1 <= secondWord.size())
				{
					pair<pair<int, int>, int> secondIndex = { {top.first.first, top.first.second + 1}, top.second + 1 };

					if (secondIndex.second == thirdWord.size()) // 3번째 단어가 마지막에 도달한 경우
					{
						canFind = true;
						cout << "Data set " << k << ":" << " yes";
						if (k != n) cout << "\n";
						break;
					}

					if (visit[secondIndex] == false)
					{
						q.push(secondIndex);
						visit[secondIndex] = true;
					}
				}
			}
		}

		if (canFind == false)
		{
			cout << "Data set " << k << ":" << " no";
			if (k != n) cout << "\n";
		}
	}

	return 0;
}