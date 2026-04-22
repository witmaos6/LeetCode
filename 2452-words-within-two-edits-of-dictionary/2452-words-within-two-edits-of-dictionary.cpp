class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary)
    {
        const int W = queries[0].size();
        vector<string> Result;
        for(const string& Query : queries)
        {
            for(const string& Word : dictionary)
            {
                int DiffCount = 0; 
                for(int i = 0; i < W; i++)
                {
                    if(Query[i] != Word[i])
                    {
                        DiffCount++;
                    }
                }
                if(DiffCount <= 2)
                {
                    Result.push_back(Query);
                    break;
                }
            }
        }
        return Result;
    }
};