struct Node {
    int start, end;
    Node* next;
};

class MyCalendar {
public:
    Node* store;
    MyCalendar() 
    {
        store = NULL;
    }
    
    bool book(int start, int end) {
        if(!store){
            Node* newNode = new Node(start, end, store);
            store = newNode;
            return true;
        }

        Node* iter = store, *prev = NULL;
        while(iter && iter->start <= start) {prev= iter;iter = iter->next;}
        if(!prev){
            if(iter->start < end) return false;
            Node *newNode = new Node(start, end, iter);
            store = newNode;
            return true;
        }

        if(!iter){
            if(prev->end > start) return false;
            Node* newNode = new Node(start, end, iter);
            prev->next = newNode;
            return true;
        }

        if(prev->end > start || iter->start < end) return false;
        Node* newNode = new Node(start, end, iter);
        prev->next = newNode;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */