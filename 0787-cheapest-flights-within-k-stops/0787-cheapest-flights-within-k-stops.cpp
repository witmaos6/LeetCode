class Solution {
    using Direct = pair<int, int>;

    unordered_map<int, vector<Direct>> Graph;

    using Path = tuple<int, int, int>;

    const int Impossible = -1;

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        BuildGraph(flights);

        return Dijkstra(n, src, dst, k);
    }

private:
    void BuildGraph(vector<vector<int>>& Flights)
    {
        for(vector<int>& Flight : Flights)
        {
            Graph[Flight[0]].push_back({Flight[1], Flight[2]});
        }
    }

    int Dijkstra(const int& n, const int& Src, const int& Des, const int& Rest)
    {
        vector<int> Dist(n + 1, INT_MAX);

        priority_queue<Path, vector<Path>, greater<Path>> MinHeap;
        MinHeap.push({0, Src, 0});

        while(!MinHeap.empty())
        {
            auto [CurrCost, CurrPath, CurrRest] = MinHeap.top();
            MinHeap.pop();

            if(CurrPath == Des)
            {
                return CurrCost;
            }

            if(Dist[CurrPath] < CurrRest)
            {
                continue;
            }
            Dist[CurrPath] = CurrRest;

            if(CurrRest <= Rest)
            {
                for(Direct& Next : Graph[CurrPath])
                {
                    MinHeap.push({CurrCost + Next.second, Next.first, CurrRest + 1});
                }
            }
        }
        
        return Impossible;
    }
};