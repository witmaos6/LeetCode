class Solution {
    unordered_map<int, vector<int>> Graph;
    vector<int> Visited;
    int N = 0;
public:
    int maximumDetonation(vector<vector<int>>& Bombs)
    {
        N = static_cast<int>(Bombs.size());
        Visited.resize(N, -1);
        
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
            if(Visited[i] > -1)
            {
                continue;
            }
            int Count = DFS(i, i);
            Result = max(Result, Count);
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
    
    int DFS(int Index, int BombNumber)
    {
        Visited[Index] = BombNumber;
        
        int Result = 1;
        for(int& Next : Graph[Index])
        {
            if(Visited[Next] != BombNumber)
            {
                Result += DFS(Next, BombNumber);
            }
        }
        return Result;
    }
};