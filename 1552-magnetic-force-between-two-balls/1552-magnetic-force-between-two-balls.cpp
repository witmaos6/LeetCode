class Solution {
public:
    int maxDistance(vector<int>& position, int m)
    {
        const int N = static_cast<int>(position.size());
        sort(position.begin(), position.end());
        
        int L = 1, R = (position.back() - position.front()) / (m - 1);
        int Result = 1;
        
        while(L <= R)
        {
            int Mid = (R + L) / 2;
            
            if(Traverse(position, Mid, m, N))
            {
                Result = Mid;
                L = Mid + 1;
            }
            else
            {
                R = Mid - 1;
            }
        }
        return Result;
    }
    
private:
    bool Traverse(vector<int>& Position, int Distance, int NrOfBall, const int N)
    {
        int PrevPosition = Position.front();
        int CountBall = 1;
        for(int i = 1; i < N; i++)
        {
            if(Position[i] - PrevPosition >= Distance)
            {
                PrevPosition = Position[i];
                CountBall++;
            }
            if(CountBall >= NrOfBall)
                return true;
        }
        return false;
    }
};