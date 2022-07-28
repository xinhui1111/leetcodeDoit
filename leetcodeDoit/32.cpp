#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

/// <summary>
/// 一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
/// </summary>
/// <param name="s"></param> 字符串
/// <returns></returns> 返回括号子串的长度
int longestValidParentheses(string s) {
    //1.利用mark数组来进行标记括号字符串
    stack<int> st;
    vector<bool> mark(s.length());
    for (int i = 0; i < mark.size(); i++) mark[i] = 0;
    int left = 0, len = 0, ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push(i);
        else {
            // 多余的右括号是不需要的，标记
            if (st.empty()) mark[i] = 1;
            else st.pop();
        }
    }
    // 2.未匹配的左括号是不需要的，标记
    while (!st.empty()) {
        mark[st.top()] = 1;
        st.pop();
    }
    // 3.寻找标记与标记之间的最大长度
    for (int i = 0; i < s.length(); i++) {
        if (mark[i]) {
            len = 0;
            continue;
        }
        len++;
        ans = max(ans, len);
    }
    return ans;
}

int main_32() {
    string str = string("(()");
    int len =longestValidParentheses(str);
    cout << len << endl;
    return 0;
}