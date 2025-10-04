class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int N = static_cast<int>(height.size()) - 1;
        int L = 0;
        int R = N;
        int Result = 0;

        while(L < R)
        {
            int H = min(height[L], height[R]);
            Result = max(Result, H * N);
            N--;

            if(height[L] > height[R])
            {
                R--;
            }
            else
            {
                L++;
            }
        }
        return Result;
    }
};