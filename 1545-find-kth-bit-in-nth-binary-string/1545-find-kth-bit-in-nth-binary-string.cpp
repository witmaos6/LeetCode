class Solution {
public:
    char findKthBit(int n, int k)
    {
        string Bits = "0";
        for(int i = 0; i < n; i++)
        {
            string Post = PostBit(Bits);
            Bits = Bits + '1' + Post;
        }
        return Bits[k - 1];
    }

private:
    string PostBit(string Bits)
    {
        for(char& Bit : Bits)
        {
            if(Bit == '0')
            {
                Bit = '1';
            }
            else if(Bit == '1')
            {
                Bit = '0';
            }
        }
        reverse(Bits.begin(), Bits.end());
        return Bits;
    }
};