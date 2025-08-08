


class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        
        // 枚举 0 ~ 1<<n - 1 之间所有数的二进制位 
        // 0 表示不选，1 表示选
        for(int i = 0; i < (1 << nums.size()); i++)
        {
            vector<int> tmp;
            for(int j = 0; j < nums.size(); j++)
            {
                if(i & (1 << j)) tmp.push_back(nums[j]);
            }
            ret.push_back(tmp);
        }

        return ret;
    }
};