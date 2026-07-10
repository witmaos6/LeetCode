class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries)
    {
        vector<pair<int, int>> NewNums(n);
        for(int i = 0; i < n; i++)
        {
            NewNums[i] = {nums[i], i};
        }
        sort(NewNums.begin(), NewNums.end());

        vector<int> GetI(n);
        for(int i = 0; i < n; i++)
        {
            GetI[NewNums[i].second] = i;
        }

        vector<vector<int>> St(n, vector<int>(18));

        int R = 0;
        for(int i = 0; i < n; i++)
        {
            if(R < i)
                R = i;

            while(R + 1 < n && NewNums[R + 1].first - NewNums[R].first <= maxDiff &&
             NewNums[R + 1].first - NewNums[i].first <= maxDiff)
             {
                R++;
             }
             St[i][0] = R;
        }

        for(int j = 1; j < 18; j++)
        {
            for(int i = 0; i < n; i++)
            {
                St[i][j] = St[St[i][j - 1]][j - 1];
            }
        }

        vector<int> Result(queries.size(), -1);
        const int Range = queries.size();
        for(int i = 0; i < Range; i++)
        {
            int A = GetI[queries[i][0]];
            int B = GetI[queries[i][1]];

            if(A > B)
                swap(A, B);
            
            if(A == B)
            {
                Result[i] = 0;
                continue;
            }

            int Curr = A, Steps = 0;

            for(int j = 17; j >= 0; j--)
            {
                if(St[Curr][j] < B)
                {
                    Curr = St[Curr][j];
                    Steps += (1 << j);
                }
                Result[i] = (St[Curr][0] >= B) ? Steps + 1 : -1;
            }
        }
        return Result;
    }
};