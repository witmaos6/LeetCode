class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int Index = static_cast<int>(digits.size()) - 1;

        digits[Index] += 1;

        while(digits[Index] > 9)
        {
            if(Index == 0)
            {
                digits[Index] = 0;
                digits.insert(digits.begin(), 1);
            }
            else
            {
                digits[Index] = 0;
                Index--;
                digits[Index] += 1;
            }
        }
        return digits;
    }
};