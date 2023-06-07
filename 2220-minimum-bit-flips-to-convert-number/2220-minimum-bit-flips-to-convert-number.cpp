class Solution {
public:
    int minBitFlips(int start, int goal)
    {
        int N = start ^ goal;
        int Count = 0;
        
        while(N > 0)
        {
            N = N & (N - 1);
            Count++;
        }
        
        return Count;
    }
};