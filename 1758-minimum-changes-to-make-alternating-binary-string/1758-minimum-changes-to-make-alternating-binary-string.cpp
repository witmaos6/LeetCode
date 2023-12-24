class Solution {
public:
    int minOperations(string s)
    {
        int Result = min(GetMinOperations(s, '0'), GetMinOperations(s, '1'));
        
        return Result;
    }
    
private:
    int GetMinOperations(const string& S, char FirstChar)
    {
        int CountingOper = 0;
        char InputChar = FirstChar;
        
        for(char C : S)
        {
            if(C != InputChar)
            {
                CountingOper++;
            }
            
            InputChar = (InputChar == '0') ? '1' : '0';
        }
        
        return CountingOper;
    }
};