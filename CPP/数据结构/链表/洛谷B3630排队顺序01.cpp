#include <iostream>

using namespace std;

const int N = 1e6+10;
int ne[N], h;

int main()
{
    int n = 0; 
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> ne[i];
    }
    cin >> h;
    for(int i = h; i ; i = ne[i])
    {
        cout << i  << " ";
    }
    return 0;
}