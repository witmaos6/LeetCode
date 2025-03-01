class Solution {
public:
    vector<int> applyOperations(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Result;
        Result.reserve(N);
        for(int i = 0; i < N; i++)
        {
            if(nums[i] != 0)
            {
                if(i + 1 < N && nums[i] == nums[i + 1])
                {
                    nums[i] *= 2;
                    nums[i + 1] = 0;
                }
                Result.push_back(nums[i]);
            }
        }

        while(Result.size() < N)
        {
            Result.push_back(0);
        }
        return Result;
    }
};