class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int CountZero = 0;
        long long TotalProduct = 1;
        int ZeroIndex = -1;
        
        for(int i = 0; i < N; i++)
        {
            if(nums[i] != 0)
            {
                TotalProduct *= nums[i];
            }
            else
            {
                CountZero++;
                ZeroIndex = i;
            }
        }
        
        if(CountZero >= 2)
        {
            fill(nums.begin(), nums.end(), 0);
            return nums;
        }
        
        if(CountZero == 1)
        {
            fill(nums.begin(), nums.end(), 0);
            nums[ZeroIndex] = TotalProduct;
            return nums;
        }
        
        for(int i = 0; i < N; i++)
        {
            nums[i] = TotalProduct / nums[i];
        }
        return nums;
    }
};