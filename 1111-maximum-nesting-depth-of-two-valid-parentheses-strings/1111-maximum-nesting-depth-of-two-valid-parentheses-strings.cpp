class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        int Depth = 0;
        vector<int> Result;
        for(char& C : seq)
        {
            if(C == '(')
            {
                Depth++;
                Result.push_back(Depth & 1);
            }
            else if(C == ')')
            {
                Result.push_back(Depth & 1);
                Depth--;
            }
        }
        return Result;
    }
};