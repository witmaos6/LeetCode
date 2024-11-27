class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries)
    {        
        vector<int> Distance(n);
        for(int i = 0; i < n; ++i)
        {
            Distance[i] = i;
        }
        
        vector<vector<int>> Table(n);
        for(int i = 0; i < n - 1; ++i)
        {
            Table[i].push_back(i + 1);
        }
        
        vector<int> Answer;
        Answer.reserve(queries.size());
        for(vector<int>& Query : queries)
        {
            const int U = Query[0];
            const int V = Query[1];
            
            Table[U].push_back(V);
            
            if(Distance[U] + 1 < Distance[V])
            {
                queue<int> BFS;
                BFS.push(V);
                
                Distance[V] = Distance[U] + 1;
                while(!BFS.empty())
                {
                    int Index = BFS.front();
                    BFS.pop();
                    
                    for(int& Road : Table[Index])
                    {
                        if(Distance[Index] + 1 < Distance[Road])
                        {
                            Distance[Road] = Distance[Index] + 1;
                            BFS.push(Road);
                        }
                    }
                }
            }
            
            Answer.push_back(Distance.back());
        }
        
        return Answer;
    }
};