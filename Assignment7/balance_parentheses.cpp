#include<iostream>
#include<stack>

using namespace std;

bool check_balancedParentheses(string input){
    stack<char>st;

    for(int i=0;i<input.size();i++){
        if(input[i]=='(' || input[i]=='{' || input[i]=='['){
            st.push(input[i]);
        }
        else{
            if(st.empty()) return false;
            if(input[i]==')' && st.top()=='('){
                st.pop();
            }
            else if(input[i]=='}' && st.top()=='{'){
                st.pop();
            }
            else if(input[i]==']' && st.top()=='['){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();    
}

int main(){
	string input;
	cin>>input;

	cout<<(check_balancedParentheses(input) ? "true" : "false")<<endl;

	return 0;
}
