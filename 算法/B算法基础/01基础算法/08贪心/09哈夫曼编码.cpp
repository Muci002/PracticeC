// NC233601

#include <iostream>
#include <queue>

using namespace std;
typedef long long LL;

priority_queue<LL, vector<LL>, greater<LL>> heap;

int main()
{
    int n = 0; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x = 0; cin >> x;
        heap.push(x);
    }
    
    LL ret = 0;
    while(heap.size() > 1)
    {
        LL x = heap.top(); heap.pop();
        LL y = heap.top(); heap.pop();
        ret += x + y;
        heap.push(x + y);
    }
    
    cout << ret;
    return 0;
}