class Solution {
public:
    int minElement(vector<int>& nums)
    {
        int Min = INT_MAX;
        for(int& Num : nums)
        {
            int Sum = 0;
            while(Num > 0)
            {
                Sum += Num % 10;
                Num /= 10;
            }
            Min = min(Min, Sum);
        }
        return Min;
    }
};