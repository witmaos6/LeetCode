class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        if(k == 0)
            return 0;
        
        const int N = static_cast<int>(nums.size());
        int Left = 0;
        int Right = 0;
        int Product = 1;
        int Count = 0;
        
        while(Right < N)
        {
            Product *= nums[Right];
            Right++;
            
            while(Left < Right && Product >= k)
            {
                Product /= nums[Left];
                Left++;
            }
            
            Count += (Right - Left);
        }
        
        return Count;
    }
};