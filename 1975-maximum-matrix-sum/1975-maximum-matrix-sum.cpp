class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        const int N = static_cast<int>(matrix.size());
        
        int NegativeCount = 0;
        int MinValue = INT_MAX;
        long long Sum = 0;
        
        for(int Row = 0; Row < N; ++Row)
        {
            for(int Col = 0; Col < N; ++Col)
            {
                if(matrix[Row][Col] < 0)
                {
                    ++NegativeCount;
                }
                
                int AbsValue = abs(matrix[Row][Col]);
                MinValue = min(MinValue, AbsValue);
                Sum += AbsValue;
            }
        }
        
        if((NegativeCount & 1) == 0)
            return Sum;
        
        return Sum - (2 * MinValue);
    }
};