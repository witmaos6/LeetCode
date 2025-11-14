class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries)
    {
        vector<vector<int>> Memo(n, vector<int>(n + 1));

        for(vector<int>& Query : queries)
        {
            int Row1 = Query[0];
            int Row2 = Query[2];
            int Col1 = Query[1];
            int Col2 = Query[3];

            for(int Row = Row1; Row <= Row2; Row++)
            {
                Memo[Row][Col1] += 1;
                Memo[Row][Col2 + 1] -= 1;
            }
        }

        for(int Row = 0; Row < n; Row++)
        {
            for(int Col = 1; Col < n; Col++)
            {
                Memo[Row][Col] += Memo[Row][Col - 1];
            }
        }

        for(int Row = 0; Row < n; Row++)
        {
            Memo[Row].pop_back();
        }
        return Memo;
    }
};