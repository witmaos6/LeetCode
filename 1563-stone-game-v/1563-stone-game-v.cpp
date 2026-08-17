class Solution {
    vector<vector<int>> Memo;
    vector<int> Prefix;
    vector<int> StoneValue;
public:
    int stoneGameV(vector<int>& stoneValue)
    {
        StoneValue = stoneValue;
        const int N = stoneValue.size();

        Prefix.resize(N + 1);

        for(int i = 0; i < N; i++)
        {
            Prefix[i + 1] = Prefix[i] + StoneValue[i];
        }

        Memo.assign(N, vector<int>(N, -1));

        return DP(0, N - 1);
    }

private:
    int DP(int L, int R)
    {
        if(L >= R)
            return 0;

        if(Memo[L][R] != -1)
            return Memo[L][R];

        int Result = 0;

        int LeftSum = 0;
        int RightSum = Prefix[R + 1] - Prefix[L];

        for(int i = L; i < R; i++)
        {
            LeftSum += StoneValue[i];
            RightSum -= StoneValue[i];

            if(LeftSum < RightSum)
            {
                if(Result >= 2 * LeftSum)
                    continue;

                Result = max(Result, LeftSum + DP(L, i));
            }
            else if(LeftSum > RightSum)
            {
                if(Result >= 2 * RightSum)
                    break;
                
                Result = max(Result, RightSum + DP(i + 1, R));
            }
            else 
            {
                Result = max({Result, LeftSum + DP(L, i), RightSum + DP(i + 1, R)});
            }
        }

        return Memo[L][R] = Result;
    }
};