// 力扣 34

class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if(nums.empty()) return {-1, -1};
        int left = 0, right = nums.size() - 1;
        // 查找左端点
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        if(nums[left] != target) return {-1,-1};
        int x = left;
        // 查找右端点
        left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = (left + right + 1) / 2;
            if(nums[mid] <= target) left = mid;
            else right = mid - 1; 
        }
        int y = left;
        return {x,y};
    }
};


// 使用slt
#include <algorithm>
class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if(nums.empty()) return {-1, -1};
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if(it == nums.end() || *it != target) return {-1, -1};
        auto is = upper_bound(nums.begin(), nums.end(), target);
        return {(int)(it - nums.begin()), (int)(is - nums.begin() - 1)};
    }
};