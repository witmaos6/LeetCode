class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {
        map<vector<int>, int> Table;
        int Result = 0;

        for(vector<int>& domino : dominoes)
        {
            if(domino[0] > domino[1])
            {
                swap(domino[0], domino[1]);
            }
            Table[domino]++;
            Result += (Table[domino] - 1);
        }

        return Result;
    }
};