#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

struct Point
{
public:
	bool lightOn = false;

	bool turnOn = false;
	vector<pair<int, int>> switches;
};

const int mapSize = 101;
Point map[mapSize][mapSize];
int visit[mapSize][mapSize]; // bfs�� ���� ������ 1�� �÷��� ���� �湮�� ���̸� �д�.

const int offsetSize = 4;
pair<int, int> offsets[offsetSize] =
{
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1},
};

int bfs()
{
	queue<pair<int, int>> lightOnQueue;
	lightOnQueue.push({ 1, 1 });
	map[1][1].lightOn = true;

	int loopCnt = 0;
	int lightOnRoomCount = 1;

	while (lightOnQueue.empty() == false)
	{
		loopCnt++;
		queue<pair<int, int>> visitQueue;

		int lightOnQueueSize = lightOnQueue.size();
		for (int i = 0; i < lightOnQueueSize; i++)
		{
			pair<int, int> front = lightOnQueue.front();
			lightOnQueue.pop();

			visitQueue.push(front);
			visit[front.second][front.first] = loopCnt;

			map[front.second][front.first].turnOn = true; // �״ٴ� üũ�� ���ش�.
			int switchSize = map[front.second][front.first].switches.size();

			for (int j = 0; j < switchSize; j++)
			{
				pair<int, int> switchPos = map[front.second][front.first].switches.back();
				map[front.second][front.first].switches.pop_back();

				if (map[switchPos.second][switchPos.first].lightOn == true) continue;
				map[switchPos.second][switchPos.first].lightOn = true; // ����ġ�� �Ѽ� �濡 ���� �÷��ְ�
				lightOnRoomCount += 1;
			}
		}

		while (visitQueue.empty() == false)
		{
			pair<int, int> front = visitQueue.front();
			visitQueue.pop();

			for (int i = 0; i < offsetSize; i++)
			{
				int x = front.first + offsets[i].first;
				int y = front.second + offsets[i].second;

				if (x < 1 || x > n || y < 1 || y > n) continue;
				if (map[y][x].lightOn == false) continue;
				if (visit[y][x] == loopCnt) continue;

				int switchSize = map[y][x].switches.size();
				if (switchSize > 0) lightOnQueue.push({ x, y }); // ����ġ�� �ְ� ������ �Ѻ��� �ʾҴٸ� ť�� �־��ش�.

				visit[y][x] = loopCnt;
				visitQueue.push({ x, y });
			}
		}
	}

	return lightOnRoomCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		map[y][x].switches.push_back({ a, b });
	}

	cout << bfs();

	return 0;
}