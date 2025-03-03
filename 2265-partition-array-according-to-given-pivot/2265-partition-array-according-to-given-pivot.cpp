class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Result(N);
        int Index = 0;
        int NrOfPivot = 0;

        for(int i = 0; i < N; i++)
        {
            if(nums[i] < pivot)
            {
                Result[Index] = nums[i];
                Index++;
            }
            else if(nums[i] == pivot)
            {
                NrOfPivot++;
            }
        }
        for(int i = 0; i < NrOfPivot; i++)
        {
            Result[Index] = pivot;
            Index++;
        }
        for(int i = 0; i < N; i++)
        {
            if(nums[i] > pivot)
            {
                Result[Index] = nums[i];
                Index++;
            }
        }
        return Result;
    }
};