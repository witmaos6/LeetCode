class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        if(k == 0)
            return 0;
        
        const int N = static_cast<int>(nums.size());
        int Left = 0;
        int Product = 1;
        int Count = 0;
        
        for(int Right = 0; Right < N; Right++)
        {
            Product *= nums[Right];
            while(Left < Right + 1 && Product >= k)
            {
                Product /= nums[Left];
                Left++;
            }
            
            Count += (Right - Left) + 1;
        }
        
        return Count;
    }
};