#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;
/*
// input:python java js c++
// output:c++ js java python

int main(){
	string s;
	getline(cin,s);
	stringstream ss(s);
	string token;
	stack<string> st;
	while(ss >> token)
	{
		st.push(token);
	}
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}
*/

// Phan tu lon ben phai (Next Greater Element)
int main() {
   	int n; cin>>n;
    int a[n], b[n];
    for (int &x : a) cin >> x;

    stack<int> st;
    for (int i = 0; i < n; ++i) {
        if (st.empty()) {
            st.push(i);
        } else {
            while (!st.empty() && a[st.top()] < a[i]) {
                b[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
    }

    while (!st.empty()) {
        b[st.top()] = -1;
        st.pop();
    }

    for (int x : b) {
        cout << x << " ";
    }
    return 0;
}
