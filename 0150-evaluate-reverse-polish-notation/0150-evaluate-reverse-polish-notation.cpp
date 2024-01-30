class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> stk;
        
        for(string s: t) {
            if(s!= "+" && s != "-" && s != "*" && s != "/") stk.push(stoi(s));
            else {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();
                if(s == "+") stk.push(op1 + op2);
                if(s == "-") stk.push(op1 - op2);
                if(s == "*") stk.push(op1 * op2);
                if(s == "/") stk.push(op1 / op2);
            }
        } 
        return stk.top();
    }
};