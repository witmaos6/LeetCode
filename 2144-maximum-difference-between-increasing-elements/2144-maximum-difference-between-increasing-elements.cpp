class Solution {
public:
    int maximumDifference(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int Result = -1;
        int IMin = nums[0];
        for(int i = 1; i < N; i++)
        {
            int Temp = nums[i];
            if(Temp <= IMin)
            {
                IMin = Temp;
            }
            else
            {
                Result = max(Result, Temp - IMin);
            }
        }
        return Result;
    }
};