class Solution {
public:
    int maximumScore(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        int Left = k, Right = k;
        int MinNum = nums[k];
        int Result = nums[k];
        
        while(Left > 0 || Right < N - 1)
        {
            if(Left == 0 || (Right < N - 1 && nums[Right + 1] > nums[Left - 1]))
            {
                Right++;
            }
            else
            {
                Left--;
            }
            
            int Temp = min(nums[Right], nums[Left]);
            MinNum = min(MinNum, Temp);
            
            int CurrScore = MinNum * (Right - Left + 1);
            Result = max(Result, CurrScore);
        }
        
        return Result;
    }
};