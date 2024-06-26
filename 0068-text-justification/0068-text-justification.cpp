class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        int i=0;
        vector<string> ans;
        while(i<n)        
        {
            int lencnt=0;
            int j;
            string res;
            for(j=i;j<n;j++) {
                if((lencnt+words[j].size()+j-i)<=maxWidth)
                  lencnt+=words[j].size();
                else break;
            }
            j--;
            int totspacelen=(maxWidth-lencnt);
            if(i==j)
            {
                res+=words[i++];
                res.append(totspacelen,' ');
                ans.push_back(res);
                continue;
            }
            string SpaceAfterEachWord=" ";
            string  SpaceAfterLastWord="";
            int spacecnt=j-i;           
            int extraspcelen=0;
                       
            if(j!=n-1)
            {
                int spacelen=totspacelen/spacecnt;
                extraspcelen=totspacelen%spacecnt;
                SpaceAfterEachWord.append(spacelen-1, ' ');
                
            }
            else   SpaceAfterLastWord.append(totspacelen-spacecnt, ' ');
            while(i<=j)
            {
                res+=words[i];
                if(i==j) res+= SpaceAfterLastWord;
                else
                {
                 res+=SpaceAfterEachWord;
                  if(extraspcelen)
                  {
                    res.push_back(' ');
                    extraspcelen--;
                  }
                }
                i++;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
