class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int Max1 = INT_MIN;
        int Max2 = INT_MIN;

        for(int& Num : nums)
        {
            if(Max1 == INT_MIN)
            {
                Max1 = Num;
            }
            else if(Max1 < Num)
            {
                Max2 = Max1;
                Max1 = Num;
            }
            else if(Max2 < Num)
            {
                Max2 = Num;
            }
        }
        return (Max1 - 1) * (Max2 - 1);
    }
};