#include <iostream>
#include <vector>
using namespace std;

bool IsPrime(int number)
{
	if (number == 1) return false;

	for (int i = 2; i < number; i++)
	{
		if (number % i == 0) return false;
	}
	return true;
}

bool IsPrime1(int number)
{
	if (number == 1) return false;

	for (int i = 2; i * i < number; i++)
	{
		if (number % i == 0) return false;
	}
	return true;
}

vector<int> PrimeList(int number)
{
	vector<int> list;
	for (int i = 1; i <= number; i++)
	{
		if (IsPrime1(i) == true) list.push_back(i);
	}

	return list;
}

vector<int> Sieve(int number)
{
	vector<int> primes;
	vector<bool> visit(number + 1, true); // 인덱스이므로 number + 1 해주기

	for (int i = 2; i * i <= number; i++)
	{
		if (visit[i] == false) continue; // 만약 이미 방문했다면(소수가 아니면) 건너뛰기

		for (int j = i * i; j <= number; j += i) // 3인 경우 배수인 6부터 시작함
		{
			visit[j] = false;
		}
	}

	for (int i = 2; i <= number; i++)
	{
		if (visit[i] == true) primes.push_back(i);
	}

	return primes;
}

vector<int> Divisor(int num)
{
	vector<int> list;

	for (int i = 1; i * i <= num; i++)
	{
		if (num % i == 0) // i로 나누어 떨어지는 경우
		{
			if (num / i == i) // i * i가 num인 경우
			{
				list.push_back(i);
			}
			else
			{
				list.push_back(i);
				list.push_back(num / i);
			}
		}
	}

	return list;
}

vector<int> Divisor1(int num)
{
	vector<int> list;

	for (int i = 1; i * i <= num; i++)
	{
		if (num % i == 0) // i로 나누어 떨어지는 경우
		{
			list.push_back(i);
		}
	}

	int listSize = (int)list.size() - 1; // size가 0인 경우 오버플로우난다.
	for (int j = listSize; j >= 0; j--)
	{
		if (list[j] * list[j] == num) continue;
		list.push_back(num / list[j]);
		
	}

	return list;
}

int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

int LCM(int a, int b)
{
	return a / GCD(b, a % b) * b;
}

int main()
{
	int number1, number2;
	cin >> number1 >> number2;

	/*vector<int> list = Divisor1(number);
	for (auto i: list)
	{
		cout << i << " ";
	}*/

	//int a = GCD(number1, number2);
	//cout << a;

	int a = LCM(number1, number2);
	cout << a;

	return 0;
}