class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges)
    {
        int Min = 1000;
        int Max = 0;
        for(char& Color : colors)
        {
            Max = max(Max, (int)Color);
            Min = min(Min, (int)Color);
        }

        const int N = static_cast<int>(colors.size());
        const int Range = Max - Min + 1;
        vector<vector<int>> Freq(N, vector<int>(Range));
        vector<int> Counts(N);
        vector<vector<int>> Parents(N);
        int Count = 0;
        int Result = 0;
        
        for(vector<int>& Edge : edges)
        {
            Counts[Edge[0]]++;
            Parents[Edge[1]].push_back(Edge[0]);
        }

        queue<int> BFS;
        for(int i = 0; i < N; i++)
        {
            if(Counts[i] == 0)
            {
                BFS.push(i);
            }
        }

        while(!BFS.empty())
        {
            int K = BFS.front();
            BFS.pop();
            Freq[K][colors[K] - Min]++;
            Count++;

            for(int i = 0; i < Range; i++)
            {
                Result = max(Result, Freq[K][i]);
            }

            for(int& Parent : Parents[K])
            {
                if(Counts[Parent]-- == 1)
                {
                    BFS.push(Parent);
                }
                for(int i = 0; i < Range; i++)
                {
                    Freq[Parent][i] = max(Freq[Parent][i], Freq[K][i]);
                }
            }
        }
        return (Count != N) ? -1 : Result;
    }
};