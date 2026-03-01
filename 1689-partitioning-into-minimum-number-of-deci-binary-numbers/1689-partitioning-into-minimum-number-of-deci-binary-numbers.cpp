class Solution {
public:
    int minPartitions(string n)
    {
        char Result = '0';
        for(char& Decimal : n)
        {
            if(Decimal > Result)
            {
                Result = Decimal;
                if(Result == '9')
                    break;
            }
        }
        return Result - '0';
    }
};