class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana)
    {
        const int N = static_cast<int>(skill.size());
        const int M = static_cast<int>(mana.size());

        vector<long long> Memo(N + 1);

        for(int j = 0; j < M; j++)
        {
            for(int i = 0; i < N; i++)
            {
                Memo[i + 1] = max(Memo[i + 1], Memo[i]) + 1LL * mana[j] * skill[i];
            }
            for(int i = N - 1; i > 0; i--)
            {
                Memo[i] = Memo[i + 1] - 1LL * mana[j] * skill[i];
            }
        }
        return Memo.back();
    }
};