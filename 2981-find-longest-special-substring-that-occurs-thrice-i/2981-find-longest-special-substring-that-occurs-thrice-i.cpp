class Solution {
public:
    int maximumLength(string s)
    {
        unordered_map<string, int> Table;
        
        const int N = static_cast<int>(s.size());
        
        for(int i = 0; i < N; i++)
        {
            string SubStr;
            for(int j = i; j < N; j++)
            {
                if(SubStr.empty() || SubStr.back() == s[j])
                {
                    SubStr += s[j];
                    Table[SubStr]++;
                }
                else
                {
                    break;
                }
            }
        }
        
        string ResultStr;
        for(auto&[SubStr, Freq] : Table)
        {
            if(Freq >= 3)
            {
                if(ResultStr.empty() || ResultStr.size() < SubStr.size())
                {
                    ResultStr = SubStr;
                }
            }
        }
        
        if(ResultStr.size() == 0)
        {
            return -1;
        }
        return ResultStr.size();
    }
};