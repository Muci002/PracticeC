//洛谷P5731
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n = 0; cin >> n;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int arr[11][11] = {0};
	int x = 1, y = 1, i = 0;
	//处理首元素
	//cin >> a; arr[x][y] = a; 
	for(int j = 1; j <= n*n; j++)
	{
		
		arr[x][y] = j;
		int nx = x + dx[i], ny = y +dy[i];
		if( ny > n || nx > n || ny < 1 || nx < 1 || arr[nx][ny] != 0)
		{
//			if(i = 3) i = (i+1)%4;
//			else i+=1;
			i = (i+1)%4;
			//nx = x + dx[i]; ny = y +dy[i];
		}
	//	x = nx; y = ny;
	x += dx[i]; y += dy[i];
		
	}
	for( x = 1; x <= n; x++ )
	{
		for( y = 1; y <= n; y++)
		{
			printf("%3d", arr[x][y]);
		}
		cout <<endl;
	}
	return 0;
}