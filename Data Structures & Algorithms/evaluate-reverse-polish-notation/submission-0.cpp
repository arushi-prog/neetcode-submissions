class Solution {
public:
    int operate(int a, int b, string s){
        if(s == "+"){
            return a + b;
        }
        if(s == "-"){
            return a - b;
        }
        if(s == "*"){
            return a * b;
        }
        if(s == "/"){
            return a / b;
        }

        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                int result = operate(a, b, s);

                st.push(result);
            }
            else{
                st.push(stoi(s));
            }
        }

        return st.top();  
    }
};