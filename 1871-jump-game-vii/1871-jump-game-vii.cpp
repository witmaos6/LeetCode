class Solution
{
    const char Valid = '0';
    int N = 0;
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        N = static_cast<int>(s.size());

        if(s[0] == '1')
            return false;

        int Far = 0;
        queue<int> Location;
        Location.push(0);

        while(!Location.empty())
        {
            int Index = Location.front();
            Location.pop();

            int Begin = max(Far, Index + minJump);
            int End = min(Index + maxJump, N - 1);

            for(int i = Begin; i <= End; i++)
            {
                if(s[i] == Valid)
                {
                    if(i == N - 1)
                        return true;

                    Location.push(i);
                }
            }
            Far = End + 1;
        }

        return false;
    }
};