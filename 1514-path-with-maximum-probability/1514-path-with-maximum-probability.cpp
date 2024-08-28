struct Compare
{
    bool operator()(pair<int, double> A, pair<int, double> B)
    {
        if(A.second == B.second)
        {
            return A.first < B.first;
        }
        return A.second < B.second;
    }
};
class Solution {
    typedef pair<int, double> FNode;
    unordered_map<int, vector<FNode>> Graph;
    vector<bool> Visited;
    priority_queue<FNode, vector<FNode>, Compare> MinHeap;
    vector<double> MaxProbability;
    
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
    {
        int NrOfEdges = static_cast<int>(edges.size());
        Visited.resize(n);
        MaxProbability.resize(n);
        
        for(int i = 0; i < NrOfEdges; i++)
        {
            FNode Node1 = {edges[i][1], succProb[i]};
            FNode Node2 = {edges[i][0], succProb[i]};
            
            Graph[edges[i][0]].push_back(Node1);
            Graph[edges[i][1]].push_back(Node2);
        }
        
        return Dijikstra(start, end);
    }
    
private:
    double Dijikstra(int Begin, const int End)
    {
        MaxProbability[Begin] = 1.0;
        MinHeap.push({Begin, 1.0});
        
        while(!MinHeap.empty())
        {
            FNode CurrNode = MinHeap.top();
            MinHeap.pop();
            
            if(Visited[CurrNode.first])
            {
                continue;
            }
            Visited[CurrNode.first] = true;
            
            for(FNode& Node : Graph[CurrNode.first])
            {
                double NextValue = Node.second * CurrNode.second;
                
                if(MaxProbability[Node.first] < NextValue)
                {
                    MaxProbability[Node.first] = NextValue;
                    MinHeap.push({Node.first, NextValue});
                }
            }
        }
        
        return MaxProbability[End];
    }
};