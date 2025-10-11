class Solution {
public:
    long long maximumTotalDamage(vector<int>& power)
    {
        unordered_map<int, long long> Freq;
        for(int& P : power)
        {
            Freq[P]++;
        }

        vector<int> Keys;
        for(auto& [Key, _] : Freq)
        {
            Keys.push_back(Key);
        }
        sort(Keys.begin(), Keys.end());

        const int N = static_cast<int>(Keys.size());
        vector<long long> Memo(N);
        Memo[0] = Freq[Keys[0]] * Keys[0];

        for(int i = 1; i < N; i++)
        {
            long long Take = Freq[Keys[i]] * Keys[i];
            int Prev = upper_bound(Keys.begin(), Keys.begin() + i, Keys[i] - 3) - Keys.begin() - 1;
            if(Prev >= 0)
                Take += Memo[Prev];
            Memo[i] = max(Memo[i - 1], Take);
        }
        return Memo[N - 1];
    }
};