class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int Result = 0;
        
        for(int i = 0; i < 32; i++)
        {
            int Sum = 0;
            for(const int& Num : nums)
            {
                Sum += (Num >> i) & 1;
            }
            Sum %= 3;
            Result |= Sum << i;
        }
        
        return Result;
    }
};