class Solution {
public:
    int numberOfBeams(vector<string>& bank)
    {
        const int N = static_cast<int>(bank.size());
        vector<int> Laser;
        Laser.reserve(N);
        for(int i = 0; i < N; i++)
        {
            int Count = 0;
            for(char& C : bank[i])
            {
                if(C == '1')
                {
                    Count++;
                }
            }
            if(Count > 0)
            {
                Laser.push_back(Count);
            }
        }

        int Result = 0;
        for(int i = 1; i < Laser.size(); i++)
        {
            Result += Laser[i] * Laser[i - 1];
        }
        return Result;
    }
};