class MyStack {
public:
    queue<int> a;
    MyStack() {       
    }   
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        int size = a.size();
        int c;
        while(size>0){
            if(size==1) {
                c = a.front();
                a.pop();
                break;
            }
            a.push(a.front());
            a.pop();
            size--;
        }
        return c;
    }
    
    int top() {
        int size = a.size();
        int c;

        while(size>0){
            if(size==1){
                c = a.front();
            }
            a.push(a.front());
            a.pop();
            size--;
        }

        return c;
    }    
    bool empty() {
        return a.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */