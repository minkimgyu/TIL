#include <iostream>
using namespace std;

int main()
{
	while (1)
	{
		char line[10];
		cin.getline(line, 10);

		if (line[0] == 'e' && line[1] == 'n' && line[2] == 'd')
		{
			return 0;
		}

		char item[3] = { 'X', 'O', '.'};

		int xCnt = 0;
		int oCnt = 0;
		int dotCnt = 0;

		for (int i = 0; i < 10; i++)
		{
			if (line[i] == item[0]) xCnt++;
			else if (line[i] == item[1]) oCnt++;
			else if (line[i] == item[2]) dotCnt++;
		}

		if (xCnt - 1 > oCnt || xCnt < oCnt)
		{
			cout << "invalid" << '\n';
			continue;
		}

		int xClear = 0;
		int oClear = 0;

		int totalClear = 0;

		bool isCross = false;

		for (int i = 0; i < 2; i++)
		{
			int* p = nullptr;

			if (i == 0) p = &xClear;
			else if (i == 1) p = &oClear;


			if (line[0] == item[i] &&
				line[2] == item[i] &&
				line[4] == item[i] &&
				line[6] == item[i] &&
				line[8] == item[i])
			{
				isCross = true;
				break;
			}
			else
			{
				if (line[0] == item[i] &&
					line[4] == item[i] &&
					line[8] == item[i]) *p += 1;

				if (line[2] == item[i] &&
					line[4] == item[i] &&
					line[6] == item[i]) *p += 1;
			}


			if (line[0] == item[i] &&
				line[1] == item[i] &&
				line[2] == item[i]) *p += 1;

			if (line[3] == item[i] &&
				line[4] == item[i] &&
				line[5] == item[i]) *p += 1;

			if (line[6] == item[i] &&
				line[7] == item[i] &&
				line[8] == item[i]) *p += 1;



			if (line[0] == item[i] &&
				line[3] == item[i] &&
				line[6] == item[i]) *p += 1;

			if (line[1] == item[i] &&
				line[4] == item[i] &&
				line[7] == item[i]) *p += 1;

			if (line[2] == item[i] &&
				line[5] == item[i] &&
				line[8] == item[i]) *p += 1;
		}

		totalClear = oClear + xClear;

		if (isCross == true)
		{
			cout << "valid" << '\n';
			continue;
		}

		if (oClear > 0 && xCnt > oCnt)
		{
			cout << "invalid" << '\n';
			continue;
		}

		if (xClear > 0 && xCnt == oCnt)
		{
			cout << "invalid" << '\n';
			continue;
		}

		if (dotCnt == 0 && xCnt == 5 && oCnt == 4)
		{
			cout << "valid" << '\n';
			continue;
		}

		if (totalClear == 0 || totalClear > 1)
		{
			cout << "invalid" << '\n';
			continue;
		}

		cout << "valid" << '\n';
	}
}