class Solution {
public:
    int findNumbers(vector<int>& nums)
    {
        int Count = 0;
        for(int& Num : nums)
        {
            if(IsEvenNumberOfDigits(Num))
            {
                Count++;
            }
        }
        return Count;
    }
private:
    bool IsEvenNumberOfDigits(int Num)
    {
        int Count = 0;
        while(Num > 0)
        {
            Num /= 10;
            Count++;
        }
        return (Count & 1) == 0;
    }
};