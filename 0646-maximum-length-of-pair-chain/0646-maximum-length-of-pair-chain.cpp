class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& A, const vector<int>& B)
             {
                 return A[1] < B[1];
             });
        
        int N = static_cast<int>(pairs.size());
        int Count = 0;
        int Memo = INT_MIN;
        
        for(int i = 0; i < N; i++)
        {
            if(Memo < pairs[i][0])
            {
                Memo = pairs[i][1];
                Count++;
            }
        }
        
        return Count;
    }
};