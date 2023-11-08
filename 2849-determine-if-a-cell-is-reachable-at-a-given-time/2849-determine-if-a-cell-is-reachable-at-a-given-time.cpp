class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        int XDist = abs(sx - fx);
        int YDist = abs(sy - fy);
        int Diagonal = min(XDist, YDist);
        
        if(OverMinLength(XDist, YDist, t) || ((sx == fx && sy == fy) && t == 1))
        {
            return false;
        }
        
        return true;
    }
    
private:
    bool OverMinLength(int XDist, int YDist, int Time)
    {
        int MaxLength = max(XDist, YDist);
        return MaxLength > Time;
    }
};