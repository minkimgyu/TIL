#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int inputCount = 100;
	const int maxInputLength = 101;
	
	/*for (int i = 0; i < inputCount; i++)
	{
		char* arr = new char[maxInputLength];
		cin.getline(arr, maxInputLength);
		cout << arr << '\n';

		delete[] arr;
	}*/

	// EOF를 사용한 풀이도 가능하다
	while (true) {
		char* arr = new char[maxInputLength];
		cin.getline(arr, maxInputLength);

		if (cin.eof()) break; // Ctrl + Z가 EOF임

		cout << arr << "\n";

		delete[] arr;
	}

	return 0;
}