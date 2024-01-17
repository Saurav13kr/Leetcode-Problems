class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[1]==b[1])
        {
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        priority_queue<int>pq;
        int ans=0;
        int time=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i][0]>arr[i][1])
            {
                continue;
            }
            else
            {
                if(time+arr[i][0]<=arr[i][1])
                {
                    time+=arr[i][0];
                    pq.push(arr[i][0]);
                    ans++;
                }
                else if(pq.top()>arr[i][0])
                {
                    time-=pq.top();
                    pq.pop();
                    pq.push(arr[i][0]);
                    time+=arr[i][0];
                }
            }
        }
        return ans;
    }
};