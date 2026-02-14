class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<double> CurrRow(1, static_cast<double>(poured));
        
        for(int i = 0; i <= query_row; i++)
        {
            vector<double> NextRow(i + 2, 0);
            
            for(int j = 0; j <= i; j++)
            {
                if(CurrRow[j] >= 1)
                {
                    NextRow[j] += (CurrRow[j] - 1) / 2.0;
                    NextRow[j + 1] += (CurrRow[j] - 1) / 2.0;
                    CurrRow[j] = 1;
                }
            }
            
            if(i != query_row)
            {
                CurrRow = NextRow;
            }
        }
        
        return CurrRow[query_glass];
    }
};