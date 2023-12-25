class Solution {
public:
    int numDecodings(string s)
    {
        if(s[0] == '0')
        {
            return 0;
        }
        
        const int N = static_cast<int>(s.size());
        
        int PrevPrev = 1;
        int Prev = (s.back() != '0') ? 1 : 0;
        int Curr = 0;
        
        for(int i = N - 2; i >= 0; i--)
        {
            if(s[i] == '0')
            {
                Curr = 0;
            }
            else 
            {
                Curr = Prev;
                if(ValidDecode(s, i))
                {
                    Curr += PrevPrev;
                }
            }
            PrevPrev = Prev;
            Prev = Curr;
        }
        
        return Prev;
    }
private:
    bool ValidDecode(string& S, int Index)
    {
        return (S[Index] == '1' || S[Index] == '2' && (S[Index + 1] <= '6'));
    }
};