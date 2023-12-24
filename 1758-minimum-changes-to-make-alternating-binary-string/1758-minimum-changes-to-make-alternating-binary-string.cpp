class Solution {
public:
    int minOperations(string s)
    {
        int Count10 = 0;
        char InputChar = '1';
        
        for(char C : s)
        {
            if(C == InputChar)
            {
                Count10++;
            }
            InputChar = (InputChar == '1') ? '0' : '1';
        }
        
        int Count01 = s.size() - Count10;
        
        return min(Count10, Count01);
    }
};