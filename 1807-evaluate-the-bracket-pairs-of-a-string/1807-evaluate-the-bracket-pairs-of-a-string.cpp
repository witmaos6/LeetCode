class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge)
    {
        unordered_map<string, string> Table;

        for(vector<string>& pair : knowledge)
        {
            Table[pair[0]] = pair[1];
        }

        string Result;
        int N = static_cast<int>(s.size());

        for(int i = 0; i < N; i++)
        {
            if(s[i] == '(')
            {
                i++;
                string Temp;
                while(s[i] != ')')
                {
                    Temp += s[i];
                    i++;
                }

                if(Table.find(Temp) != Table.end())
                {
                    Result += Table[Temp];
                }
                else
                {
                    Result += '?';
                }
            }
            else
            {
                Result += s[i];
            }
        }
        
        return Result;
    }
};