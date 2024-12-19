class Solution {
public:
    int maxChunksToSorted(vector<int>& arr)
    {
        const int N = static_cast<int>(arr.size());
        
        int Count = 0;
        int Max = 0;
        for(int i = 0; i < N; i++)
        {
            if(Max < arr[i])
            {
                Max = arr[i];
            }
            if(Max == i)
            {
                Count++;
            }
        }
        return Count;
    }
};