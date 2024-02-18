class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int d) {
        int n=nums.size();
        k--;
        set<pair<int,int>> pq, mp;
        
        long long ans=nums[0];
        
        long long sum=0;
        for(int i=1;i<=d+1;i++){
           if(pq.size()<k){
               pq.insert({nums[i],i});
               sum+=nums[i];
           }else {
                auto it=pq.rbegin();
                int e=it->first;
                if(nums[i]<e){
                    pq.insert({nums[i],i});
                    mp.insert(*it);
                    pq.erase(*it);
                    sum-=e;
                    sum+=nums[i];
                }else{
                    mp.insert({nums[i],i});
                }
            }
        }
        
        long long temp=sum;
        for(int i=d+2;i<n;i++){
          int p=nums[i-d-1];
          mp.insert({nums[i],i});
            
            if(pq.find({p,i-d-1})!=pq.end()){
                sum-=p;
               pq.erase({p,i-d-1});
               auto it=mp.begin();
               sum+=it->first;
               pq.insert(*it);
               mp.erase(it);
            }
            else {
                mp.erase({p,i-d-1});
                auto it1=pq.rbegin();
                auto it2=mp.begin();
                if(it1->first>it2->first){
                    sum-=it1->first;
                    sum+=it2->first;
                    
                    mp.insert(*it1);
                    pq.insert(*it2);
                    pq.erase(*it1);
                    mp.erase(it2);
                }
               
                }
            
            temp=min(temp,sum);
        }
         
        return ans+temp;
    }
};