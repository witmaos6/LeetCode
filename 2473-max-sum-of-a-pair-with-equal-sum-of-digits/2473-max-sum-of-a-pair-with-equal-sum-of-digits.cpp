class Solution {
public:
    int maximumSum(vector<int>& nums)
    {
        unordered_map<int, int> DigitSumToMaxNum;
        int MaxSum = -1;
        
        for(int& Num : nums)
        {
            int DigitSum = GetDigitSum(Num);

            if(DigitSumToMaxNum.find(DigitSum) == DigitSumToMaxNum.end())
            {
                DigitSumToMaxNum[DigitSum] = Num;
            }
            else
            {
                int CurrSum = DigitSumToMaxNum[DigitSum] + Num;
                MaxSum = max(MaxSum, CurrSum);

                DigitSumToMaxNum[DigitSum] = max(DigitSumToMaxNum[DigitSum], Num);
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