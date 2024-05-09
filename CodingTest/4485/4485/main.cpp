#include <iostream>
#include <vector>
using namespace std;

const int offsetSize = 4;
pair<int, int> offset[offsetSize] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

struct Land
{
public:
	int _weight;
	pair<int, int> _pos;
};

vector<Land> ReturnCloseNode(Land land, int n, int** arr)
{
	vector<Land> closeLands;

	int currentWeight = land._weight;
	pair<int, int> currentPos = land._pos;

	for (int i = 0; i < offsetSize; i++)
	{
		Land land;
		pair<int, int> pos = { currentPos.first + offset[i].first, currentPos.second + offset[i].second };
		
		if (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= n) continue;
		
		land._pos = pos;
		land._weight = currentWeight + arr[pos.second][pos.first];

		closeLands.push_back(land);
	}

	return closeLands;
}

class MinHeap
{
public:
	void Insert(Land land)
	{
		_vec.push_back(land);
		int size = Size();
		PercolateUp(size - 1);
	}

	Land GetMin()
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
	int GetParentIndex(int index) { return (int)((index - 1) / 2); }

	int GetLeftChildIndex(int index) { return 2 * index + 1; }

	int GetRightChildIndex(int index) { return 2 * index + 2; }

	void Swap(int aIndex, int bIndex)
	{
		Land land = _vec[bIndex];
		_vec[bIndex] = _vec[aIndex];
		_vec[aIndex] = land;
	}

	void PercolateDown(int index)
	{
		int currentIndex = index;
		int childIndex = GetLeftChildIndex(currentIndex);
		int rightChildIndex = GetRightChildIndex(currentIndex);

		int size = Size();
		if (rightChildIndex < size && _vec[childIndex]._weight > _vec[rightChildIndex]._weight)
		{
			childIndex = rightChildIndex;
		}

		while (childIndex < size && _vec[currentIndex]._weight > _vec[childIndex]._weight)
		{
			Swap(currentIndex, childIndex);

			currentIndex = childIndex;
			childIndex = GetLeftChildIndex(currentIndex);
			rightChildIndex = GetRightChildIndex(currentIndex);

			if (rightChildIndex < size && _vec[childIndex]._weight > _vec[rightChildIndex]._weight)
			{
				childIndex = rightChildIndex;
			}
		}
	}

	void PercolateUp(int index)
	{
		int currentIndex = index;
		int parentIndex = GetParentIndex(currentIndex);

		while (parentIndex >= 0 && _vec[parentIndex]._weight > _vec[currentIndex]._weight)
		{
			Swap(currentIndex, parentIndex);

			currentIndex = parentIndex;
			parentIndex = GetParentIndex(currentIndex);
		}
	}

private:
	vector<Land> _vec;
};

// visit 필요 없음 --> 어차피 가장 작은 값을 우선해서 넣기 때문에
// https://www.acmicpc.net/board/view/136866
// 주변 노드를 넣을 때 거리 판단하고 넣어야함 --> 이건 수도 코드를 비슷한 내용임

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	const int size = 150;
	const int maxValue = 10000;
	vector<int> results;

	while (1)
	{
		int n;
		cin >> n;

		if (n == 0) break;

		int** arr = new int* [n];
		int** dp = new int* [n];

		for (int i = 0; i < n; i++)
		{
			arr[i] = new int[n];
			dp[i] = new int[n];

			for (int j = 0; j < n; j++)
			{
				int tmp;
				cin >> tmp;

				arr[i][j] = tmp;
				dp[i][j] = maxValue;
			}
		}

		MinHeap minHeap;

		Land land;
		land._pos = { 0, 0 };
		land._weight = arr[0][0];

		minHeap.Insert(land);

		while (minHeap.IsEmpty() == false)
		{
			Land top = minHeap.GetMin();
			minHeap.DeleteMin();

			vector<Land> closeLands = ReturnCloseNode(top, n, arr);
			int closeLandCnt = closeLands.size();
			for (int i = 0; i < closeLandCnt; i++)
			{
				int second = closeLands[i]._pos.second;
				int first = closeLands[i]._pos.first;

				if (dp[second][first] <= closeLands[i]._weight) continue;

				dp[second][first] = closeLands[i]._weight; // 여기서 값 업데이트 해주기
				minHeap.Insert(closeLands[i]);
			}
		}

		results.push_back(dp[n - 1][n - 1]);

		for (int i = 0; i < n; i++)
		{
			delete[] arr[i];
			delete[] dp[i];
		}
	}

	int resultSize = results.size();
	for (int i = 1; i <= resultSize; i++)
	{
		cout << "Problem " << i << ": " << results[i - 1];
		if (i != resultSize) cout << '\n';
	}

	return 0;
}