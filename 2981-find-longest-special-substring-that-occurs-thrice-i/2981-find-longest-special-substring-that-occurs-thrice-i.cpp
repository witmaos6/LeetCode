class Solution {
public:
    int maximumLength(string s)
    {
        unordered_map<string, int> Table;
        
        const int N = static_cast<int>(s.size());
        string ResultStr;
        
        for(int i = 0; i < N; i++)
        {
            string SubStr;
            for(int j = i; j < N; j++)
            {
                if(SubStr.empty() || SubStr.back() == s[j])
                {
                    SubStr += s[j];
                    Table[SubStr]++;
                    
                    if(Table[SubStr] >= 3)
                    {
                        if(ResultStr.size() < SubStr.size())
                        {
                            ResultStr = SubStr;
                        }
                    }
                }
                else
                {
                    break;
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