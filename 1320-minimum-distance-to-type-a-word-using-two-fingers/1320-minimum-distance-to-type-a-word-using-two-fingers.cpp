class Solution {
public:
    int minimumDistance(string word)
    {
        int N = word.size();
        const int INF = 1e9 + 7;
        vector<vector<int>> Memo(300, vector<int>(27, INF));
        Memo[0][26] = 0;

        int Prev = word[0] - 'A';
        for(int i = 1; i < N; i++)
        {
            int X = word[i] - 'A';

            for(int j = 0; j <= 26; j++)
            {
                if(Memo[i - 1][j] >= INF)
                    continue;
                
                Memo[i][j] = min(Memo[i][j], Memo[i - 1][j] + Dist(Prev, X));

                Memo[i][Prev] = min(Memo[i][Prev], Memo[i - 1][j] + Dist(j, X));
            }
            Prev = X;
        }
        return *min_element(Memo[N - 1].begin(), Memo[N - 1].begin() + 27);
    }

    int Dist(int X, int Y)
    {
        if(X == 26 || Y == 26)
            return 0;
        return abs(X / 6 - Y / 6) + abs(X % 6 - Y % 6);
    }
};