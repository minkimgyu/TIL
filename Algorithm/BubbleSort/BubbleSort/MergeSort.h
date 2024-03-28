#pragma once

void Merge(int* arr, int size, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;

	int* sortedArr = new int[size] { 0 };

	while (i <= mid && j <= right) //  arr[i]와 arr[j] 중 작은 값을 배열에 넣어줌
	{
		if (arr[i] < arr[j])
		{
			sortedArr[k] = arr[i];
			i++;
		}
		else
		{
			sortedArr[k] = arr[j];
			j++;
		}
		k++;
	}

	// 남은 값을 전부 넣어준다.

	while (j <= right)
	{
		sortedArr[k] = arr[j];
		j++;
		k++;
	}

	while (i <= mid)
	{
		sortedArr[k] = arr[i];
		i++;
		k++;
	}

	i = left;
	while (i <= right)
	{
		arr[i] = sortedArr[i];
		i++;
	}
}

void MergeSort(int* arr, int size, int left, int right)
{
	int mid = (int)((left + right) / 2);

	if (left >= right) return; // 같아지는 순간 2개로 나누어지지 않음 --> 1개와 1개까지 나누어짐

	MergeSort(arr, size, 0, mid);
	MergeSort(arr, size, mid + 1, right);
	Merge(arr, size, left, mid, right); // left와 right가 같아지기 바로 전까지 순회함
}

// Merge sort
// □ 비교 횟수
// 크기 n인 리스트를 정확히 균등 분배하므로 log(n) 개의 패스(순환 호출)
// 각 패스에서 리스트의 모든 레코드 n개를 비교하므로 n번의 비교 연산
// 
// □ 이동 횟수(추가 메모리 사용)
// 레코드의 이동이 각 패스에서 2n번 발생하므로 전체 레코드의 이동은 2n * log(n)번 발생
// 레코드의 크기가 큰 경우에는 매우 큰 시간적 낭비 초래
// 레코드를 연결 리스트로 구성하여 합병 정렬할 경우, 효율적
// 
//□ 최적, 평균, 최악의 경우, 모두 O(nlogn)의 시간 복잡도
// 
//□ In - place: No
// 
//□ Stable: No
