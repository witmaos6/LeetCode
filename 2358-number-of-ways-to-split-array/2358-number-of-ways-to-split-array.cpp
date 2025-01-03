class Solution {
public:
    int waysToSplitArray(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());

        long long Total = 0;
        for(int& Num : nums)
        {
            Total += Num;
        }
        long long Sum = 0;
        int Count = 0;
        for(int i = 0; i < N - 1; i++)
        {
            Sum += nums[i];
            Total -= nums[i];

            if(Sum >= Total)
            {
                Count++;
            }
        }
        return Count;
    }
};