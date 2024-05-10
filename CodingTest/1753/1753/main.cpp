#include <iostream>
#include <vector>
using namespace std;

struct Point
{
public:
	vector<pair<int, int>> _lines;
};

class MinHeap
{
public:
	void Insert(pair<int, int> item)
	{
		_vec.push_back(item);
		int size = Size();
		PercolateUp(size - 1);
	}

	pair<int, int> GetMin()
	{
		return _vec[0];
	}

	void DeleteMin()
	{
		int size = Size();
		_vec[0] = _vec[size - 1];
		_vec.pop_back();

		PercolateDown(0);
	}

	int Size()
	{
		return _vec.size();
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

private:
	int GetParentIndex(int index)
	{
		return (int)((index - 1) / 2);
	}

	int GetLeftChildIndex(int index)
	{
		return 2 * index + 1;
	}

	int GetRightChildIndex(int index)
	{
		return 2 * index + 2;
	}

	void PercolateUp(int index)
	{
		int currentIndex = index;
		int parentIndex = GetParentIndex(currentIndex);

		while (currentIndex >= 0 && _vec[currentIndex].first < _vec[parentIndex].first)
		{
			Swap(currentIndex, parentIndex);

			currentIndex = parentIndex;
			parentIndex = GetParentIndex(currentIndex);
		}
	}

	void PercolateDown(int index)
	{
		int currentIndex = index;
		int childIndex = GetLeftChildIndex(currentIndex);
		int rightChildIndex = GetRightChildIndex(currentIndex);

		int size = Size();
		if (rightChildIndex < size && _vec[rightChildIndex].first < _vec[childIndex].first)
		{
			childIndex = rightChildIndex;
		}

		while (childIndex < size && _vec[childIndex].first < _vec[currentIndex].first)
		{
			Swap(currentIndex, childIndex);

			currentIndex = childIndex;
			childIndex = GetLeftChildIndex(currentIndex);
			rightChildIndex = GetRightChildIndex(currentIndex);

			if (rightChildIndex < size && _vec[rightChildIndex].first < _vec[childIndex].first)
			{
				childIndex = rightChildIndex;
			}
		}
	}

	void Swap(int aIndex, int bIndex)
	{
		pair<int, int> a = _vec[aIndex];
		_vec[aIndex] = _vec[bIndex];
		_vec[bIndex] = a;
	}

private:
	vector<pair<int, int>> _vec;
};

void AddPoints(Point* points, int start, int startWeight, MinHeap* minHeap, int* dp)
{
	Point startPoint = points[start];
	int startCloseSize = startPoint._lines.size();
	for (int i = 0; i < startCloseSize; i++)
	{
		int weight = startPoint._lines[i].first + startWeight;
		int end = startPoint._lines[i].second;

		if (dp[end - 1] <= weight) continue;

		minHeap->Insert({ weight , end });
	}
}

// maxWeight를 11로 놔서 틀림...
// 가중치를 더하면서 11 이상이 나올 수 있기 때문에
// maxWeight를 2100000000정도로 지정해줘야 한다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	int start;
	cin >> start;
	
	const int maxWeight = 2100000000;
	int* dp = new int[v];
	for (int i = 0; i < v; i++)
	{
		dp[i] = maxWeight;
	}

	Point* points = new Point[v];
	for (int i = 0; i < e; i++)
	{
		int start, end, weight;
		cin >> start >> end >> weight;

		pair<int, int> line = { weight, end };
		points[start - 1]._lines.push_back(line);
	}

	MinHeap minHeap;

	dp[start - 1] = 0;
	AddPoints(points, start - 1, dp[start - 1], &minHeap, dp);

	while (minHeap.IsEmpty() == false)
	{
		pair<int, int> line = minHeap.GetMin();
		minHeap.DeleteMin();

		int index = line.second - 1;
		int weight = line.first;

		if (dp[index] <= weight) continue;
		dp[index] = weight;

		AddPoints(points, index, dp[index], &minHeap, dp);
	}

	for (int i = 0; i < v; i++)
	{
		if (dp[i] == maxWeight)
		{
			cout << "INF";
		}
		else
		{
			cout << dp[i];
		}

		if(i != v - 1) cout << '\n';
	}

	return 0;
}