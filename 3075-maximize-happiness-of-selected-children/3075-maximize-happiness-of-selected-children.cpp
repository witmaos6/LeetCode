class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), greater<>());

        long long Result = 0;
        for(int i = 0; i < k; i++)
        {
            long long Num = max(0, happiness[i] - i);
            Result += Num;
        }
        return Result;
    }
};