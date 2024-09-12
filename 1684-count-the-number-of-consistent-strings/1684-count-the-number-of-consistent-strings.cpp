class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words)
    {
        vector<int> Table(26);
        for(char C : allowed)
        {
            Table[C - 'a']++;
        }
        
        int Count = 0;
        for(string& Word : words)
        {
            bool Flag = true;
            for(char C : Word)
            {
                if(Table[C - 'a'] == 0)
                {
                    Flag = false;
                    break;
                }
            }
            
            if(Flag)
            {
                Count++;
            }
        }
        
        return Count;
    }
};