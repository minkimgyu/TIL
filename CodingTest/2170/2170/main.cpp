#include <iostream>
#include <algorithm>
using namespace std;

struct Line
{
public:
	long long int _start, _end = 0;
};

bool compare(Line a, Line b)
{
	if (a._start < b._start) return true;
	else if (a._start == b._start && a._end < b._end) return true;

	return false;
}

// 초기 접근법이 맞다.
// 틀린 이유는 어이 없이 

//if (n - 1 == i)
//{
//	long long int length = tmpLine->_end - tmpLine->_start;
//	sum += length; // 길이 구해주기
//}

// 이거를 빼먹음 ㅋㅋㅋㅋ
// 집가고 싶다....

// 정렬해서 겹치는 경우, 맞물리는 경우 길이를 업데이트 해주고
// 겹치지 않는 경우는 앞선 길이를 더해주는 방식으로 접근

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	Line* lines = new Line[n];

	for (int i = 0; i < n; i++)
	{
		cin >> lines[i]._start >> lines[i]._end;
	}

	sort(lines, lines + n, compare);

	long long int sum = 0;
	Line* tmpLine = nullptr;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			tmpLine = &lines[i];
			if (n - 1 == i)
			{
				long long int length = tmpLine->_end - tmpLine->_start;
				sum += length; // 길이 구해주기
			}
			continue;
		}

		// 겹치는 경우 or 맞물리는 경우
		if ((tmpLine->_start <= lines[i]._start && lines[i]._start < tmpLine->_end && tmpLine->_end <= lines[i]._end)
			|| tmpLine->_end == lines[i]._start)
		{
			tmpLine->_end = lines[i]._end;
		}
		else if (tmpLine->_end < lines[i]._start)
		{
			long long int length = tmpLine->_end - tmpLine->_start;
			sum += length; // 길이 구해주기

			tmpLine = &lines[i]; // 새롭게 라인 할당해주기
		}

		if (n - 1 == i)
		{
			long long int length = tmpLine->_end - tmpLine->_start;
			sum += length; // 길이 구해주기
		}
	}

	cout << sum;

	return 0;
}