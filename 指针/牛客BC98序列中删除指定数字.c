#include <stdio.h>

#define N 55
int arr[N],id;

//尾插
void push_back(int x)
{
	arr[++id] = x;
}

//删除
void del(int x)
{
	for(int i = 1; i <= id; )
	{
		if (arr[i] == x)
		{
			
			int j = i;
			while (j <= id)
			{
				arr[j]  = arr[j + 1];
				j++;
			}
			id--;
		}
		if (arr[i] != x)
		{
			i++;
		}
	}
	
	
}

//打印
void print()
{
	for (int i = 1; i<= id; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int x = 0;
	while (n--)
	{
		
		scanf("%d", &x);
		push_back(x);
	}
	scanf("%d", &x);                                
	del(x);
	print();
	return 0;
}