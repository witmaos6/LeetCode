class Solution {
    using Position = pair<int, int>;
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions)
    {
        const int N = static_cast<int>(positions.size());
        
        vector<Position> Robots(N);
        for(int i = 0; i < N; i++)
        {
            Robots[i] = {positions[i], i};
        }
        sort(Robots.begin(), Robots.end(), greater<>());
        
        stack<int> St;
        for(auto&[Pos, Index] : Robots)
        {
            if(directions[Index] == 'L')
            {
                St.push(Index);
            }
            else
            {
                while(!St.empty() && healths[Index] > 0)
                {
                    int i = St.top();
                    int Diff = healths[i] - healths[Index];
                    
                    if(Diff > 0)
                    {
                        healths[i]--;
                        healths[Index] = 0;
                    }
                    else if(Diff < 0)
                    {
                        healths[i] = 0;
                        healths[Index]--;
                        St.pop();
                    }
                    else
                    {
                        healths[Index] = 0;
                        healths[i] = 0;
                        St.pop();
                    }
                }
            }
        }
        
        vector<int> Result;
        for(int Health : healths)
        {
            if(Health > 0)
                Result.push_back(Health);
        }
        
        return Result;
    }
};