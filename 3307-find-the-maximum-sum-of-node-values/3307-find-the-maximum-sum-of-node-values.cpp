class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges)
    {
        long long Result = 0;
        int N = 0;
        long long D = INT_MAX;
        for(int& Num : nums)
        {
            long long XOR = Num ^ k;
            Result += max((long long)Num, XOR);
            if(Num < XOR)
            {
                N = 1 - N;
            }
            D = min(D, abs(Num - XOR));
        }
        return Result - N * D;
    }
};