class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board)
    {
        const int Mod = 1e9 + 7;
        const int N = board.size();

        vector<int> NextScore(N + 1, -1);
        vector<int> NextWays(N + 1);

        for(int i = N - 1; i >= 0; i--)
        {
            vector<int> CurrScore(N + 1, -1);
            vector<int> CurrWays(N + 1);

            for(int j = N - 1; j >= 0; j--)
            {
                char Cell = board[i][j];

                if(Cell == 'X')
                    continue;
                
                if(Cell == 'S')
                {
                    CurrScore[j] = 0;
                    CurrWays[j] = 1;
                    continue;
                }

                int Best = max({NextScore[j], CurrScore[j + 1], NextScore[j + 1]});

                if(Best == -1)
                    continue;
                
                long long Ways = 0;

                if(NextScore[j] == Best)
                    Ways += NextWays[j];

                if(CurrScore[j + 1] == Best)
                    Ways += CurrWays[j + 1];

                if(NextScore[j + 1] == Best)
                    Ways += NextWays[j + 1];

                int Value = (Cell == 'E') ? 0 : Cell - '0';

                CurrScore[j] = Best + Value;
                CurrWays[j] = Ways % Mod;
            }

            NextScore = move(CurrScore);
            NextWays = move(CurrWays);
        }

        if(NextScore[0] == -1)
            return {0,0};
        
        return {NextScore[0], NextWays[0]};
    }
};