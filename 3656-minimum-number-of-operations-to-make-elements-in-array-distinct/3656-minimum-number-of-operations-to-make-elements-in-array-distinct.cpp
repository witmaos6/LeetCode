class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        unordered_map<int, int> Table;
        for(int& Num : nums)
        {
            Table[Num]++;
        }

        const int N = static_cast<int>(nums.size());
        int i = 0;
        int Count = 0;
        while(Table.size() < (N - i) && i < N)
        {
            const int Range = min(i + 3, N);
            for(int j = i; j < Range; j++)
            {
                Table[nums[j]]--;
                if(Table[nums[j]] == 0)
                {
                    Table.erase(nums[j]);
                }
            }
            i += 3;
            Count++;
        }
        return Count;
    }
};