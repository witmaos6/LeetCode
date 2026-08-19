class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats)
    {
        unordered_map<int, vector<int>> Table;
        for(vector<int>& Reserve : reservedSeats)
        {
            if(Reserve[1] != 1 && Reserve[1] != 10)
            {
                Table[Reserve[0]].push_back(Reserve[1]);
            }
        }

        int Possible = n << 1;
        for(auto&[Row, Seats] : Table)
        {
            array<bool, 4> Flags = {false};
            for(int& Seat : Seats)
            {
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

            int Count = 0;
            for(bool Flag : Flags)
            {
                if(Flag)
                    Count++;
            }
            if(Count == 0)
                continue;

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