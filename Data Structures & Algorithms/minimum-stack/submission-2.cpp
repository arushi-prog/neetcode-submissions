// USING 2 STACKS
// class MinStack {
// public:
//     stack<int> st;
//     stack<int> minSt;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         st.push(val);
//         if(minSt.empty() || val <= minSt.top()){
//             minSt.push(val);
//         }
//     }
    
//     void pop() {
//         if(st.top() == minSt.top()){
//             minSt.pop();
//         }
//         st.pop();
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         return minSt.top();
//     }
// };

// USING 1 STACK AND STORING VALUES IN PAIRS
class MinStack {
public:
    stack<pair<int,int>> st;

    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }
        else{
            int minimum = min(val,st.top().second);
            st.push({val,minimum});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};



// class MinStack {
// public:
//     MinStack() {
        
//     }
    
//     void push(int val) {
        
//     }
    
//     void pop() {
        
//     }
    
//     int top() {
        
//     }
    
//     int getMin() {
        
//     }
// };

