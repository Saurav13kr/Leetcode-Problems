/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

class SmallestInfiniteSet {
public:
    set<int> s;
    int smallest = 1;
    SmallestInfiniteSet() {       
    }
    
    int popSmallest() {
        int t=smallest;

        if(!s.empty())
        { 
            t=*s.begin();
            s.erase(s.begin());
            return t;
        }
        smallest++;
        return t;
    }
    
    void addBack(int num) 
    {
        if(num<smallest){
            s.insert(num);
        }
    }
};
