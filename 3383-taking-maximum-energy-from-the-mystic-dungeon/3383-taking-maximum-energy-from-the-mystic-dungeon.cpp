class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k)
    {
        const int N = static_cast<int>(energy.size());

        vector<int> Memo(N);
        int Result = INT_MIN;

        for(int i = N - 1; i >= 0; i--)
        {
            Memo[i] = energy[i] + ((i + k < N) ? Memo[i + k] : 0);
            Result = max(Result, Memo[i]);
        }
        return Result;
    }
};