#include <iostream>
#include <vector>

using namespace std;

void rearrange(vector<int>& arr) 
{
    int leftIndex = 0;
    int rightIndex = arr.size() - 1;
    int swapCount = 0;

    while (leftIndex < rightIndex) {
        while (arr[rightIndex] % 2 == 1 && leftIndex < rightIndex) {
            rightIndex--;
        }

        while (arr[leftIndex] % 2 == 0 && leftIndex < rightIndex) {
            leftIndex++;
        }

        if (leftIndex < rightIndex) {
            swap(arr[leftIndex], arr[rightIndex]);
            swapCount++;
        }
    }

    return swapCount;
}

int main() {
    vector<int> arr = { 8, 1, 4, 7 };

    rearrange(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}