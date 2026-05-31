class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        unordered_set<string> dict = {"+", "-", "*", "/"};
        for(int i = 0; i < tokens.size(); i++){
            if(!dict.count(tokens[i])){
                s.push(tokens[i]);
            }
            else{
                int b = stoi(s.top());
                s.pop();
                int a = stoi(s.top());
                s.pop();
                int result = 0;
                if(tokens[i] == "+")
                    result = a + b;
                else if(tokens[i] == "-")
                    result = a - b;
                else if(tokens[i] == "*")
                    result = a * b;
                else if(tokens[i] == "/")
                    result = a / b;
                s.push(to_string(result));
            }
        }
        return stoi(s.top());
    }
};
