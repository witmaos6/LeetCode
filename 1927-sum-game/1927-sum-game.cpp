class Solution {
public:
    bool sumGame(string num)
    {
        const int N = num.size();
        int N2 = N >> 1;

        int Diff = 0;
        for(int i = 0; i < N; i++)
        {
            char C = num[i];
            bool isQ = C == '?';
            bool Half = i < N2;

            int SGN = (Half << 1) - 1;
            int D = (-isQ & 9) + (-!isQ & (C - '0') << 1);
            Diff += SGN * D;
        }
        return Diff != 0;
    }
};