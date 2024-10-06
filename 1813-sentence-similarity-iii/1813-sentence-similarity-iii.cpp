class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        
        int n1 = words1.size();
        int n2 = words2.size();
        
        int left = 0;
        int right = 0;
        
        while (left < n1 && left < n2 && words1[left] == words2[left]) {
            left++;
        }
        
        while (right < n1 && right < n2 && 
               words1[n1 - 1 - right] == words2[n2 - 1 - right]) {
            right++;
        }
        
        return left + right >= min(n1, n2);
    }
    
    vector<string> split(const string& sentence) {
        vector<string> words;
        istringstream stream(sentence);
        string word;
        while (stream >> word) 
        {
            words.push_back(word);
        }
        return words;
    }
};