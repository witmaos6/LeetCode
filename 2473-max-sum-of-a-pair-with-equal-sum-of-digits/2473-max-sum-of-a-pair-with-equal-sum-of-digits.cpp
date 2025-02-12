class Solution {
public:
    int maximumSum(vector<int>& nums)
    {
        vector<int> DigitSumToMaxNum(82, -1);
        int MaxSum = -1;
        
        for(int& Num : nums)
        {
            int DigitSum = GetDigitSum(Num);

            if(DigitSumToMaxNum[DigitSum] != -1)
            {
                int CurrSum = DigitSumToMaxNum[DigitSum] + Num;
                MaxSum = max(MaxSum, CurrSum);

                DigitSumToMaxNum[DigitSum] = max(DigitSumToMaxNum[DigitSum], Num);
            }
            else
            {
                DigitSumToMaxNum[DigitSum] = Num;
            }
        }

        return MaxSum;
    }

private:
    int GetDigitSum(int Num)
    {
        int Sum = 0;
        while(Num > 0)
        {
            Sum += (Num % 10);
            Num /= 10;
        }
        return Sum;
    }
};