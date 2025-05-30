class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2)
    {
        const int N = static_cast<int>(edges.size());

        vector<int> Visited1(N, -1);
        vector<int> Visited2(N, -1);

        int Depth = 0;
        while(node1 != -1 && Visited1[node1] == -1)
        {
            Visited1[node1] = Depth;
            node1 = edges[node1];
            Depth++;
        }

        int Result = INT_MAX;
        int Index = -1;
        Depth = 0;
        while(node2 != -1 && Visited2[node2] == -1)
        {
            Visited2[node2] = Depth;
            if(Visited1[node2] != -1)
            {
                if(max(Visited1[node2], Depth) < Result)
                {
                    Result = max(Visited1[node2], Depth);
                    Index = node2;
                }
                else if(max(Visited1[node2], Depth) == Result)
                {
                    if(Index > node2)
                    {
                        Index = node2;
                    }
                }
            }
            node2 = edges[node2];
            Depth++;
        }
        return Index;
    }
};