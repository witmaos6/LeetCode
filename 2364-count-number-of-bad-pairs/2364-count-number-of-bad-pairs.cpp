class Solution {
public:
    long long countBadPairs(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        unordered_map<int, int> Table;
        
        long long Count = 0;
        for(int i = 0; i < N; i++)
        {
            int Temp = i - nums[i];
            Count += i - Table[Temp];
            Table[Temp]++;
        }
        
        return Count;
    }
};