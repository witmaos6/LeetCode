class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int PositiveIndex = 0;
        int NegativeIndex = 1;
        
        vector<int> Result(N);
        for(int i = 0; i < N; i++)
        {
            if(nums[i] > 0)
            {
                Result[PositiveIndex] = nums[i];
                PositiveIndex += 2;
            }
            else if(nums[i] < 0)
            {
                Result[NegativeIndex] = nums[i];
                NegativeIndex += 2;
            }
        }
        
        return Result;
    }
};