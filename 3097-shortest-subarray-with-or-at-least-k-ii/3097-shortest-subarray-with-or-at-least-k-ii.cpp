class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        array<int, 32> BitCount{};
        
        int CurrentOR = 0;
        int Left = 0;
        int MinLength = INT_MAX;
        
        for (int Right = 0; Right < N; ++Right)
        {
            CurrentOR |= nums[Right];
            
            for (int Bit = 0; Bit < 32; ++Bit)
            {
                if (nums[Right] & (1 << Bit))
                {
                    BitCount[Bit]++;
                }
            }
            
            while (Left <= Right && CurrentOR >= k)
            {
                MinLength = min(MinLength, Right - Left + 1);
                
                int UpdatedOR = 0;
                for (int Bit = 0; Bit < 32; ++Bit)
                {
                    if (nums[Left] & (1 << Bit))
                    {
                        --BitCount[Bit];
                    }
                    if (BitCount[Bit] > 0)
                    {
                        UpdatedOR |= (1 << Bit);
                    }
                }
                
                CurrentOR = UpdatedOR;
                Left++;
            }
        }
        
        return MinLength == INT_MAX ? -1 : MinLength;
    }
};