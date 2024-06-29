class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges)
    {
        unordered_map<int, vector<int>> DAG;
        for(vector<int>& Edge : edges)
        {
            int From = Edge[0];
            int To = Edge[1];
            
            DAG[To].push_back(From);
        }       
        
        vector<set<int>> Ancestors(n);
        for(int i = 0; i < n; i++)
        {
            queue<int> BFS;
            for(int Num : DAG[i])
            {
                BFS.push(Num);
            }
            
            vector<bool> Visited(n);
            
            while(!BFS.empty())
            {
                int Node = BFS.front();
                BFS.pop();
                
                if(Visited[Node])
                    continue;
                
                Visited[Node] = true;
                Ancestors[i].insert(Node);
                
                for(int Adj : DAG[Node])
                {
                    BFS.push(Adj);
                }
            }
        }
        
        vector<vector<int>> Answer(n);
        for(int i = 0; i < n; i++)
        {
            for(const int& Num : Ancestors[i])
            {
                Answer[i].push_back(Num);
            }
        }
        
        return Answer;
    }
};