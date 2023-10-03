class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        int N = static_cast<int>(nums.size());
        int Count = 0;
        vector<int> Memo(101);
        
        for(int i = 0; i < N; i++)
        {
            Count += Memo[nums[i]];
            Memo[nums[i]]++;
        }
        
        return Count;
    }
};