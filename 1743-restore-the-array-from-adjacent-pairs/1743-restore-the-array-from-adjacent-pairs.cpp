class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs)
    {
        unordered_map<int, vector<int>> Table;
        
        for(vector<int>& Adj : adjacentPairs)
        {
            Table[Adj[0]].push_back(Adj[1]);
            Table[Adj[1]].push_back(Adj[0]);
        }
        
        int SideNum = INT_MIN;
        for(auto& [Index, Adj] : Table)
        {
            if(Adj.size() == 1)
            {
                SideNum = Index;
                break;
            }
        }
        
        int N = static_cast<int>(adjacentPairs.size());
        vector<int> Result = {SideNum};
        int Prev = SideNum;
        
        for(int i = 0; i < N; i++)
        {
            int Node = Result[i];
            
            vector<int>& Adj = Table[Node];
            
            for(int& Num : Adj)
            {
                if(Num != Prev)
                {
                    Result.push_back(Num);
                }
            }
            
            Prev = Node;
        }
        
        return Result;
    }
};