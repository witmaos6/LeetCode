class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        const long long Division = 2 * k + 1;
        vector<int> Avgs(N, -1);
        
        if(Division > N)
        {
            return Avgs;
        }
        
        long long PrefixSum = GetInitPrefixSum(nums, k);
        
        for(int i = k; i < N - k; i++)
        {
            PrefixSum += nums[i + k];
            Avgs[i] = static_cast<int>(PrefixSum / Division);
            
            PrefixSum -= nums[i - k];
        }
        
        return Avgs;
    }
    
private:
    long long GetInitPrefixSum(vector<int>& nums, int K)
    {
        long long InitPrefixSum = 0;
        K *= 2;
        
        for(int i = 0; i < K; i++)
        {
            InitPrefixSum += nums[i];
        }
        
        return InitPrefixSum;
    }
};