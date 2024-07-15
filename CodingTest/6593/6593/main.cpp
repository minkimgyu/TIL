#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int l, r, c;

struct Vector3
{
	int x, y, z;
};

const int offsetSize = 6;
Vector3 offset[offsetSize]
{
	{1, 0, 0},
	{-1, 0, 0},
	{0, 1, 0},
	{0, -1, 0},
	{0, 0, 1},
	{0, 0, -1},
};

vector<Vector3> ReturnClosePoints(Vector3 pos)
{
	vector<Vector3> points;

	for (int i = 0; i < offsetSize; i++)
	{
		Vector3 point = { pos.x + offset[i].x, pos.y + offset[i].y, pos.z + offset[i].z };

		if (point.x < 0 || point.x >= c || point.y < 0 || point.y >= r || point.z < 0 || point.z >= l) continue;

		points.push_back(point);
	}

	return points;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		int arr[30][30][30];
		cin >> l >> r >> c;
		cin.ignore();

		if (l == 0 && r == 0 && c == 0) break;

		queue<Vector3> queue;

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				char* line = new char[c + 1];
				cin.getline(line, c + 1);

				for (int k = 0; k < c; k++)
				{
					if (line[k] == 'S')
					{
						Vector3 start = { k, j, i };
						queue.push(start);

						arr[i][j][k] = -2;
					}
					else if (line[k] == 'E')
					{
						arr[i][j][k] = -3;
					}
					else if (line[k] == '.')
					{
						arr[i][j][k] = 0;
					}
					else if (line[k] == '#')
					{
						arr[i][j][k] = -1;
					}
				}

				delete[] line;
			}

			cin.ignore();
		}

		int time = 0;
		bool canExit = false;

		while (queue.empty() == false)
		{
			int queueSize = queue.size();
			for (int i = 0; i < queueSize; i++)
			{
				Vector3 item = queue.front();
				queue.pop();

				vector<Vector3> closePoints =  ReturnClosePoints(item);
				for (int i = 0; i < closePoints.size(); i++)
				{
					Vector3 point = closePoints[i];
					int item = arr[point.z][point.y][point.x];

					if (item == -1 || item == -2) continue;
					else if (item == -3)
					{
						canExit = true;
						break;
					}
					else
					{
						arr[point.z][point.y][point.x] = -1;
					}

					queue.push(point);
				}

				if (canExit) break;
			}

			time++;
			if (canExit) break;
		}

		if (canExit == true) cout << "Escaped in " << time << " minute(s)." << '\n';
		else cout << "Trapped!" << '\n';
	}

	return 0;
}