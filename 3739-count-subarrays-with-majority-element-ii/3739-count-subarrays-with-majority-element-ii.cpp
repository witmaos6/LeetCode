class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target)
    {
        const int N = nums.size();

        vector<int> Pre(2 * N + 1, 0);
        Pre[N] = 1;

        int Count = N;
        long long PreSum = 0;
        long long Result = 0;

        for(const int& Num : nums)
        {
            if(Num == target)
            {
                PreSum += Pre[Count];

                Count++;
                Pre[Count]++;
            }
            else
            {
                Count--;
                PreSum -= Pre[Count];
                Pre[Count]++;
            }

            Result += PreSum;
        }
        return Result;
    }
};