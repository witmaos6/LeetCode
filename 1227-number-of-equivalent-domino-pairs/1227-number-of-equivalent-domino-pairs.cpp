class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {
        map<vector<int>, int> Table;

        for(vector<int>& domino : dominoes)
        {
            if(domino[0] > domino[1])
            {
                swap(domino[0], domino[1]);
            }
            Table[domino]++;
        }

        int Result = 0;
        for(auto&[Domino, Freq] : Table)
        {
            Result += (Freq * (Freq - 1)) / 2;
        }
        return Result;
    }
};