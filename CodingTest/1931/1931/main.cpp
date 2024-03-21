#include <iostream>
#include <vector>
using namespace std;

class Meeting
{
public:
	Meeting(int startTime, int endTime)
	{
		_startTime = startTime;
		_endTime = endTime;
	}

public:
	int _startTime = 0;
	int _endTime = 0;

public:
	int ReturnDuration() { return _endTime - _startTime; }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<Meeting*> meetings;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;

		Meeting* nowMeeting = new Meeting(start, end);

		if(i == 0) meetings.push_back(nowMeeting);
		else
		{
			if (nowMeeting->_startTime == nowMeeting->_endTime)
			{
				meetings.push_back(nowMeeting);
			}
			else
			{
				bool canPush = true;
				int size = meetings.size();
				for (int i = 0; i < size; i++)
				{
					// 서로 겹치거나 포함되는 경우
					if ((meetings[i]->_startTime <= nowMeeting->_startTime && nowMeeting->_startTime < meetings[i]->_endTime && meetings[i]->_endTime <= nowMeeting->_endTime) ||
						(nowMeeting->_startTime <= meetings[i]->_startTime && meetings[i]->_startTime < nowMeeting->_endTime && nowMeeting->_endTime <= meetings[i]->_endTime) ||
						(nowMeeting->_startTime <= meetings[i]->_startTime && meetings[i]->_endTime <= nowMeeting->_endTime))
					{
						canPush = false;
					}

					if (meetings[i]->_startTime <= nowMeeting->_startTime && nowMeeting->_endTime <= meetings[i]->_endTime) //--> 안에 쏙 들어가는 경우임 -- 이거는 가능하다
					{
						meetings[i] = nowMeeting;
						canPush = false;
						break;
					}
				}

				if (canPush == true) meetings.push_back(nowMeeting);
			}
		}
	}

	int size = meetings.size();
	cout << size;

	for (int i = 0; i < size; i++)
	{
		delete meetings[i];
	}

	return 0;
}