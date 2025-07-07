//P5266 【深基17.例6】学籍管理

#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> mp;

int main()
{
	int n, op;
	string name;
	int score = 0;
	cin >> n;
	while (n--)
	{
		cin >> op;
		switch (op)
		{
		case 1:
			cin >> name>> score;
			mp[name] = score;
			cout << "OK" << endl;
			break;
		case 2:
			cin >> name;
			if (mp.find(name) == mp.end()) cout << "Not found" << endl;
			else cout << mp.find(name)->second << endl;
			break;
		case 3:
			cin >> name;
			if (mp.count(name))
			{
				mp.erase(name);
				cout << "Deleted successfully" << endl;
			}
			else cout << "Not found" << endl;
			break;
		case 4:
			cout << mp.size() << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}