class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Result;
        Result.reserve(N);
        
        int FindMaxNegative = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        if(FindMaxNegative == N)
        {
            FindMaxNegative--;
        }
        
        int RDirect = FindMaxNegative;
        int LDirect = RDirect - 1;
        
        while(LDirect >= 0 || RDirect < N)
        {
            if(LDirect < 0)
            {
                Result.push_back(pow(nums[RDirect], 2));
                RDirect++;
                continue;
            }
            if(RDirect >= N)
            {
                Result.push_back(pow(nums[LDirect], 2));
                LDirect--;
                continue;
            }
            
            if(-nums[LDirect] < nums[RDirect])
            {
                Result.push_back(pow(nums[LDirect], 2));
                LDirect--;
            }
            else
            {
                Result.push_back(pow(nums[RDirect], 2));
                RDirect++;
            }
        }
        
        return Result;
    }
};