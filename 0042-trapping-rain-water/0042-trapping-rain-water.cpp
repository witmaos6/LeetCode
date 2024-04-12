class Solution {
public:
    int trap(vector<int>& height)
    {
        int Left = 0;
        int Right = static_cast<int>(height.size()) - 1;
        int MaxLeft = INT_MIN;
        int MaxRight = INT_MIN;
        int Result = 0;
        
        while(Left < Right)
        {
            MaxLeft = max(MaxLeft, height[Left]);
            MaxRight = max(MaxRight, height[Right]);
            
            if(MaxLeft < MaxRight)
            {
                Result += MaxLeft - height[Left];
                Left++;
            }
            else
            {
                Result += MaxRight - height[Right];
                Right--;
            }
        }
        
        return Result;
    }
};