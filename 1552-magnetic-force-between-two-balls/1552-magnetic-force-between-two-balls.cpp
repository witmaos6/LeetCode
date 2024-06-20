class Solution {
public:
    int maxDistance(vector<int>& position, int m)
    {
        const int N = static_cast<int>(position.size());
        sort(position.begin(), position.end());
        
        m--;
        int L = 1, R = (position.back() - position.front()) / m;
        
        while(L <= R)
        {
            int Mid = (R + L) / 2;
            
            if(Traverse(position, N, Mid, m))
            {
                L = Mid + 1;
            }
            else
            {
                R = Mid - 1;
            }
        }
        return L - 1;
    }
    
private:
    bool Traverse(vector<int>& Position, const int N, const int Distance, int NrOfBall)
    {
        int PrevPosition = Position.front();
        for(int i = 1; i < N; i++)
        {
            if(Position[i] - PrevPosition >= Distance)
            {
                PrevPosition = Position[i];
                NrOfBall--;
            }
            if(NrOfBall <= 0)
                return true;
        }
        return false;
    }
};