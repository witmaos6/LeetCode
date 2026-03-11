class Solution {
public:
    int bitwiseComplement(int n)
    {
        if(n == 0)
            return 1;
            
        vector<int> Bits;
        while(n > 0)
        {
            Bits.push_back(n & 1);
            n >>= 1;
        }

        int Complement = 0;
        int Binary = 0;
        for(int& Bit : Bits)
        {
            Complement += (Bit == 0) ? pow(2, Binary) : 0;
            Binary++;
        }
        return Complement;
    }
};