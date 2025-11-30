class Solution {
public:
    int minSubarray(vector<int>& nums, int p)
    {
        long TotalSum = 0;
        for (int Num : nums)
        {
            TotalSum += Num;
        }

        int Remain = TotalSum % p;
        if (Remain == 0)
            return 0;

        unordered_map<int, int> PrefixMod;
        PrefixMod[0] = -1;
        long PrefixSum = 0;
        const int N = static_cast<int>(nums.size());
        int MinLength = N;

        for (int i = 0; i < N; ++i)
        {
            PrefixSum += nums[i];
            int CurrentMod = PrefixSum % p;
            int TargetMod = (CurrentMod - Remain + p) % p;

            if (PrefixMod.count(TargetMod))
            {
                MinLength = min(MinLength, i - PrefixMod[TargetMod]);
            }

            PrefixMod[CurrentMod] = i;
        }

        return MinLength == N ? -1 : MinLength;
    }
};