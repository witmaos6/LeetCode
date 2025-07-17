class Solution {
public:
    int maximumLength(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        int Result = 2;
        for(int i = 0; i < k; i++)
        {
            vector<int> Memo(k);

            for(int& Num : nums)
            {
                int Mod = Num % k;
                int Pos = (i - Mod + k) % k;
                Memo[Mod] = Memo[Pos] + 1;
            }

            for(int& Num : Memo)
            {
                Result = max(Result, Num);
            }
        }
        return Result;
    }
};