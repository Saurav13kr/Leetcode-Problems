class CustomStack {
    vector<int> st;
    int mx;
public:
    CustomStack(int maxSize) {
        mx = maxSize;
    }
    
    void push(int x) {
        if(st.size()>=mx) return;
        st.push_back(x);
    }
    
    int pop() 
    {
        if(!st.size()) return -1;
        int x = st[st.size() - 1];
        st.pop_back();
        return x;
    }
    
    void increment(int k, int val) {
        int x = st.size();
        if(x < k) k = x;
        if(k > mx) k = mx;
        for(int i = 0; i < k; i++) st[i] += val;
    }
};
