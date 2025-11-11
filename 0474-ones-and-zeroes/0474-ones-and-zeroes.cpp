class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<int>> Memo(m + 1, vector<int>(n + 1));

        for(string& Str : strs)
        {
            const int Len = Str.size();
            const int Count0 = count(Str.begin(), Str.end(), '0');
            const int Count1 = Len - Count0;

            for(int i = m; i >= Count0; i--)
            {
                for(int j = n; j >= Count1; j--)
                {
                    Memo[i][j] = max(Memo[i][j], Memo[i - Count0][j - Count1] + 1);
                }
            }
        }
        return Memo[m][n];
    }
};