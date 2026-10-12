class Solution {
public:
    int maxSum(vector<int>& nums, int k)
    {
        vector<int> Bit(30);
        long long Result = 0;
        long long Mod = 1e9 + 7;

        for(int& Num : nums)
        {
            for(int i = 0; i < 30; i++)
            {
                if(Num & (1 << i))
                    Bit[i]++;
            }
        }

        while(k-- > 0)
        {
            long long X = 0;
            for(int i = 0; i < 30; i++)
            {
                if(Bit[i] > 0)
                {
                    X |= 1LL << i;
                    Bit[i]--;
                }
            }
            Result = (Result + X * X) % Mod;
        }
        return (int)Result;
    }
};