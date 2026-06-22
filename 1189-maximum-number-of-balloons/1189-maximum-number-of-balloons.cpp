class Solution {
public:
    int maxNumberOfBalloons(string text)
    {
        vector<int> Balloons(26);

        for(char& C : text)
        {
            if(IsBalloonChar(C))
            {
                Balloons[C - 'a']++;
            }
        }

        int OneChar = INT_MAX;
        int TwoChar = INT_MAX;
        for(int i = 0; i < 26; i++)
        {
            if(i == 'a' - 'a' || i == 'b' - 'a' || i == 'n' - 'a')
            {
                OneChar = min(OneChar, Balloons[i]);
            }
            if(i == 'l' - 'a' || i == 'o' - 'a')
            {
                TwoChar = min(TwoChar, Balloons[i] / 2);
            }
        }

        return min(OneChar, TwoChar);
    }
private:
    bool IsBalloonChar(char C)
    {
        if(C == 'a' || C == 'b' || C == 'l' || C == 'o' || C == 'n')
            return true;

        return false;
    }
};