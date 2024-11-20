class Solution {
    const int a = 0;
    const int b = 1;
    const int c = 2;
public:
    int takeCharacters(string s, int k)
    {
        array<int, 3> Table;
        
        for(char& C : s)
        {
            Table[GetIndex(C)]++;
        }
        
        for(int& Num : Table)
        {
            if(Num < k)
                return -1;
        }
        
        const int N = static_cast<int>(s.size());        
        int j = 0;
        int Erase = 0;
        int MinMinute = INT_MAX;
        for(int i = 0; i < N; ++i)
        {
            int Index = GetIndex(s[i]);
            --Table[Index];
            ++Erase;
            
            while(Table[Index] < k)
            {
                ++Table[GetIndex(s[j])];
                ++j;
                --Erase;
            }
            
            MinMinute = min(MinMinute, N - Erase);
        }
        
        return MinMinute;
    }
    
private:
    int GetIndex(char C)
    {
        if(C == 'a')
            return a;
        
        if(C == 'b')
            return b;
        
        if(C == 'c')
            return c;
        
        return 0;
    }
};