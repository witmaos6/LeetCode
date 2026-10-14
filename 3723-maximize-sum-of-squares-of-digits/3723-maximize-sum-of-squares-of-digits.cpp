class Solution {
public:
    string maxSumOfSquares(int num, int sum)
    {
        if(sum > 9 * num)
            return "";
        
        string Result;

        while(num-- > 0)
        {
            int Digit = min(9, sum);
            Result += '0' + Digit;
            sum -= Digit;
        }
        return sum == 0 ? Result : "";
    }
};