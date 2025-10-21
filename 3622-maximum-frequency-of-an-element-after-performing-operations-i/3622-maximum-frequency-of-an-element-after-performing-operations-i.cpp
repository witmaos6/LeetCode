class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations)
    {
        int MaxNum = *max_element(nums.begin(), nums.end()) + k + 2;
        vector<int> Count(MaxNum);

        for(int& Num : nums)
        {
            Count[Num]++;
        }

        for(int i = 1; i < MaxNum; i++)
        {
            Count[i] += Count[i - 1];
        }

        int Result = 0;
        for(int i = 0; i < MaxNum; i++)
        {
            int Left = max(0, i - k);
            int Right = min(MaxNum - 1, i + k);
            int Total = Count[Right] - (Left ? Count[Left - 1] : 0);
            int Freq = Count[i] - (i ? Count[i - 1] : 0);
            Result = max(Result, Freq + min(numOperations, Total - Freq));
        }
        return Result;
    }
};