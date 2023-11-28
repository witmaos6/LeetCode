class Solution {
    const int Mod = 1e9 + 7;
public:
    int numberOfWays(string corridor)
    {
        const int N = static_cast<int>(corridor.size());
        long long Result = 1;
        int j = 0, Seat = 0;
        
        for(int i = 0; i < N; i++)
        {
            if(corridor[i] == 'S')
            {
                if(++Seat > 2 && (Seat & 1))
                {
                    Result = Result * (i - j) % Mod;
                }
                j = i;
            }
        }
        
        return (Seat % 2 == 0) && Seat > 0 ? Result : 0;
    }
};