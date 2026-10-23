class Solution {
public:
    int sortPermutation(vector<int>& nums)
    {
        int k = -1;
        const int N = nums.size();
        for(int i = 0; i < N; i++)
        {
            if(nums[i] != i)
            {
                k &= nums[i];
                if(k == 0)
                    return 0;
            }
        }
        return max(k, 0);
    }
};