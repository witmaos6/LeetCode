class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs)
    {
        vector<vector<int>> Right(n + 1);
        for(const vector<int>& Pair : conflictingPairs)
        {
            Right[max(Pair[0], Pair[1])].push_back(min(Pair[0], Pair[1]));
        }

        long long Result = 0;
        vector<long long> Left = {0, 0};
        vector<long long> Bonus(n + 1);

        for(int R = 1; R <= n; R++)
        {
            for(int L_Value : Right[R])
            {
                if(L_Value > Left[0])
                {
                    Left = {static_cast<long long>(L_Value), Left[0]};
                }
                else if(L_Value > Left[1])
                {
                    Left = {Left[0], static_cast<long long>(L_Value)};
                }
            }

            Result += R - Left[0];
            if(Left[0] > 0)
            {
                Bonus[Left[0]] += Left[0] - Left[1];
            }
        }

        long long Max_Bonus = 0;
        for(long long B : Bonus)
        {
            Max_Bonus = max(Max_Bonus, B);
        }
        return Result + Max_Bonus;
    }
};