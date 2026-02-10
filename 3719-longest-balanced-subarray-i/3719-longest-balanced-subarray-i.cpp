class Solution {
public:
    int longestBalanced(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int Result = 0;
        unordered_set<int> Table;
        array<int, 2> Count = {0};
        
        for(int i = 0; i < N; i++)
        {
            Table.clear();
            Count = {0};
            for(int j = i; j < N; j++)
            {
                if(Table.count(nums[j]) == 0)
                {
                    Count[nums[j] & 1]++;
                    Table.insert(nums[j]);
                }

                if(Count[0] == Count[1])
                {
                    Result = max(Result, j - i + 1);
                }
            }
        }
        return Result;
    }
};