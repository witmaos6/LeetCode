class Solution {
public:
    int minimumDeletions(vector<int>& nums)
    {
        int MinIndex = -1;
        int MinNum = INT_MAX;
        int MaxIndex = -1;
        int MaxNum = INT_MIN;
        const int N = nums.size();
        if(N <= 2)
            return N;

        for(int i = 0; i < N; i++)
        {
            if(MinNum > nums[i])
            {
                MinNum = nums[i];
                MinIndex = i;
            }
            if(MaxNum < nums[i])
            {
                MaxNum = nums[i];
                MaxIndex = i;
            }
        }

        int RemoveL = min(MinIndex, MaxIndex);
        int RemoveR = max(MinIndex, MaxIndex);

        int DBackToRemoveR = N - 1 - RemoveR;
        int DRemoveLToRemoveR = RemoveR - RemoveL;

        int Result = 0;
        if(RemoveL < DBackToRemoveR)
        {
            Result += RemoveL + 1;

            if(DRemoveLToRemoveR <= DBackToRemoveR)
            {
                Result += DRemoveLToRemoveR;
            }
            else
            {
                Result += DBackToRemoveR + 1;
            }
        }
        else
        {
            Result += DBackToRemoveR + 1;
            
            if(DRemoveLToRemoveR <= RemoveL)
            {
                Result += DRemoveLToRemoveR;
            }
            else
            {
                Result += RemoveL + 1;
            }
        }

        return Result;
    }
};