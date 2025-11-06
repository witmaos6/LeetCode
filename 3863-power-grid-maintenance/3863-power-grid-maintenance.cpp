class Solution {
    vector<vector<int>> Graph;
    vector<int> Visited;
    vector<int> Online;
    map<int, set<int>> Table;
    map<int, int> IDTable;
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries)
    {
        Graph.resize(c);
        for(vector<int>& Connect : connections)
        {
            Graph[Connect[0] - 1].push_back(Connect[1] - 1);
            Graph[Connect[1] - 1].push_back(Connect[0] - 1);
        }

        Visited.resize(c);
        Online.resize(c, 1);
        
        int ID = 0;
        for(int i = 0; i < c; i++)
        {
            if(!Visited[i])
            {
                DFS(ID, i);
                ID++;
            }
        }

        vector<int> Result;
        for(vector<int>& Query : queries)
        {
            int Type = Query[0];
            int Node = Query[1] - 1;
            int ComID = IDTable[Node];

            if(Type == 2)
            {
                Table[ComID].erase(Node);
                Online[Node] = 0;
                continue;
            }

            if(Online[Node])
            {
                Result.push_back(Node + 1);
            }
            else if(Table[ComID].size() > 0)
            {
                Result.push_back(*Table[ComID].begin() + 1);
            }
            else
            {
                Result.push_back(-1);
            }
        }
        return Result;
    }

private:
    void DFS(int ID, int Node)
    {
        Visited[Node] = 1;
        Table[ID].insert(Node);
        IDTable[Node] = ID;

        for(int& Adj : Graph[Node])
        {
            if(!Visited[Adj])
            {
                DFS(ID, Adj);
            }
        }
    }
};