class Solution {
public:
    int minimumRecolors(string blocks, int k)
    {
        int BlackCount = 0;
        int Result = INT_MAX;
        const int N = static_cast<int>(blocks.size());

        for(int i = 0; i < N; i++)
        {
            if(i - k >= 0 && blocks[i - k] == 'B')
            {
                BlackCount--;
            }
            if(blocks[i] == 'B')
            {
                BlackCount++;
            }
            Result = min(Result, k - BlackCount);
        }
        return Result;
    }
};