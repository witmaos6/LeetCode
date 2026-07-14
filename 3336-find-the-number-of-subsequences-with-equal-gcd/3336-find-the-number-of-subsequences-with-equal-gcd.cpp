class Solution {
public:
    int subsequencePairCount(vector<int>& nums)
    {
        const int Mod = 1e9 + 7;
        const int N = nums.size();
        int Max = *max_element(nums.begin(), nums.end());

        vector<vector<int>> Memo(Max + 1, vector<int>(Max + 1));
        Memo[0][0] = 1;

        for(int Num : nums)
        {
            vector<vector<int>> New(Max + 1, vector<int>(Max + 1));

            for(int GCD1 = 0; GCD1 <= Max; GCD1++)
            {
                int NewGCD1 = gcd(GCD1, Num);

                for(int GCD2 = 0; GCD2 <= Max; GCD2++)
                {
                    if(Memo[GCD1][GCD2] == 0)
                        continue;
                    
                    int Ways = Memo[GCD1][GCD2];
                    int NewGCD2 = gcd(GCD2, Num);

                    New[GCD1][GCD2] = (New[GCD1][GCD2] + Ways) % Mod;

                    New[NewGCD1][GCD2] = (New[NewGCD1][GCD2] + Ways) % Mod;

                    New[GCD1][NewGCD2] = (New[GCD1][NewGCD2] + Ways) % Mod;
                }
            }
            Memo = New;
        }

        int Result = 0;
        for(int GCDVal = 1; GCDVal <= Max; GCDVal++)
        {
            Result = (Result + Memo[GCDVal][GCDVal]) % Mod;
        }
        return Result;
    }
};