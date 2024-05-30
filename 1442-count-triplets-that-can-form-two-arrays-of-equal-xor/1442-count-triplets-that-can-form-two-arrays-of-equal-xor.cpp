class Solution {
public:
    int countTriplets(vector<int>& arr)
    {
        const int N = static_cast<int>(arr.size());
        
        int Count = 0;
                
        for(int Begin = 0; Begin < N - 1; Begin++)
        {
            int A = 0;
            for(int i = Begin; i < N - 1; i++)
            {
                A ^= arr[i];
                int B = 0;
                for(int j = i + 1; j < N; j++)
                {
                    B ^= arr[j];
                    if(A == B)
                    {
                        Count++;
                    }
                }
            }
        }
        
        
        return Count;
    }
};