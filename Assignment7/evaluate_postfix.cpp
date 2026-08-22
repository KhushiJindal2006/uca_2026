#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluate_postfix(string input){
    stack<int>st;
    int ans=0;
    for(char ch : input){
        if(ch==' ') continue;
        if(isdigit(ch)){
            st.push(ch-'0');
        }
        else{
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            
            if(ch=='+'){
                ans=b+a;
            }
            if(ch=='-'){
                ans=b-a;
            }
            if(ch=='*'){
                ans=b*a;
            }
            
            st.push(ans);
        }
    }
    return st.top();
}
int main()
{
   string input;
   getline(cin,input);
   
   cout<<evaluate_postfix(input)<<endl;
   return 0;
}
