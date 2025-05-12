class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits)
    {
        vector<int> Table(10);
        for(int& Digit : digits)
        {
            Table[Digit]++;
        }
        vector<int> Result;

        for(int Num = 100; Num < 1000; Num++)
        {
            if((Num & 1) == 1)
                continue;
                
            string NumToStr = to_string(Num);
            vector<int> StrTable(10);
            for(char& C : NumToStr)
            {
                StrTable[C - '0']++;
            }
            bool bPossible = true;
            for(int i = 0; i < 10; i++)
            {
                if(StrTable[i] > Table[i])
                {
                    bPossible = false;
                    break;
                }
            }
            if(bPossible)
            {
                Result.push_back(Num);
            }
        }
        return Result;
    }
};