class Solution {
public:
    int minMoves(vector<int>& nums)
    {
        int Max = 0;
        int Sum = 0;
        for(int& Num : nums)
        {
            Sum += Num;
            Max = max(Max, Num);
        }
        const int N = nums.size();

        return Max * N - Sum;
    }
};