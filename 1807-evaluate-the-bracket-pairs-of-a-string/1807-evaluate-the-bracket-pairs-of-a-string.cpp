class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge)
    {
        unordered_map<string, string> Table;

        for(vector<string>& Word : knowledge)
        {
            Table[Word[0]] = Word[1];
        }
        
        string Result;
        bool Flag = false;
        string Key;
        for(char& C : s)
        {
            if(C == '(')
            {
                Flag = true;
            }
            else if(C == ')')
            {
                Flag = false;
                
                if(Table.count(Key))
                {
                    Result += Table[Key];
                }
                else
                {
                    Result += '?';
                }
                Key.clear();
            }
            else
            {
                if(Flag)
                {
                    Key += C;
                }
                else
                {
                    Result += C;
                }
            }
        }
        return Result;
    }
};