class Solution {
public:
    string fractionAddition(string expression)
    {
        stringstream ss(expression);
        char op;
        int a,b,c,d;
        int num,den;
        ss>>a;ss>>op;ss>>b;
        while(ss>>c)
        {
            ss>>op;
            ss>>d;
            num= a*d + b*c;
            den= b*d;
            a= num/__gcd(abs(num),abs(den));
            b= den/__gcd(abs(num),abs(den));
        }
        c=__gcd(abs(a),abs(b));
        a=a/c;
        b=b/c;
        return to_string(a)+'/'+to_string(b);
    }
};