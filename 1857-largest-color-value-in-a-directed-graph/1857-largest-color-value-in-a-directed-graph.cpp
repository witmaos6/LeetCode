class Solution {
    unordered_map<int, vector<int>> Graph;
public:
    int largestPathValue(string Colors, vector<vector<int>>& Edges)
    {
        int N = static_cast<int>(Colors.size());
        vector<int> Indegrees(N);
        
        for(vector<int>& Edge : Edges)
        {
            Graph[Edge[0]].push_back(Edge[1]);
            
            Indegrees[Edge[1]]++;
        }
        
        queue<int> ZeroIndegrees;
        for(int i = 0; i < N; i++)
        {
            if(Indegrees[i] == 0)
            {
                ZeroIndegrees.push(i);
            }
        }
        
        vector<vector<int>> Counts(N, vector<int>(26));
        for(int i = 0; i < N; i++)
        {
            Counts[i][Colors[i] - 'a']++;
        }
        
        int Result = 0;
        int Visited = 0;
        
        while(!ZeroIndegrees.empty())
        {
            int Curr = ZeroIndegrees.front();
            ZeroIndegrees.pop();
            Visited++;
            
            for(int Next : Graph[Curr])
            {
                for(int i = 0; i < 26; i++)
                {
                    int Temp = Counts[Curr][i];
                    if(Colors[Next] - 'a' == i)
                    {
                        Temp++;
                    }
                    Counts[Next][i] = max(Counts[Next][i], Temp);
                }
                Indegrees[Next]--;
                if(Indegrees[Next] == 0)
                {
                    ZeroIndegrees.push(Next);
                }
            }
            int CurrMax = *max_element(Counts[Curr].begin(), Counts[Curr].end());
            
            Result = max(Result, CurrMax);
        }
        
        if(Visited == N)
        {
            return Result;
        }
        return -1;
    }
};