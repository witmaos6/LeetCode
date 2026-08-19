class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats)
    {
        unordered_map<int, vector<bool>> Table;
        for(vector<int>& Reserve : reservedSeats)
        {
            if(Reserve[1] != 1 && Reserve[1] != 10)
            {
                int Seat = Reserve[1];
                vector<bool>& Flags = Table[Reserve[0]];
                if(Flags.empty())
                {
                    Flags.resize(4);
                }
                if(Seat == 2 || Seat == 3)
                {
                    Flags[0] = true;
                }
                else if(Seat == 4 || Seat == 5)
                {
                    Flags[1] = true;
                }
                else if(Seat == 6 || Seat == 7)
                {
                    Flags[2] = true;
                }
                else if(Seat == 8 || Seat == 9)
                {
                    Flags[3] = true;
                }
            }
        }

        int Possible = n << 1;
        for(auto&[Row, Flags] : Table)
        {
            int Count = 0;
            for(bool Flag : Flags)
            {
                if(Flag)
                    Count++;
            }

            if(Count >= 3 || (Flags[0] && Flags[2]) || (Flags[1] && Flags[2]) || (Flags[1] && Flags[3]))
            {
                Possible -= 2;
            }
            else
            {
                Possible -= 1;
            }
        }
        return Possible;
    }
};