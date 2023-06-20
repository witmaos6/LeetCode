class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        
        vector<int> PrefixSums(N);
        PrefixSums[0] = nums[0];
        
        for(int i = 1; i < N; i++)
        {
            PrefixSums[i] = nums[i] + PrefixSums[i - 1];
        }
        
        unordered_map<int, int> Table;
        int Result = 0;
        
        for(int i = 0; i < N; i++)
        {
            if(PrefixSums[i] == k)
            {
                Result++;
            }
            
            int NeedValue = PrefixSums[i] - k;
            
            if(Table.find(NeedValue) != Table.end())
            {
                Result += Table[NeedValue];
            }
            
            Table[PrefixSums[i]]++;
        }
        
        return Result;
    }
};