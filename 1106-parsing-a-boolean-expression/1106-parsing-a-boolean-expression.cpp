class Solution {
private:
    char eval(char op, const string& res) {
        if (op == '!') {
            return (res[0] == 't') ? 'f' : 't';
        } 
        else if (op == '&') 
        {
            for (char c : res) {
                if (c == 'f') return 'f';
            }
            return 't';
        } 
        else if (op == '|') {
            for (char c : res) {
                if (c == 't') return 't';
            }
            return 'f';
        }
        return 'f';
    }

public:
    bool parseBoolExpr(string expression) {
        stack<char> exp;
        for (char c : expression) {
            if (c == ')') {
                string res;
                while (exp.top() != '(') {
                    res = exp.top() + res;
                    exp.pop();
                }
                exp.pop();
                char op = exp.top();
                exp.pop();
                exp.push(eval(op, res));
            }
            else if (c != ',') {
                exp.push(c);
            }
        }
        return exp.top() == 't';
    }
};