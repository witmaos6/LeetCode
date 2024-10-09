class Solution {
public:
    int minAddToMakeValid(string s)
    {
        int OpenCount = 0;
        int Mismatch = 0;
        
        for(char C : s)
        {
            if(C == '(')
            {
                OpenCount++;
            }
            else if(C == ')')
            {
                if(OpenCount > 0)
                {
                    OpenCount--;
                }
                else
                {
                    Mismatch++;
                }
            }
        }
        
        return OpenCount + Mismatch;
    }
};