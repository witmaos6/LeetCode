class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums)
    {
        int NrOfDistinct = unordered_set<int>(nums.begin(), nums.end()).size();

        const int N = static_cast<int>(nums.size());
        unordered_map<int, int> Table;
        int Result = 0;
        int Left = 0;
        for(int i = 0; i < N; i++)
        {
            Table[nums[i]]++;
            while(Table.size() == NrOfDistinct)
            {
                Result += (N - i);
                Table[nums[Left]]--;
                if(Table[nums[Left]] == 0)
                {
                    Table.erase(nums[Left]);
                }
                Left++;
            }
        }
        return Result;
    }
};