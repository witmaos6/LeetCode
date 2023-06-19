class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
    {
        const int N = static_cast<int>(queries.size());
        const int ArrSize = static_cast<int>(arr.size());
        
        for(int i = 1; i < ArrSize; i++)
        {
            arr[i] ^= arr[i - 1];
        }
        
        vector<int> Results(N);
        
        for(int i = 0; i < N; i++)
        {
            int Begin = queries[i][0];
            int End = queries[i][1];
            
            if(Begin > 0)
            {
                Results[i] = arr[End] ^ arr[Begin - 1];
            }
            else
            {
                Results[i] = arr[End];
            }
        }
        
        return Results;
    }
};