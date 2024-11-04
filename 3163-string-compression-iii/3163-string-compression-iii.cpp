class Solution {
public:
    string compressedString(string word) {
        string newStr{""};
        int count{1};
        if (word.length() == 1) {
            newStr += to_string(1);
            newStr += word[0];
            return newStr;
        }
        for (int i{1}; i <= word.length(); i += 1) {

            if (word[i - 1] == word[i]) {
                count += 1;
            }
            if (count == 9) 
            {
                newStr += to_string(count);
                newStr += word[i - 1];
                i += 1;
                count = 1;
            } 
            else if (word[i] != word[i - 1]) {
                newStr += to_string(count);
                newStr += word[i - 1];
                count = 1;
            }
        }
        return newStr;
    }
};
