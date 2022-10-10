#include<bits\stdc++.h> 
#include<string.h>
using namespace std; 
Balanced(string p) 
{ 
    stack<char> s; 
    char x; 
    for (int i=0; i<p.length(); i++) 
    { 
        if (p[i]=='('||p[i]=='['||p[i]=='{') 
        { 
            s.push(p[i]); 
            continue; 
        }
   switch (p[i]) 
        { 
        case ')': 
            x = s.top(); 
            s.pop(); 
            if (x=='{' || x=='[') 
                return false; 
            break; 
  
        case '}':
            x = s.top(); 
            s.pop(); 
            if (x=='(' || x=='[') 
                return false; 
            break; 
  
        case ']':
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{') 
                return false; 
            break; }}}
int main() 
{ 
    string p="{([}])}";
    cout<<"enter characters:\n";
    getline(cin,p);
  
    if (Balanced(p)) 
        cout << "\nBalanced"; 
    else
        cout << "\nNot Balanced"; 
    return 0; 
}
