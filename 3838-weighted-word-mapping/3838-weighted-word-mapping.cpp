class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights)
    {
        string Result;
        for(const string& Word : words)
        {
            int Sum = 0;
            for(const char& C : Word)
            {
                Sum += weights[C - 'a'];
            }

            Result += 'z' - (Sum % 26);
        }

        return Result;
    }
};