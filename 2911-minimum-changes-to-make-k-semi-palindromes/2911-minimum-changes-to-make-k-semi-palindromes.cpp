class Solution {
public:
    int minimumChanges(string s, int k)
    {
        const int N = s.size();
        int INF = INT_MAX / 2;

        vector Cost(N + 1, vector(N + 1, INF));
        for(int D = 1; 2 * D <= N; ++D)
        {
            for(int L = 2 * D; L <= N; L += D)
            {
                for(int i = 0, j = L; j <= N; i++, j++)
                {
                    Cost[i][j] = min(Cost[i][j], Peel(s, i, j, D));
                }
            }
        }

        vector Best(N + 1, INF);
        Best[0] = 0;

        for(int P = 1; P < k; P++)
        {
            vector Next(N + 1, INF);
            for(int j = 2 * P; j <= N - 2 * (k - P); j++)
            {
                Next[j] = Extend(Best, Cost, j);
            }
            swap(Best, Next);
        }
        return Extend(Best, Cost, N);
    }

private:
    int Peel(string& S, int i, int j, int D)
    {
        int Change = 0;
        for(; j - i > D; i += D, j -= D)
        {
            for(int t = 0; t < D; t++)
            {
                Change += S[i + t] != S[j - D + t];
            }
        }
        return Change;
    }

    int Extend(vector<int>& Best, vector<vector<int>>& Cost, int j)
    {
        return ranges::min(views::iota(0, j - 1) | views::transform([&](int i) { return Best[i] + Cost[i][j]; }));
    }
};