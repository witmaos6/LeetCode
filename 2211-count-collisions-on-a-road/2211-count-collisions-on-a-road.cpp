class Solution {
public:
    int countCollisions(string directions)
    {
        const int N = static_cast<int>(directions.size());

        if(N == 1)
            return 0;

        int L = 0;
        int R = N - 1;
        while(directions[L] == 'L')
        {
            L++;
        }
        while(directions[R] == 'R')
        {
            R--;
        }

        if(L >= R)
            return 0;

        int Count = 0;
        while(L <= R)
        {
            Count += directions[L] != 'S';
            L++;
        }
        return Count;
    }
};