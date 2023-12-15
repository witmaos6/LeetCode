class Solution {
    int N = 0;
    array<char, 12> SpecialChars = {'!','@','#','$','%','^','&','*','(',')','-','+'};
public:
    bool strongPasswordCheckerII(string password)
    {
        N = static_cast<int>(password.size());
        
        if(N < 8)
        {
            return false;
        }
        array<bool, 5> StrongCondition = {false, false, false, false, true};
        
        for(int i = 0; i < N; i++)
        {
            if(password[i] >= 'a' && password[i] <= 'z')
            {
                StrongCondition[0] = true;
            }
            else if(password[i] >= 'A' && password[i] <= 'Z')
            {
                StrongCondition[1] = true;
            }
            else if(password[i] >= '0' && password[i] <= '9')
            {
                StrongCondition[2] = true;
            }
            else if(IsSpecial(password[i]))
            {
                StrongCondition[3] = true;
            }
            
            if(password[i] == password[i + 1])
            {
                StrongCondition[4] = false;
            }
        }
        
        for(bool Condition : StrongCondition)
        {
            if(!Condition)
                return false;
        }
        return true;
    }
    
private:
    bool IsSpecial(const char C)
    {
        for(char SpecialChar : SpecialChars)
        {
            if(C == SpecialChar)
                return true;
        }
        return false;
    }
};