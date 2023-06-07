class Solution {
public:
    int minFlips(int a, int b, int c)
    {
        vector<bool> BitA = GetIntToBit(a);
        vector<bool> BitB = GetIntToBit(b);
        vector<bool> BitC = GetIntToBit(c);
        
        int CountFlips = 0;
        
        for(int i = 0; i < 32; i++)
        {
            if(BitC[i])
            {
                if(!BitA[i] && !BitB[i])
                    CountFlips++;
            }
            else
            {
                if(BitA[i])
                    CountFlips++;
                
                if(BitB[i])
                    CountFlips++;
            }
        }
        
        return CountFlips;
    }
    
private:
    vector<bool> GetIntToBit(int Num)
    {
        vector<bool> Bit(32);
        
        int Index = 31;
        
        while(Num > 0)
        {
            Bit[Index] = Num % 2;
            Num /= 2;
            
            Index--;
        }
        return Bit;
    }
};