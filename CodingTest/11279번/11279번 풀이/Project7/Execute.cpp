#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
private:
	vector<int> vec;

public:
	int length() { return vec.size(); }

	void printHeap()
	{
		for (int i = 0; i < length(); i++)
		{
			cout << vec[i] << " ";
		}
	}

	void buildHeap()
	{
		int tmpSize = (length() - 2) / 2;
		for (int i = tmpSize; i >= 0; i--)
		{
			down(i);
		}
	}

	int deleteMin()
	{
		int returnItem = vec[0];
		vec[0] = vec[length() - 1];
		vector<int>::iterator iter = --vec.end();
		vec.erase(iter);
		down(0);

		return returnItem;
	}

	void insert(int item)
	{
		vec.push_back(item);
		up(length() - 1);
	}

	void up(int index)
	{
		int upIndex = (index - 1) / 2; // 계산 시 [(i - 1) / 2] 적용
		if (index > 0 && abs(vec[upIndex]) > abs(vec[index]))
		{
			int tmp = vec[upIndex];
			vec[upIndex] = vec[index];
			vec[index] = tmp;
			up(upIndex);
		}
		else if (index > 0 && abs(vec[upIndex]) == abs(vec[index]))
		{
			if (vec[upIndex] > vec[index])
			{
				int tmp = vec[upIndex];
				vec[upIndex] = vec[index];
				vec[index] = tmp;
				up(upIndex);
			}
		}
	}

	void down(int index)
	{
		int leftIndex = 2 * index + 1;
		int rightIndex = 2 * index + 2;

		if (leftIndex < this->length())
		{
			if (rightIndex < this->length() && abs(vec[leftIndex]) > abs(vec[rightIndex])) leftIndex = rightIndex;
			else if (rightIndex < this->length() && abs(vec[leftIndex]) == abs(vec[rightIndex]))
			{
				if (vec[leftIndex] > vec[rightIndex])
				{
					leftIndex = rightIndex;
				}
			}

			if (abs(vec[index]) > abs(vec[leftIndex])) // 위의 if문과 따로 적용
			{
				int tmp = vec[leftIndex];
				vec[leftIndex] = vec[index];
				vec[index] = tmp;
				down(leftIndex);
			}
			else if (abs(vec[index]) == abs(vec[leftIndex])) // 위의 if문과 따로 적용
			{
				if (vec[index] > vec[leftIndex])
				{
					int tmp = vec[leftIndex];
					vec[leftIndex] = vec[index];
					vec[index] = tmp;
					down(leftIndex);
				}
			}
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); // 꼭 붙여주기

	PriorityQueue queue;
	int count;

	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int tmp;
		cin >> tmp;

		if (tmp == 0)
		{
			if (queue.length() == tmp) cout << tmp << '\n';
			else
			{
				int min = queue.deleteMin();
				cout << min << '\n';
			}
		}
		else
		{
			queue.insert(tmp);
		}
	}

	return 0;
}