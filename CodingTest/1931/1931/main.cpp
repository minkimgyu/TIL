#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Meeting
{
public:
	float _startTime;
	float _endTime;

	float ReturnDuration() { return _endTime - _startTime; }

	bool IsBetweenTime(Meeting meeting)
	{
		if (this->_startTime <= meeting._startTime
			&& meeting._endTime <= this->_endTime) return true;

		return false;
	}

	bool IsOutOfBoundary(Meeting meeting)
	{
		if(this->_endTime <= meeting._startTime) return true;

		return false;
	}
};

bool compare(Meeting a1, Meeting a2)
{
	/*if(a1._startTime == a2._startTime)
		return a1._endTime < a2._endTime;*/

	return a1._startTime < a2._startTime;
}

//void Swap(Meeting* arr, int i, int j)
//{
//	Meeting tmp = arr[i];
//	arr[i] = arr[j];
//	arr[j] = tmp;
//}
//
//int Partition(Meeting* arr, int start, int end)
//{
//	int pivot = arr[end]._startTime;
//	int index = start;
//	for (int j = start; j < end; j++)
//	{
//		if (arr[j]._startTime < pivot)
//		{
//			Swap(arr, index, j);
//			index++;
//		}
//	}
//
//	Swap(arr, index, end);
//	return index;
//}
//
//
//void QuickSort(Meeting* arr, int start, int end)
//{
//	if (start >= end) return;
//
//	int index = Partition(arr, start, end);
//	QuickSort(arr, start, index - 1);
//	QuickSort(arr, index + 1, end);
//}

// 시작 시간을 기준으로 정렬해주고 끝나는 시간을 기준으로 문제를 해결해야한다.
// 기간이 안에 들어가거나 겹치거나 벗어나는 3가지 경우가 존재하는데
// 들어가는 경우는 대체해주고 겹치는 경우는 무시한다.
// 무시하는 이유는 기존 값으로 더 많은 경우를 창출할 수 있기 때문임
// 
// 벗어나는 경우는 +1 해주자
// 추가적으로 기간이 0 0이라서 겹치는 경우도 있는데 이 때는 +1 해주면 된다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	Meeting* meetings = new Meeting[n];

	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;

		meetings[i]._startTime = start;
		meetings[i]._endTime = end;
	}

	//QuickSort(meetings, 0, n - 1);

	sort(meetings, meetings + n, compare);

	int meetingCount = 0;
	Meeting beforeMeetings;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			beforeMeetings = meetings[i];
			meetingCount++;
		}
		else
		{
			bool nowBetween = beforeMeetings.IsBetweenTime(meetings[i]);
			if (nowBetween == true)
			{

				// Duration이 0이면서 사이에 들어가 있는 경우는 교체해야한다고 생각하자

				// 끝에 붙어있는 경우임
				if((beforeMeetings.ReturnDuration() == 0 ||
					meetings[i].ReturnDuration() == 0)
					&& (beforeMeetings._startTime == meetings[i]._startTime
					|| beforeMeetings._endTime == meetings[i]._endTime))
					meetingCount++;

				beforeMeetings = meetings[i];
				continue;
			}

			bool nowOutOfBoundary = beforeMeetings.IsOutOfBoundary(meetings[i]);
			if (nowOutOfBoundary == true)
			{
				beforeMeetings = meetings[i];
				meetingCount++;
			}
		}
	}

	cout << meetingCount;

	// 정렬 후 겹치면서 회의 시간이 더 적은 값을 골라서 대체한다.

	return 0;
}