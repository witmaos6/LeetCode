class Solution {
public:
    double average(vector<int>& salary)
    {
        int MinSalary = 1e6;
        int MaxSalary = 0;
        int Sum = 0;

        for(int& Salary : salary)
        {
            Sum += Salary;
            MinSalary = min(MinSalary, Salary);
            MaxSalary = max(MaxSalary, Salary);
        }

        Sum -= (MinSalary + MaxSalary);
        double Result = static_cast<double>(Sum) / static_cast<double>(salary.size() - 2);
        return Result;
    }
};