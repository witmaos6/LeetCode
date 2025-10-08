class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        const int N = static_cast<int>(potions.size());
        sort(potions.begin(), potions.end());
        vector<int> Result;
        Result.reserve(spells.size());

        for(int& Spell : spells)
        {
            long long MinSpell = (success + Spell - 1) / Spell;

            int LowIndex = lower_bound(potions.begin(), potions.end(), MinSpell) - potions.begin();
            Result.push_back(N - LowIndex);
        }
        return Result;
    }
};