class Solution {
public:
    int smallestIndex(vector<int>& nums)
    {
        const int N = nums.size();
        for(int i = 0; i < N; i++)
        {
            if(DigitSum(nums[i]) == i)
            {
                return i;
            }
        }
        return -1;
    }
private:
    int DigitSum(int Num)
    {
        int Sum = 0;
        while(Num > 0)
        {
            Sum += Num % 10;
            Num /= 10;
        }
        return Sum;
    }
};