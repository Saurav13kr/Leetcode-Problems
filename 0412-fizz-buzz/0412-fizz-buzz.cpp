class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> c;
        for (int i=1; i<=n; i++) {
            if (!(i % 3)) {
                if (!(i % 5))
                    c.push_back("FizzBuzz");
                else
                    c.push_back("Fizz");
            }
            else if (!(i % 5))
                c.push_back("Buzz");
            else
                c.push_back(to_string(i));
        }
        return c;
    }
};