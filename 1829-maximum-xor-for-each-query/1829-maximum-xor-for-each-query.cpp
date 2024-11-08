class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit)
    {
        const int N = static_cast<int>(nums.size());
        
        int PrefixXOR = nums[0];
        for(int i = 1; i < N; ++i)
        {
            PrefixXOR ^= nums[i];
        }
        
        int MaxXOR = pow(2, maximumBit) - 1;
        vector<int> Result(N);
        for(int i = 0; i < N; ++i)
        {
            Result[i] = PrefixXOR ^ MaxXOR;
            PrefixXOR ^= nums[N - 1 - i];
        }
        
        return Result;
    }
};