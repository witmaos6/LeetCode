class Solution {
public:
    bool checkValidString(string s)
    {
        int Low = 0, High = 0;
        for (char C : s)
        {
            Low += (C == '(') ? 1 : -1;
            High += (C != ')') ? 1 : -1;
            
            if (High < 0)
                return false;
            
            Low = max(Low, 0);
        }
        
        return Low == 0;
    }
};