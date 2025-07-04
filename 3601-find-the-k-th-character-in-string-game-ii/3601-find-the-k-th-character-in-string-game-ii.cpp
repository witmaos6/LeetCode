class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations)
    {
        vector<long long> Lengths;
        long long Len = 1;

        for(int Operation : operations)
        {
            Len *= 2;
            Lengths.push_back(Len);
            if(Len >= k)
                break;
        }

        int Shift = 0;
        const int LengthSize = static_cast<int>(Lengths.size());
        for(int i = LengthSize - 1; i >= 0; i--)
        {
            long long Half = Lengths[i] / 2;
            int Operation = operations[i];
            if(k > Half)
            {
                k -= Half;
                if(Operation == 1)
                {
                    Shift++;
                }
            }
        }

        return static_cast<char>((('a' - 'a' + Shift) % 26) + 'a');
    }
};