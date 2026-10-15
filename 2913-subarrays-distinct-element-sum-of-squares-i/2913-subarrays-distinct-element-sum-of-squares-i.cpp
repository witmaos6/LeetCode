class Solution {
public:
    int sumCounts(vector<int>& nums)
    {
        const int N = nums.size();
        int Result = 0;
        for(int i = 0; i < N; i++)
        {
            unordered_set<int> Table;
            for(int j = i; j < N; j++)
            {
                Table.insert(nums[j]);

                int Count = Table.size();

                Result += Count * Count;
            }
        }
        return Result;
    }
};