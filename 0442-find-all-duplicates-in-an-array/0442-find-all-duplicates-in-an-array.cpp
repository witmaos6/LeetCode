class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Result;
        for(int i = 0; i < N; i++)
        {
            int Index = abs(nums[i]) - 1;
            nums[Index] *= -1;

            if(nums[Index] > 0)
            {
                Result.push_back(Index + 1);
            }
        }
        
        return Result;
    }
};