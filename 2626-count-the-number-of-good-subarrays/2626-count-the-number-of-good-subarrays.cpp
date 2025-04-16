class Solution {
public:
    long long countGood(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        unordered_map<int, int> Freq;
        long long Result = 0;
        long long Pairs = 0;
        int Left = 0;
        
        for(int Right = 0; Right < N; Right++)
        {
            int Value = nums[Right];
            Pairs += Freq[Value];
            Freq[Value]++;

            while(Pairs >= k)
            {
                Result += (N - Right);
                int Out = nums[Left];
                Left++;
                Freq[Out]--;
                Pairs -= Freq[Out];
            }
        }
        return Result;
    }
};