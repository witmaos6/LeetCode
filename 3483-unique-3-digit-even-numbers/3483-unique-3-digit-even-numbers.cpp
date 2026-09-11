class Solution {
public:
    int totalNumbers(vector<int>& digits)
    {
        vector<int> Table(10);
        for(int& Digit : digits)
        {
            Table[Digit]++;
        }

        int Result = 0;

        for(int i = 1; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                for(int k = 0; k < 9; k += 2)
                {
                    Result += (Table[i] > 0) && (Table[j] > (i == j)) && (Table[k] > (i == k) + (j == k));
                }
            }
        }
        return Result;
    }
};