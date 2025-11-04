#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long largestRectangleArea(const vector<int>& heights) {
    int n = (int)heights.size();
    if (n == 0) return 0;
    vector<int> h;
    h.reserve(n + 1);
    for (int x : heights) h.push_back(x);
    h.push_back(0);

    stack<int> st;
    long long maxArea = 0;
    for (int i = 0; i < (int)h.size(); ++i) {
        while (!st.empty() && h[i] < h[st.top()]) {
            int top = st.top();
            st.pop();
            long long height = h[top];
            int width = st.empty() ? i : i - st.top() - 1;
            long long area = height * (long long)width;
            if (area > maxArea) maxArea = area;
        }
        st.push(i);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Max rectangle area = " << largestRectangleArea(heights) << endl;
    return 0;
}

