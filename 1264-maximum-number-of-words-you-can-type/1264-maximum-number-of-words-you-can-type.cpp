class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        vector<bool> Table(26);
        for(char& C : brokenLetters)
        {
            Table[C - 'a'] = true;
        }
        stringstream Stream(text);
        string Word;
        int Count = 0;
        while(Stream >> Word)
        {
            bool Can = true;
            for(char& C : Word)
            {
                if(Table[C - 'a'])
                {
                    Can = false;
                    break;
                }
            }
            if(Can)
            {
                Count++;
            }
        }
        return Count;
    }
};