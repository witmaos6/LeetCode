class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        const int N = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());
        long long j = 0, Sum = 0, Left = 0;
        
        for(int i = 0; i < N; i++)
        {
            Sum += nums[i];
            
            while((i - j + 1) * nums[i] - Sum > k)
            {
                Sum -= nums[j];
                j++;
            }
            
            Left = max(Left, i - j + 1);
        }
              
        return Left;
    }
};