class Solution {
    public:

        string getPermutation(int n, int k)
{
            string ans = "";
            vector<int> numbers;
       
            int fact = 1;
            for (int i = 1; i <= n; i++){
                fact = fact * i;
                numbers.push_back(i);
            }
    
            int blockSize = fact / n;	
            k = k - 1;
            
            while (true)
            {
                ans += to_string(numbers[k / blockSize]);	
                numbers.erase(numbers.begin() + k / blockSize);
               
                if (numbers.size() == 0){
                    break;
                }
                
                k = k % blockSize;	
                blockSize = blockSize / numbers.size();	
               
            }
            return ans;
        }
};
