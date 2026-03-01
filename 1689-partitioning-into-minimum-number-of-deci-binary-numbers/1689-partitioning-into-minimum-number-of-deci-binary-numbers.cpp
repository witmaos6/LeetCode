class Solution {
public:
    int minPartitions(string n)
    {
        char Result = '0';
        for(char& Decimal : n)
        {
            char Temp = Decimal;
            if(Temp > Result)
            {
                Result = Temp;
                if(Result == '9')
                    break;
            }
        }
        return Result - '0';
    }
};