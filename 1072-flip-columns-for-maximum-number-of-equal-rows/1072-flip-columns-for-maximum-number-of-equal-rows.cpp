class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix)
    {
        const int N = static_cast<int>(matrix[0].size());
        unordered_map<bitset<300>, int> Freq;
        int Result = 0;
        
        for(vector<int>& Rows : matrix)
        {
            bitset<300> Col;
            Col.set(0);
            
            for(int i = 1; i < N; ++i)
            {
                if(Rows[0] != Rows[i])
                {
                    Col.flip(i);
                }
            }
            
            ++Freq[Col];
            Result = max(Result, Freq[Col]);
        }
        
        return Result;
    }
};