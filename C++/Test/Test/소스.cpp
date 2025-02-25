//#include <iostream>
//using namespace std;
//
//void Change(int* item)
//{
//	*item = 3;
//}
//
//int main()
//{
//	int number = 5;
//
//	cout << number;
//	cout << '\n';
//	Change(&number);
//	cout << number;
//	return 0;
//}

#include <iostream>
using namespace std;

int main() {
	int a = 3;
	int& another_a = a;

	another_a = 5;

	cout << "a : " << a << '\n';
	cout << "another_a : " << another_a << '\n';
	return 0;
}