class Solution {
    using P = pair<long long, vector<int>>;
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals)
    {
        const int N = intervals.size();
        vector<tuple<int, int, int, int>> Nodes(N);
        for(int i = 0; i < N; i++)
        {
            Nodes[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        sort(Nodes.begin(), Nodes.end());

        vector<int> Begins(N);
        for(int i = 0; i < N; i++)
        {
            Begins[i] = get<0>(Nodes[i]);
        }

        vector<vector<P>> Memo(N + 1, vector<P>(5, {0, {}}));
        for(int i = N - 1; i >= 0; i--)
        {
            auto[L, R, W, Index] = Nodes[i];
            int Next = upper_bound(Begins.begin(), Begins.end(), R) - Begins.begin();

            for(int j = 1; j <= 4; j++)
            {
                P Take = Memo[Next][j - 1];
                Take.first += W;
                Take.second.push_back(Index);
                sort(Take.second.begin(), Take.second.end());

                P Best = Memo[i + 1][j];

                if(Take.first > Best.first ||
                (Take.first == Best.first && (Best.second.empty() || Take.second < Best.second)))
                {
                    Memo[i][j] = Take;
                }
                else
                {
                    Memo[i][j] = Best;
                }
            }
        }
        return Memo[0][4].second;
    }
};