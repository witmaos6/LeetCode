class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int Result = 0;
        int Prev = -1e9;

        for(int& Num : nums)
        {
            int Low = max(Num - k, Prev + 1);
            if(Low <= Num + k)
            {
                Prev = Low;
                Result++;
            }
        }
        return Result;
    }
};