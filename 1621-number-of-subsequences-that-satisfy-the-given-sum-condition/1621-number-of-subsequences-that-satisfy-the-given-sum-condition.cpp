class Solution {
    const int Mod = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target)
    {
        const int N = static_cast<int>(nums.size());
        
        vector<int> Pow(N + 1);
        Pow[0] = 1;
        
        for(int i = 1; i <= N; i++)
        {
            Pow[i] = (Pow[i - 1] << 1) % Mod;
        }
        
        sort(nums.begin(), nums.end());
        long long Result = 0;
        int L = 0, R = N - 1;
        
        while(L <= R)
        {
            if(nums[L] + nums[R] <= target)
            {
                Result += Pow[R - L];
                Result %= Mod;
                L++;
            }
            else
            {
                R--;
            }
        }
        
        return static_cast<int>(Result);
    }
};