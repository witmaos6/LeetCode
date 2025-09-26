class Solution {
public:
    int triangleNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        const int N = static_cast<int>(nums.size());
        int Result = 0;
        for(int i = 2; i < N; i++)
        {
            int L = 0, R = i - 1;
            while(L < R)
            {
                if(nums[L] + nums[R] > nums[i])
                {
                    Result += R - L;
                    R--;
                }
                else
                {
                    L++;
                }
            }
        }
        return Result;
    }
};