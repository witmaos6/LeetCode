class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k)
    {
        const int N = static_cast<int>(nums.size());

        long long CountSubarray = 0;
        long long Sum = 0;
        long long Count = 0;
        int Left = 0;

        for(int i = 0; i < N; i++)
        {
            Sum += nums[i];
            Count++;

            long long Product = Sum * Count;
            while(Product >= k && Left < i)
            {
                Sum -= nums[Left];
                Count--;
                Product = Sum * Count;
                Left++;
            }
            if(Product < k)
            {
                CountSubarray += (i - Left + 1);
            }
        }
        return CountSubarray;
    }
};