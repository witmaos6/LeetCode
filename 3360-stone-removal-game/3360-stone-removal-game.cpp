class Solution {
public:
    bool canAliceWin(int n)
    {
        int Missing = 55 - n;
        int unplayed = lround(sqrt(2 * Missing));
        return unplayed % 2 == 1;
    }
};