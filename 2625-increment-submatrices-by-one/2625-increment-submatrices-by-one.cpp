class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries)
    {
        vector<vector<int>> Memo(n + 1, vector<int>(n));

        for(vector<int>& Query : queries)
        {
            int Row1 = Query[0];
            int Row2 = Query[2];
            int Col1 = Query[1];
            int Col2 = Query[3];

            Memo[Row1][Col1]++;
            Memo[Row2 + 1][Col1]--;

            if(Col2 + 1 < n)
            {
                Memo[Row1][Col2 + 1]--;
                Memo[Row2 + 1][Col2 + 1]++;
            }
        }

        for(int Row = 0; Row < n; Row++)
        {
            for(int Col = 1; Col < n; Col++)
            {
                Memo[Row][Col] += Memo[Row][Col - 1];
            }
        }

        for(int Col = 0; Col < n; Col++)
        {
            for(int Row = 1; Row < n; Row++)
            {
                Memo[Row][Col] += Memo[Row - 1][Col];
            }
        }

        Memo.resize(n);
        return Memo;
    }
};