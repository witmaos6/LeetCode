class Solution {
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        const int Str1Size = static_cast<int>(str1.size());
        const int Str2Size = static_cast<int>(str2.size());
        if(Str1Size < Str2Size)
            return false;
        
        int Index = 0;
        
        for(int i = 0; i < Str1Size; ++i)
        {
            if(IsValid(str2[Index], str1[i]))
            {
                ++Index;
                if(Index >= Str2Size)
                {
                    break;
                }
            }
        }
        
        return (Index == Str2Size);
    }
    
private:
    bool IsValid(const char C, const char Increament)
    {
        if(C == Increament)
            return true;
        
        if(C == (Increament + 1))
            return true;
        
        if(C == 'a' && Increament == 'z')
            return true;
        
        return false;
    }
};