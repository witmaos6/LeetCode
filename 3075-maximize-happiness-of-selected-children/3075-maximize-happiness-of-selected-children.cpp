class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), greater<>());
        
        const int N = static_cast<int>(happiness.size());
        long long Result = 0;
        int Decrease = 0;
        for(int i = 0; i < k; i++)
        {
            long long Value = happiness[i] - Decrease;
            Value = (Value > 0) ? Value : 0;
            Result += Value;
            Decrease++;
        }
        
        return Result;
    }
};