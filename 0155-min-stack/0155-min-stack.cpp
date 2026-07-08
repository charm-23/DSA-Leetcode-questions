class MinStack {
public:
    stack<long long>st; 
    long long mini; 

    MinStack() {
    }

    //encryption formula--> flag= (2*val-mini) //*2 cuz it gives  flag<val even in case of negative numbers 
    
    void push(int value) {
        if(st.empty()){
            st.push(value); 
            mini=value; 
            return;
        }
        if(value<mini){
            long long diff =(2LL* value-mini); 
            st.push(diff);
            mini=value; 
        } 
        else{
            st.push(value); 
        }
    }
    
    void pop() {
        if(st.empty()) return; 

        if(st.top()<mini){
            mini= 2*mini-st.top(); 
            st.pop(); 
        }
        else{
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        if(st.top()<mini){
            return mini; 
        }
        else return st.top(); 
    }
    
    int getMin() {
        return mini; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */