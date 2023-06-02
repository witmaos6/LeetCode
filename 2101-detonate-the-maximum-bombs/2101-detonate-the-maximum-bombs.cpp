class Solution {
    unordered_map<int, vector<int>> Graph;
    int N = 0;
public:
    int maximumDetonation(vector<vector<int>>& Bombs)
    {
        N = static_cast<int>(Bombs.size());
        
        for(int i = 0; i < N - 1; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                if(bInDetonateRange(Bombs[i], Bombs[j]))
                {
                    Graph[i].push_back(j);
                }
                if(bInDetonateRange(Bombs[j], Bombs[i]))
                {
                    Graph[j].push_back(i);
                }
            }
        }

        int Result = 0;
        
        for(int i = 0; i < N; i++)
        {
            Result = max(Result, BFS(i));
        }
        
        return Result;
    }
    
private:
    bool bInDetonateRange(vector<int>& Bomb, vector<int>& P)
    {
        long long X = abs(Bomb[1] - P[1]);
        long long Y = abs(Bomb[0] - P[0]);
        long long Diagonal = (X * X) + (Y * Y);
        long long BombRange = static_cast<long long>(Bomb[2]) * Bomb[2];
        
        if(BombRange >= Diagonal)
        {
            return true;
        }
        return false;
    }
    
    int BFS(int Index)
    {
        int Count = 0;
        queue<int> Q;
        Q.push(Index);
        
        vector<bool> Visited(N);
        Visited[Index] = true;
        
        while(!Q.empty())
        {
            int CurrIndex = Q.front();
            Q.pop();
            Count++;
            
            for(int& Next : Graph[CurrIndex])
            {
                if(!Visited[Next])
                {
                    Visited[Next] = true;
                    Q.push(Next);
                }
            }
        }
        
        return Count;
    }
};