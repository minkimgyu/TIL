#include <iostream>
#include <algorithm>
using namespace std;

class PickUp
{
public:
	int paperScore;
	int interviewScore;
};

//void Swap(PickUp* arr, int i, int j)
//{
//	PickUp tmp = arr[i];
//	arr[i] = arr[j];
//	arr[j] = tmp;
//}
//
//int Partition(PickUp* arr, int start, int end)
//{
//	int pivot = arr[end].paperScore;
//	int index = start;
//	for (int j = start; j < end; j++)
//	{
//		if (arr[j].paperScore < pivot)
//		{
//			Swap(arr, index, j);
//			index++;
//		}
//	}
//
//	Swap(arr, index, end);
//
//	return index;
//}
//
//void QuickSort(PickUp* arr, int start, int end)
//{
//	if (start >= end) return;
//
//	int index = Partition(arr, start, end);
//	QuickSort(arr, start, index - 1);
//	QuickSort(arr, index + 1, end);
//}

bool compare(PickUp a, PickUp b)
{
	return a.paperScore < b.paperScore;
}

// 다 맞았는데 Quick Sort보다 sort가 훨씬 빠름
// 혹시 Quick Sort로 정렬해서 풀었는데 안 풀리면 sort 사용해보는 것도 좋은듯
// 재귀를 사용하기도 했고 Quick Sort의 경우 모든 원소가 같거나 이미 정렬되어 있는 경우 O(N^2)이기 때문에 그런 것 같음

// https://justicehui.github.io/medium-algorithm/2019/03/24/IntroSort/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	int* maxPeopleCnt = new int[cnt];

	for (int i = 0; i < cnt; i++)
	{
		int peopleCnt;
		cin >> peopleCnt;

		PickUp* arr = new PickUp[peopleCnt];
		for (int j = 0; j < peopleCnt; j++)
		{
			cin >> arr[j].paperScore >> arr[j].interviewScore;
		}

		sort(arr, arr + peopleCnt, compare);

		//QuickSort(arr, 0, peopleCnt - 1);

		int min = 0;
		int maxPeopleInCase = peopleCnt;
		for (int k = 0; k < peopleCnt; k++)
		{
			if (k == 0) min = arr[k].interviewScore;
			else
			{
				if (min > arr[k].interviewScore)
				{
					min = arr[k].interviewScore;
				}
				else if (min < arr[k].interviewScore) // 제외되는 경우
				{
					maxPeopleInCase -= 1;
				}
			}
		}
		
		maxPeopleCnt[i] = maxPeopleInCase;
	}

	for (int i = 0; i < cnt; i++)
	{
		if (i == cnt - 1) cout << maxPeopleCnt[i];
		else cout << maxPeopleCnt[i] << '\n';
	}

	return 0;
}