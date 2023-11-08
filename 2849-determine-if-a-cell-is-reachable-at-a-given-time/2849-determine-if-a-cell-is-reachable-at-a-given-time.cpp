class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        int XDist = abs(sx - fx);
        int YDist = abs(sy - fy);
        int Dist = max(XDist, YDist);
        
        if(Dist > t)
        {
            return false;
        }
        if(Dist == 0 && t == 1)
        {
            return false;
        }
        
        return true;
    }
};