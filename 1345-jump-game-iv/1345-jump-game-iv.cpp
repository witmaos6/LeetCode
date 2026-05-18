class Solution {
    unordered_map<int, vector<int>> Graph;
    vector<bool> Visited;
    int N = 0;
public:
    int minJumps(vector<int>& arr)
    {
        N = static_cast<int>(arr.size());
        if(N == 1)
        {
            return 0;
        }

        Graph = SetGraph(arr);

        Visited.resize(N);
        Visited[0] = true;

        queue<int> BFS;
        BFS.push(0);
        
        int Step = 0;

        while(!BFS.empty())
        {
            int Range = static_cast<int>(BFS.size());

            for(int i = 0; i < Range; i++)
            {
                int CurrIndex = BFS.front();
                BFS.pop();

                if(CurrIndex == N - 1)
                {
                    return Step;
                }

                for(int& NextIndex : Graph[arr[CurrIndex]])
                {
                    if(!Visited[NextIndex])
                    {
                        BFS.push(NextIndex);
                        Visited[NextIndex] = true;
                    }
                }
                SetAdjacentNode(BFS, CurrIndex);

                Graph[arr[CurrIndex]].clear();
            }

            Step++;
        }

        return Step;
    }

private:
    unordered_map<int, vector<int>> SetGraph(const vector<int>& arr)
    {
        unordered_map<int, vector<int>> Set;

        for(int i = 0; i < N; i++)
        {
            Set[arr[i]].push_back(i);
        }

        return Set;
    }

    void SetAdjacentNode(queue<int>& Q, const int& CurrIndex)
    {
        if(CurrIndex + 1 < N && !Visited[CurrIndex + 1])
        {
            Q.push(CurrIndex + 1);
            Visited[CurrIndex + 1] = true;
        }
        if(CurrIndex - 1 >= 0 && !Visited[CurrIndex - 1])
        {
            Q.push(CurrIndex - 1);
            Visited[CurrIndex - 1] = true;
        }
    }
};