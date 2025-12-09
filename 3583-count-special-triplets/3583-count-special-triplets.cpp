class Solution {
public:
    int specialTriplets(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        const int Mod = 1e9 + 7;
        unordered_map<int, int> Pre;
        unordered_map<int, int> Suf;

        for(int& Num : nums)
        {
            Suf[Num] += 1;
        }

        int Count = 0;
        for(int& Num : nums)
        {
            Suf[Num] -= 1;

            Count = (Count + 1LL* Pre[2 * Num] * Suf[2 * Num]) % Mod;
            Pre[Num] += 1;
        }
        return Count % Mod;
    }
};