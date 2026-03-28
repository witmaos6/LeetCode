class Solution {
public:
    string findTheString(vector<vector<int>>& lcp)
    {
        const int N = lcp.size();
        string S(N, 'X');
        int id = -1;
        for(int i = 0; i < N; i++)
        {
            if(lcp[i][i] != N - i)
                return "";
            if(S[i] >= 'a')
                continue;
            if(id++ >= 25)
                return "";
            for(int j = i; j < N; j++)
            {
                if(lcp[i][j])
                    S[j] = 'a' + id;
            }
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < i; j++)
            {
                const int X = lcp[i][j];
                if(X != lcp[j][i] || X + i > N)
                    return "";
                int Y = (i < N - 1) ? lcp[i + 1][j + 1] : 0;
                Y = (S[i] == S[j]) ? Y + 1 : 0;
                if(X != Y)
                    return "";
            }
        }
        return S;
    }
};