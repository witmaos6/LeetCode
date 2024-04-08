class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches)
    {
        int CountSquare = 0;
        int CountCircular = 0;
        
        for(int Student : students)
        {
            if(Student == 1)
            {
                CountSquare++;
            }
            else if(Student == 0)
            {
                CountCircular++;
            }
        }
        
        for(int Sandwich : sandwiches)
        {
            if(Sandwich == 1)
            {
                if(CountSquare > 0)
                {
                    CountSquare--;
                }
                else
                {
                    return CountCircular;
                }
            }
            else if(Sandwich == 0)
            {
                if(CountCircular > 0)
                {
                    CountCircular--;
                }
                else
                {
                    return CountSquare;
                }
            }
        }
        return 0;
    }
};