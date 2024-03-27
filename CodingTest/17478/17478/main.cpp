#include <iostream>
#include <vector>
using namespace std;

void PrintLine(vector<const char*>arrs, int index, int count)
{
	count--;
	for (int i = 0; i < count * 4; i++) cout << "_";
	cout << arrs[index];
}

void Print(vector<const char*>arrs, int count, int maxCount)
{
	if (maxCount < count) return;

	int size = arrs.size();

	if (maxCount == count)
	{
		PrintLine(arrs, 0, count);
		cout << '\n';
		PrintLine(arrs, 4, count);
		cout << '\n';
	}
	else
	{
		for (int i = 0; i < size - 2; i++)
		{
			PrintLine(arrs, i, count);
			cout << '\n';
		}

		Print(arrs, count + 1, maxCount);
	}

	PrintLine(arrs, size - 1, count);

	if (count == 1) return;
	cout << '\n';
}

// �⺻���� ��͸� Ȱ���ϴ� ����
// ������

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';

	vector<const char*> arrs;

	arrs.push_back("\"����Լ��� ������?\"");
	arrs.push_back("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.");
	arrs.push_back("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.");
	arrs.push_back("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"");
	arrs.push_back("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"");
	arrs.push_back("��� �亯�Ͽ���.");

	Print(arrs, 1, n + 1);

	return 0;
}