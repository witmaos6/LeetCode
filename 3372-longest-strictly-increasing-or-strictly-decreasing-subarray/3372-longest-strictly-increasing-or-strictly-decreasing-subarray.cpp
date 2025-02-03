class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int MaxIncreasingNum = 0;
        {
            int PrevNum = 0;
            int CurrNum = 0;
            for(int i = 0; i < N; i++)
            {
                if(PrevNum < nums[i])
                {
                    CurrNum++;
                    MaxIncreasingNum = max(MaxIncreasingNum, CurrNum);
                }
                else
                {
                    CurrNum = 1;
                }
                PrevNum = nums[i];
            }
        }
        
        int MaxDecreasingNum = 0;
        {
            int PrevNum = INT_MAX;
            int CurrNum = 0;
            for(int i = 0; i < N; i++)
            {
                if(PrevNum > nums[i])
                {
                    CurrNum++;
                    MaxDecreasingNum = max(MaxDecreasingNum, CurrNum);
                }
                else
                {
                    CurrNum = 1;
                }
                PrevNum = nums[i];
            }
        }

        return (MaxIncreasingNum > MaxDecreasingNum) ? MaxIncreasingNum : MaxDecreasingNum;
    }
};