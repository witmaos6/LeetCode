class Solution {
public:
    int maximumLength(vector<int>& nums)
    {
        map<long long, int> Table;
        int OneCount = 0;
        for(int& Num : nums)
        {
            if(Num == 1)
            {
                OneCount++;
            }
            else
            {
                Table[Num]++;
            }
        }

        int Result = 1;
        if(OneCount >= 3)
        {
            Result = (OneCount & 1) ? OneCount : OneCount - 1;
        }
        for(const auto&[Num, Count] : Table)
        {
            if(Count >= 2)
            {
                int Length = 2;
                long long Pow = Num * Num;
                auto It = Table.find(Pow);

                while(It != Table.end())
                {
                    if(It->second == 1)
                    {
                        Length++;
                        It->second = 0;
                        break;
                    }
                    else if(It->second >= 2)
                    {
                        Length += 2;
                        It->second = 0;
                        Pow = Pow * Pow;
                        It = Table.find(Pow);
                    }
                }
                if((Length & 1) == 0)
                {
                    Length--;
                }
                Result = max(Result, Length);
            }
        }
        return Result;
    }
};