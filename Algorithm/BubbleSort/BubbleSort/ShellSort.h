#pragma once

void InsertionSortStep(int* arr, int start, int end, int gap);

void ShellSort(int* arr, int size)
{
	// 1 --> 3 --> 5 이런 식으로 돌려줘야함, 
	int gap = (int)(size / 2); // 초기 값은 gap / 2

	while (gap >= 1)
	{
		for (int i = 0; i < gap; i++)
		{
			InsertionSortStep(arr, i, size, gap);
		}

		gap = (int)(gap / 2);
		if (gap != 0 && gap % 2 == 0) gap++;
	}
}

void InsertionSortStep(int* arr, int start, int size, int gap)
{
	for (int i = start + gap; i < size; i += gap) // i를 key의 인덱스에 맞춰서 진행하는게 좋음 --> 그래야 인덱스를 넘지 않는다.
	{
		int key = arr[i];
		int j = i - gap;
		while (j >= start && arr[j] > key) // j가 0과 같거나 더 크고 arr[j]가 처음 선정한 key 값보다 큰 경우
		{
			arr[j + gap] = arr[j];
			j -= gap;
		}
		arr[j + gap] = key;
	}
}

// Shell sort
// 입력 자료를 일정한 간격(interval 또는 gap)에 의해 여러 개의 부분 집합
// 으로 나눈 다음, 각 부분 집합에 대해 삽입 정렬을 수행하여 전체 자료를 정렬.

// 삽입정렬의 단점이 될 수 있는 이동 횟수를 적게 하여 효율을 높임

// 삽입 정렬은 요소들이 이웃한 위치로만 이동하므로, n이 큰 경우 제 자리를 찾기
// 위해서는 많은 수를 이동해야 함.따라서, 요소들이 멀리 떨어진 위치로(한번에)
// 이동할 수 있게 하면 보다 적은 수의 이동으로 제 자리를 찾을 수 있음

// 셸 정렬의 장점
// 불연속적인 부분 리스트에서 원거리 자료 이동으로 보다 적은 위치교환으로 제자리 찾을 가능성 증대
// 부분 리스트가 점진적으로 정렬된 상태가 되므로 삽입정렬 속도 증가

// 간격이 홀수일 때, 서로 배수가 되지 않는 요소들끼리 비교 및 이동을 하게 되어 정렬 알고리즘의 효율성을 높일 수 있습니다.

// 시간적 복잡도
// 최악의 경우 O(n^2)
// Gap sequence 구현에 따라 다름; 평균적인 경우 O(n^1.5) 또는 O(nlog2n)

// Stable: No --> 간격에 따라서 이동하기 때문에 유지되지 않을 수도 있음
// In-place: Yes
// 쉘 정렬의 가장 큰 장점: 타 정렬 알고리즘에 비해 빠르다. 많을 수록 삽입 정렬에 비해 빠르다.