class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if(numerator == 0)
            return "0";

        string Fraction;
        if((numerator < 0) ^ (denominator < 0))
            Fraction += '-';

        long long Dividend = llabs((long long)numerator);
        long long Divisor = llabs((long long)denominator);

        Fraction += to_string(Dividend / Divisor);
        long long Remainder = Dividend % Divisor;
        if(Remainder == 0)
            return Fraction;

        Fraction += '.';
        unordered_map<long long, int> Table;
        while(Remainder != 0)
        {
            if(Table.count(Remainder))
            {
                Fraction.insert(Table[Remainder], "(");
                Fraction += ')';
                break;
            }
            Table[Remainder] = Fraction.size();
            Remainder *= 10;
            Fraction += to_string(Remainder / Divisor);
            Remainder %= Divisor;
        }
        return Fraction;
    }
};