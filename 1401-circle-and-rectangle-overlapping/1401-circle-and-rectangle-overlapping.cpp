class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        int X = clamp(xCenter, x1, x2) - xCenter;
        int Y = clamp(yCenter, y1, y2) - yCenter;

        return X * X + Y * Y <= radius * radius;
    }
};