class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board)
    {
        const int N = static_cast<int>(board.size());

        vector<int> Moves(N * N + 1, -1);

        int Index = 1;
        bool Flag = true;

        for(int Row = N - 1; Row >= 0; Row--)
        {
            for(int i = 0; i < N; i++)
            {
                int Col = Flag ? i : N - i - 1;
                Moves[Index] = board[Row][Col];
                Index++;
            }
            Flag = !Flag;
        }

        queue<int> Q;
        vector<bool> Visited(N * N + 1);
        Q.push(1);
        Visited[1] = true;
        int Steps = 0;

        while(!Q.empty())
        {
            int Range = static_cast<int>(Q.size());
            while(Range--)
            {
                int Curr = Q.front();
                Q.pop();

                if(Curr == N * N)
                    return Steps;

                for(int Dice = 1; Dice <= 6; Dice++)
                {
                    int Next = Curr + Dice;
                    if(Next > N * N)
                        continue;
                    
                    int Dest = Moves[Next] == -1 ? Next : Moves[Next];
                    if(!Visited[Dest])
                    {
                        Visited[Dest] = true;
                        Q.push(Dest);
                    }
                }
            }
            Steps++;
        }
        return -1;
    }
};