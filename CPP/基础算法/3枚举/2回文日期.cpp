//洛谷P2010
#include <iostream>
#include <string>
using namespace std;

//枚举对象
int day[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{

	int x = 0, y = 0;
	cin >> x >> y;
	int num = 0, cnt = 0;
	for(int i = 1; i <= 12; i++)
	{
		for(int j = 0; j <= day[i]; j++)
		{
			num = j % 10 * 1000 + j / 10 * 100 + i % 10 * 10 + i / 10;
			num = num * 10000 + i * 100 + j; 
			if(num >= x && num <= y) cnt++;
		}
		
	}
	
	cout << cnt;
	
	return 0;
}
