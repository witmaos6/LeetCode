class Solution {
public:
    bool winnerSquareGame(int n)
    {
        vector<bool> Memo(n + 1);

        for(int i = 0; i <= n; i++)
        {
            if(!Memo[i])
            {
                for(int j = 1; i + j * j <= n; j++)
                {
                    Memo[i + j * j] = true;
                }
                if(Memo[n])
                    return true;
            }
        }
        return false;
    }
};