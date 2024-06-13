class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        const int N = static_cast<int>(seats.size());
        
        int Result = 0;
        for(int i = 0; i < N; i++)
        {
            Result += abs(seats[i] - students[i]);
        }
        
        return Result;
    }
};