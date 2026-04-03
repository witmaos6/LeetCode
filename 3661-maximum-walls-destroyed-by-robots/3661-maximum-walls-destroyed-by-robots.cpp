class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls)
    {
        const int N = robots.size();
        vector<vector<int>> X(N, vector<int>(2));
        for(int i = 0; i < N ; i++)
        {
            X[i] = {robots[i], distance[i]};
        }

        sort(X.begin(), X.end());
        sort(walls.begin(), walls.end());

        X.push_back({static_cast<int>(1e9), 0});

        vector<vector<int>> Memo(N, vector<int>(2));
        Memo[0][0] = Query(walls, X[0][0] - X[0][1], X[0][0]);

        if(N > 1)
        {
            int Temp = min(X[1][0] - 1, X[0][0] + X[0][1]);
            Memo[0][1] = Query(walls, X[0][0], Temp);
        }
        else
        {
            Memo[0][1] = Query(walls, X[0][0], X[0][0] + X[0][1]);
        }

        for(int i = 1; i < N; i++)
        {
            int Right = min(X[i + 1][0] - 1, X[i][0] + X[i][1]);
            Memo[i][1] = max(Memo[i - 1][0], Memo[i - 1][1]) + Query(walls, X[i][0], Right);

            int Left = max(X[i][0] - X[i][1], X[i - 1][0] + 1);
            Memo[i][0] = Memo[i - 1][0] + Query(walls, Left, X[i][0]);

            int LeftStart = max(X[i][0] - X[i][1], X[i - 1][0] + 1);
            int LeftEnd = X[i][0];

            int OverlapStart = LeftStart;
            int OverlapEnd = min(X[i - 1][0] + X[i - 1][1], X[i][0] - 1);

            int Result = Memo[i - 1][1] + Query(walls, LeftStart, LeftEnd) - Query(walls, OverlapStart, OverlapEnd);

            Memo[i][0] = max(Memo[i][0], Result);
        }
        return max(Memo[N - 1][0], Memo[N - 1][1]);
    }

    int Query(vector<int>& Arr, int L, int R)
    {
        if(L > R)
            return 0;
        
        auto It1 = upper_bound(Arr.begin(), Arr.end(), R);
        auto It2 = lower_bound(Arr.begin(), Arr.end(), L);
        return It1 - It2;
    }
};