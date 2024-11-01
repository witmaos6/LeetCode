class Solution {
public:
    string makeFancyString(string s)
    {
        string FancyString;
        
        int Count = 0;
        char LastC = '_';
        for(char C : s)
        {
            if(LastC == C)
            {
                Count++;
                
                if(Count >= 3)
                {
                    continue;
                }
            }
            else
            {
                LastC = C;
                Count = 1;
            }
            
            FancyString += C;
        }
        
        return FancyString;
    }
};