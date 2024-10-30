class Solution {
    int N = 0;
public:
    int minimumMountainRemovals(vector<int>& nums)
    {
        N = static_cast<int>(nums.size());
        vector<int> LIS = LongestIncreasingSubsequence(nums);
        vector<int> LDS = LongestDecreasingSubsequence(nums);
        
        int MaxMountainSize = 0;
        
        for(int i = 1; i < N - 1; ++i)
        {
            if(LIS[i] > 1 && LDS[i] > 1)
            {
                int MountainSize = LIS[i] + LDS[i] - 1;
                MaxMountainSize = max(MaxMountainSize, MountainSize);
            }
        }
        
        return N - MaxMountainSize;
    }
    
private:
    vector<int> LongestIncreasingSubsequence(vector<int>& Nums)
    {
        vector<int> LIS(N, 1);
        
        for(int i = 1; i < N; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(Nums[i] > Nums[j])
                {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }
        return LIS;
    }
    
    vector<int> LongestDecreasingSubsequence(vector<int>& Nums)
    {
        vector<int> LDS(N, 1);
        
        for(int i = N - 2; i >= 0; --i)
        {
            for(int j = N - 1; j > i; --j)
            {
                if(Nums[i] > Nums[j])
                {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }
        return LDS;
    }
};