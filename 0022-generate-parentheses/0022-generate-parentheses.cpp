class Solution {
    vector<string> Result;
public:
    vector<string> generateParenthesis(int n)
    {
        string S;
        DFS(S, n * 2, 0, 0);
        return Result;
    }
private:
    void DFS(string S, int N, int Open, int Close)
    {
        if(S.size() == N)
        {
            Result.push_back(S);
            return;
        }

        if(Open < N / 2)
        {
            DFS(S + '(', N, Open + 1, Close);
        }
        if(Close < Open)
        {
            DFS(S + ')', N, Open, Close + 1);
        }
    }
};