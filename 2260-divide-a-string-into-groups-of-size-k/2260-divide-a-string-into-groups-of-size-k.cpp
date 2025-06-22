class Solution {
public:
    vector<string> divideString(string s, int k, char fill)
    {
        const int N = static_cast<int>(s.size());
        int Mod = N % k;
        if(Mod > 0)
        {
            int NrOfAdd = k - Mod;
            for(int i = 0; i < NrOfAdd; i++)
            {
                s += fill;
            }
        }
        vector<string> Result;
        for(int i = 0; i < N; i += k)
        {
            Result.push_back(s.substr(i, k));
        }

        return Result;
    }
};