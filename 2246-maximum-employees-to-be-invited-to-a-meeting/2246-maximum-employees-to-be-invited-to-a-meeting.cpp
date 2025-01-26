class Solution {
public:
    int maximumInvitations(vector<int>& favorite)
    {
        const int N = static_cast<int>(favorite.size());
        vector<int> InDegree(N);
        for(int& Fav : favorite)
        {
            InDegree[Fav]++;
        }

        queue<int> BFS;
        for(int i = 0; i < N; i++)
        {
            if(InDegree[i] == 0)
            {
                BFS.push(i);
            }
        }

        vector<int> ChainLength(N);
        vector<bool> Visited(N);
        while(!BFS.empty())
        {
            int Node = BFS.front();
            BFS.pop();

            Visited[Node] = true;

            int Next = favorite[Node];
            ChainLength[Next] = ChainLength[Node] + 1;
            if(--InDegree[Next] == 0)
            {
                BFS.push(Next);
            }
        }

        int MaxCycle = 0;
        int TotalChains = 0;
        for(int i = 0; i < N; i++)
        {
            if(Visited[i])
                continue;

            int Current = i;
            int CycleLength = 0;
            while(!Visited[Current])
            {
                Visited[Current] = true;
                Current = favorite[Current];
                CycleLength++;
            }

            if(CycleLength == 2)
            {
                TotalChains += 2 + ChainLength[i] + ChainLength[favorite[i]];
            }
            else
            {
                MaxCycle = max(MaxCycle, CycleLength);
            }
        }

        return max(MaxCycle, TotalChains);
    }
};