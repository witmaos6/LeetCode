class Solution {
public:
    vector<int> sumZero(int n)
    {
        vector<int> Nums(n);
        int Negative = -(n / 2);
        int Index = 0;
        while(Index < (n / 2))
        {
            Nums[Index] = Negative;
            Negative++;
            Index++;
        }
        if((n & 1) == 1)
        {
            Nums[Index] = 0;
            Index++;
        }
        int Positive = 1;
        while(Index < n)
        {
            Nums[Index] = Positive;
            Positive++;
            Index++;
        }
        return Nums;
    }
};