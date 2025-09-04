class Solution {
public:
    int findClosest(int x, int y, int z)
    {
        int XStep = abs(x - z);
        int YStep = abs(y - z);
        if(XStep < YStep)
            return 1;
        else if(XStep > YStep)
            return 2;

        return 0;
    }
};