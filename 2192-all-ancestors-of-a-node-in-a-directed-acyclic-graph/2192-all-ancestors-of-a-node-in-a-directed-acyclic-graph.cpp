class Solution {
    unordered_map<int, vector<int>> DAG;
    vector<vector<int>> Answer;
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges)
    {
        for(vector<int>& Edge : edges)
        {
            int From = Edge[0];
            int To = Edge[1];
            
            DAG[From].push_back(To);
        }       

        Answer.resize(n);
        for(int i = 0; i < n; i++)
        {
            DFS(i, i);
        }
        
        return Answer;
    }
    
    private:
    void DFS(const int Index, int CurrNode)
    {
        for (int Adj : DAG[CurrNode])
        {
            if (Answer[Adj].empty() || Answer[Adj].back() != Index)
            {
                Answer[Adj].push_back(Index);
                DFS(Index, Adj);
            }
        }
    }
};