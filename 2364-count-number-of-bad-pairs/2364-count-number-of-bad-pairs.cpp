class Solution {
public:
    long long countBadPairs(vector<int>& nums)
    {
        const long long N = static_cast<long long>(nums.size());
        unordered_map<long long, long long> Table;
        
        long long Count = 0;
        for(long long i = 0; i < N; i++)
        {
            long long Temp = i - nums[i];
            Count += i - Table[Temp];
            Table[Temp]++;
        }
        
        return Count;
    }
};