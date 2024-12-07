class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations)
    {
        const int N = static_cast<int>(nums.size());
        int Left = 1;
        int Right = *max_element(nums.begin(), nums.end());
        
        while(Left < Right)
        {
            int Mid = Left + (Right - Left) / 2;
            
            long long DivideSum = 0;
            for(int i = 0; i < N; i++)
            {
                DivideSum += (nums[i] - 1) / Mid;
                if(DivideSum > maxOperations)
                {
                    break;
                }
            }
            
            if(DivideSum <= maxOperations)
            {
                Right = Mid;
            }
            else
            {
                Left = Mid + 1;
            }
        }
        
        return Right;
    }
};