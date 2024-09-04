struct PairHash {
    std::size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

class Solution {
    using Point = pair<int, int>;
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        unordered_set<Point, PairHash> Table;
        for(vector<int>& Obstacle : obstacles)
        {
            Table.insert({Obstacle[0], Obstacle[1]});
        }
        
        Point CurrPoint = {0, 0};
        vector<vector<int>> Dir = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int Direction = 0;
        Point DirectionPoint = {0, 1};
        int MaxDistance = 0;
        
        for(int Command : commands)
        {
            if(Command == -1)
            {
                Direction = (Direction + 3) % 4;
                DirectionPoint.first = Dir[Direction][0];
                DirectionPoint.second = Dir[Direction][1];
            }
            else if(Command == -2)
            {
                Direction = (Direction + 1) % 4;
                DirectionPoint.first = Dir[Direction][0];
                DirectionPoint.second = Dir[Direction][1];
            }
            else
            {
                for(int i = 0; i < Command; i++)
                {
                    CurrPoint.first += DirectionPoint.first;
                    CurrPoint.second += DirectionPoint.second;
                    
                    if(Table.count({CurrPoint.first, CurrPoint.second}) >= 1)
                    {
                        CurrPoint.first -= DirectionPoint.first;
                        CurrPoint.second -= DirectionPoint.second;
                        break;
                    }
                    
                    int CurrX = CurrPoint.first * CurrPoint.first;
                    int CurrY = CurrPoint.second * CurrPoint.second;
                    MaxDistance = max(MaxDistance, CurrX + CurrY);
                }
            }
        }
        
        return MaxDistance;
    }
};