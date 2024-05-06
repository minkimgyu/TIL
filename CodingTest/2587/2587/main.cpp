#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    const int size = 5;
    int arr[5];

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << sum / size;
    sort(arr, arr + size);
    cout << '\n';
    cout << arr[2];


    return 0;
}
