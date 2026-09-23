class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int N = static_cast<int>(nums.size());
        int Target = accumulate(nums.begin(), nums.end(), 0) - x;
        
        if(Target == 0)
        {
            return N;
        }
        else if(Target < 0)
        {
            return -1;
        }
        
        int Sum = 0;
        int MaxLength = 0;
        int j = 0;
        
        for(int i = 0; i < N; i++)
        {
            Sum += nums[i];
            
            while (i < N && Sum > Target)
            {
                Sum -= nums[j];
                j++;
            }
            
            if(Sum == Target)
            {
                MaxLength = max(MaxLength, i - j + 1);
            }
        }
        
        if(MaxLength == 0)
        {
            return -1;
        }
        return N - MaxLength;
    }
};