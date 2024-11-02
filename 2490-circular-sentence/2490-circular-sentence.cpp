class Solution {
public:
    bool isCircularSentence(string sentence) {
        char last='@';
        
        for(int i=0;i<sentence.size()-1;i++)
        {
            if(sentence[i]==' '){
                if(sentence[i-1]!=sentence[i+1]) 
                    return false;
            }
        }

        if(sentence[0]!=sentence[sentence.size()-1]) 
            return false;


        return true;
        
    }
};