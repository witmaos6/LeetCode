class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        int DX = coordinates[1][0] - coordinates[0][0];
        int DY = coordinates[1][1] - coordinates[0][1];
        
        for(vector<int>& Point : coordinates)
        {
            int SlopeX = DX * (Point[1] - coordinates[0][1]);
            int SlopeY = DY * (Point[0] - coordinates[0][0]);
            
            if(SlopeX != SlopeY)
            {
                return false;
            }
        }
        
        return true;
    }
};