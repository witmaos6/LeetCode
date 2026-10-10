class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2)
    {
        vector<int> Memo(100001);
        long long K = k1 + k2;
        long long Sum = 0;
        int Max = 0;

        const int N = nums1.size();

        for(int i = 0; i < N; i++)
        {
            int X = abs(nums1[i] - nums2[i]);
            Memo[X]++;
            Sum += X;
            Max = max(Max, X);
        }

        if(Sum <= K)
            return 0;

        for(int i = Max; i > 0 && K > 0; i--)
        {
            long long Move = min(K, (long long)Memo[i]);
            Memo[i] -= Move;
            Memo[i - 1] += Move;
            K -= Move;
        }

        long long Result = 0;
        for(int i = 0; i <= Max; i++)
        {
            Result += (long long)i * i * Memo[i];
        }
        return Result;
    }
};