class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts)
    {
        const int N = static_cast<int>(s.size());
        vector<int> CountShift(N + 1);

        for(vector<int>& Shift : shifts)
        {
            int Direction = (Shift[2] == 0) ? -1 : Shift[2];
            CountShift[Shift[0]] += Direction;
            CountShift[Shift[1] + 1] -= Direction;
        }

        partial_sum(CountShift.begin(), CountShift.end(), CountShift.begin());

        for(int i = 0; i < N; i++)
        {
            int Remain = (CountShift[i] + s[i] - 'a') % 26;

            s[i] = 'a' + Remain;
            if(s[i] < 'a')
            {
                s[i] += 26;
            }
        }
        
        return s;
    }
};