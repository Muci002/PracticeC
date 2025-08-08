//力扣88
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        //解法一：利用辅助数组
        vector<int> nums3(m + n);
        int cur1 = 0, cur2 = 0, cur3 = 0;
        while (cur1 < m && cur2 < n)
        {
            if (nums1[cur1] <= nums2[cur2]) nums3[cur3++] = nums1[cur1++];
            else nums3[cur3++] = nums2[cur2++];
        }
       
        while(cur1 < m) nums3[cur3++] = nums1[cur1++];
        while(cur2 < n) nums3[cur3++] = nums2[cur2++];

        for (int i = 0; i < n + m; i++)
        {
            nums1[i] = nums3[i];
        }


        //解法2：原地合并,从后往前放
        /*int cur = m + n - 1, cur1 = m - 1, cur2 = n - 1;
        while (cur1 >= 0 && cur2 >= 0)
        {
            if (nums1[cur1] >= nums2[cur2]) nums1[cur--] = nums1[cur1--];
            else nums1[cur--] = nums2[cur2--];
        }
        while (cur2 >= 0) nums1[cur--] = nums2[cur2--];*/
    }
};

int main()
{
    class Solution s;
    vector<int> nums1 = { 1,2,3,0,0,0 };
    vector<int> nums2 = { 2,5,6 };
    s.merge(nums1, 3, nums2, 3);


	return 0;
}