class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr)
    {
        const int N = static_cast<int>(arr.size());
        
        int Left = 0;
        while(Left + 1 < N && arr[Left] <= arr[Left + 1])
        {
            Left++;
        }
        if(Left == N - 1)
            return 0;
        
        int Right = N - 1;
        while(Right > 0 && arr[Right - 1] <= arr[Right])
        {
            Right--;
        }
        
        int Result = min(N - Left - 1, Right);
        int i = 0, j = Right;
        while(i <= Left && j < N)
        {
            if(arr[i] <= arr[j])
            {
                Result = min(Result, j - i - 1);
                ++i;
            }
            else
            {
                ++j;
            }
        }
        
        return Result;
    }
};