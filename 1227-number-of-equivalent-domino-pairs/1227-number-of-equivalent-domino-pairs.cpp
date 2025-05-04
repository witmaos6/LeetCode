class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {
        array<int, 100> Table = {0};
        int Result = 0;

        for(vector<int>& Domino : dominoes)
        {
            int Temp = 0;
            if(Domino[0] > Domino[1])
            {
                Temp += Domino[1];
                Temp += Domino[0] * 10;
            }
            else
            {
                Temp += Domino[0];
                Temp += Domino[1] * 10;
            }
            Table[Temp]++;
            Result += (Table[Temp] - 1);
        }

        return Result;
    }
};