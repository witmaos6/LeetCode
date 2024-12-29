class Solution {
public:
    int numWays(vector<string>& words, string target)
    {
        const int Mod = 1e9 + 7;
        const int N = static_cast<int>(words[0].size());
        const int TargetSize = static_cast<int>(target.size());
        
        vector<vector<int>> Freq(26, vector<int>(N));
        for(int i = 0; i < N; i++)
        {
            for(const string& Word : words)
            {
                Freq[Word[i] - 'a'][i]++;
            }
        }

        vector<int> Memo(TargetSize + 1);
        Memo[0] = 1;

        for(int i = 0; i < N; i++)
        {
            for(int j = TargetSize; j >= 1; j--)
            {
                long long CurrFreq = Freq[target[j - 1] - 'a'][i];
                Memo[j] = (Memo[j] + Memo[j - 1] * CurrFreq) % Mod;
            }
        }
        return Memo[TargetSize];
    }
};