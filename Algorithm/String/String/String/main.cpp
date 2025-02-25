#include <iostream>
#include <vector>
#include <string>
using namespace std;

void basic()
{
	string s = "hello";
	s += " BKD!"; // hello BKD!
	cout<<s.size() << '\n'; // 10 
	
	cout << s.substr(2, 3) << '\n'; // llo 
	cout << s[1] << '\n'; // e

	s.replace(6, 4, "guys"); // hello guys 
	cout << s << '\n';

	int it = s.find("guys"); // 6
	s.replace(it, 4, "everyone"); // hello everyone 
	cout << s << '\n';

	s.erase(7, 6); // hello ee
	cout << s << '\n';

	s[6] = 'm'; // hello me
	cout << s << '\n';

	s.insert(0, "say ");// say hello me
	cout << s << '\n';

	if (s.find("to") == string::npos) // string::npos == -1
		cout << "'to' is not in string 's'\n";
}

vector<string> split(string& s, string& sep)
{
	vector<string> ret;
	int pos = 0;

	while (pos < s.size())
	{
		int nxt = s.find(sep, pos);

		if (nxt == string::npos)
		{
			ret.push_back(s.substr(pos, s.size() - pos));
			pos = s.size();
		}
		else
		{
			ret.push_back(s.substr(pos, nxt - pos));
			pos = nxt + sep.size();
		}
	}

	return ret;
}

void split_test()
{
	string s1 = "welcome to the black parade";
	string sep1 = " ";

	vector<string> chunks1 = split(s1, sep1); //welcome/to/the/black/parade/
	for (auto chunk : chunks1) cout << chunk << '/'; cout << '\n';

	string s2 = "b*!*ac*!**!*e* ! *y* ! *";
	string sep2 = "*!*";

	vector<string> chunks2 = split(s2, sep2);
	// b/ac/a/y/
	for (auto chunk : chunks2) cout << chunk << '/';
}

int main() 
{
	string s;
	for (int i = 0; i < 1000000; i++) 
		s = s + 'a';
}