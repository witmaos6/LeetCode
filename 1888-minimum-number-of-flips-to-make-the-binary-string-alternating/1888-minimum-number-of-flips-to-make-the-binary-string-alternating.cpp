class Solution {
public:
    int minFlips(string s)
    {
        const int N = static_cast<int>(s.size());
        string T = s + s;

        int Result = N;
        int Mis0 = 0;

        for(int i = 0; i < 2 * N; i++)
        {
            char Expected = (i % 2 == 0) ? '0' : '1';

            if(T[i] != Expected)
                Mis0++;

            if(i >= N)
            {
                int Left = i - N;
                char ExpLeft = (Left % 2 == 0) ? '0' : '1';
                if(T[Left] != ExpLeft)
                    Mis0--;
            }
            if(i >= N - 1)
            {
                int Mis1 = N - Mis0;
                Result = min(Result, min(Mis0, Mis1));
            }
        }
        return Result;
    }
};