class Solution {
public:
    int findGCD(vector<int>& nums)
    {
        int Min = INT_MAX;
        int Max = INT_MIN;

        for(int& Num : nums)
        {
            Min = min(Min, Num);
            Max = max(Max, Num);
        }

        return gcd(Min, Max);
    }
};