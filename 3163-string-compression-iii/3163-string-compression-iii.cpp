class Solution {
public:
    string compressedString(string word)
    {
        const int Most = 9;
        string Comp;
        
        char LastChar = '_';
        int Length = 0;
        for(char C : word)
        {
            if(LastChar == C)
            {
                ++Length;
            }
            else
            {
                while(Length > 0)
                {
                    if(Length >= 9)
                    {
                        Comp += '9';
                    }
                    else
                    {
                        Comp += ('0' + Length);
                        
                    }
                    Comp += LastChar;
                    Length -= 9;
                }
                    
                LastChar = C;
                Length = 1;
            }
        }
        while(Length > 0)
        {
            if(Length >= 9)
            {
                Comp += '9';
            }
            else
            {
                Comp += ('0' + Length);

            }
            Comp += LastChar;
            Length -= 9;
        }
        
        return Comp;
    }
};