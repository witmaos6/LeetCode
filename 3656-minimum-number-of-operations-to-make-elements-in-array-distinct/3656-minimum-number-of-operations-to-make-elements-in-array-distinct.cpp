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
        int NrOfNums = N;
        int i = 0;
        int Count = 0;
        while(Table.size() != NrOfNums)
        {
            const int Range = min(i + 3, N);
            for(int j = i; j < Range; j++)
            {
                Table[nums[j]]--;
                NrOfNums--;
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