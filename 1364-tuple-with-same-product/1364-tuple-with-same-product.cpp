class Solution {
public:
    int tupleSameProduct(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        if(N <= 3)
        {
            return 0;
        }

        unordered_map<int, int> ProductToNum;
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                ProductToNum[nums[i] * nums[j]]++;
            }
        }

        int Result = 0;
        for(auto&[Product, Num] : ProductToNum)
        {
            if(Num >= 2)
            {
                int Temp = Num;
                int Combinations = (Temp * (Temp - 1)) / 2;
                Result += Combinations * 8;
            }
        }

        return Result;
    }
};