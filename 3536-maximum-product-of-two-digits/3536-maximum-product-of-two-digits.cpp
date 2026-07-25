class Solution {
public:
    int maxProduct(int n)
    {
        int Max1 = -1;
        int Max2 = -1;
        string Str = to_string(n);

        for(char& C : Str)
        {
            int Num = C - '0';

            if(Max1 == -1)
            {
                Max1 = Num;
            }
            else if(Max1 <= Num)
            {
                Max2 = Max1;
                Max1 = Num;
            }
            else if(Max2 < Num)
            {
                Max2 = Num;
            }
        }
        return Max1 * Max2;
    }
};