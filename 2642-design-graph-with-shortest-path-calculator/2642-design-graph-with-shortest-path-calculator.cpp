struct Compare
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        if(a.second == b.second)
            {
                return a.first > b.first;
            }
        return a.second > b.second;
    }
};

class Graph {
    typedef pair<int, int> Node;
    unordered_map<int, vector<Node>> Table;
    int N = 0;
public:
    Graph(int n, vector<vector<int>>& edges)
    {
        for(vector<int>& Next : edges)
        {
            int From = Next[0];
            int To = Next[1];
            int Weight = Next[2];
            
            Table[From].push_back({To, Weight});
        }
        N = n;
    }
    
    void addEdge(vector<int> edge)
    {
        int From = edge[0];
        int To = edge[1];
        int Weight = edge[2];
        
        Table[From].push_back({To, Weight});
    }
    
    int shortestPath(int FromNode, int ToNode)
    {
        if(FromNode == ToNode)
        {
            return 0;
        }
        priority_queue<Node, vector<Node>, Compare> MinHeap;
        MinHeap.push({FromNode, 0});
        vector<int> Distance(N, INT_MAX);
        Distance[FromNode] = 0;
        
        while(!MinHeap.empty())
        {
            auto [CurrNode, Weight] = MinHeap.top();
            MinHeap.pop();
            
            if(Weight > Distance[CurrNode])
            {
                continue;
            }
            if(CurrNode == ToNode)
            {
                return Weight;
            }
            
            for(auto& [NextNode, NextWeight] : Table[CurrNode])
            {
                int NextDistance = Distance[CurrNode] + NextWeight;
                if(Distance[NextNode] > NextDistance)
                {
                    Distance[NextNode] = NextDistance;
                    MinHeap.push({NextNode, NextDistance});
                }
            }
        }
        
        if(Distance[ToNode] == INT_MAX)
        {
            return -1;
        }
        return Distance[ToNode];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */