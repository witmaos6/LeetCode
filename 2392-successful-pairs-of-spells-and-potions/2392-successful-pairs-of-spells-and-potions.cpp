class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> Result;
        Result.reserve(spells.size());
        const int N = static_cast<int>(potions.size());

        for(int& Spell : spells)
        {
            long long MinSpell = success / Spell;
            MinSpell += (success % Spell == 0) ? 0 : 1;

            int LowIndex = lower_bound(potions.begin(), potions.end(), MinSpell) - potions.begin();
            Result.push_back(N - LowIndex);
        }
        return Result;
    }
};