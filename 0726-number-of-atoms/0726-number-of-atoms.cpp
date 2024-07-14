class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<string, int>> stk;

        int n = formula.size();
        int i = 0;
        while(i<n){
            if(formula[i] >= 'A' && formula[i] <= 'Z'){
                // find element and immediate count
                string che;
                che.push_back(formula[i++]);

                while(i < n && formula[i] >= 'a' && formula[i] <= 'z'){
                    che.push_back(formula[i++]);
                }

                string count;

                while(i<n && formula[i] >= '0' && formula[i] <= '9'){
                    count.push_back(formula[i++]);
                }
                stk.push({che, count.size() == 0 ? 1 : stoi(count)});
            }else if(formula[i] == ')'){
   
                i++;
                vector<pair<string, int>> curr;
                while(!stk.empty() && stk.top().first != "("){
                    curr.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();

                string countStr;
                while(i<n && formula[i] >= '0' && formula[i] <= '9'){
                    countStr.push_back(formula[i++]);
                }
                int count = countStr.size() == 0 ? 1 : stoi(countStr);
                for(pair<string, int> pr: curr){
                    pr.second = pr.second * count;
                    stk.push(pr);
                }
            }
            else{
                // just push the opening bracket
                stk.push({formula.substr(i++, 1), 0});
            }
        }
        
        map<string, int> ump;
        while(!stk.empty()){
            ump[stk.top().first] += stk.top().second;
            stk.pop();
        }
        string ans ;
        
        // concatinating the elements
        for(auto itr: ump){
            ans+=(itr.first);
            if(itr.second != 1)
                ans+=to_string(itr.second);
        }
        
        return ans;
    }
};