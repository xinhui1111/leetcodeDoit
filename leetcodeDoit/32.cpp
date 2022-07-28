#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

/// <summary>
/// һ��ֻ���� '(' �� ')' ���ַ������ҳ����Ч����ʽ��ȷ�������������Ӵ��ĳ��ȡ�
/// </summary>
/// <param name="s"></param> �ַ���
/// <returns></returns> ���������Ӵ��ĳ���
int longestValidParentheses(string s) {
    //1.����mark���������б�������ַ���
    stack<int> st;
    vector<bool> mark(s.length());
    for (int i = 0; i < mark.size(); i++) mark[i] = 0;
    int left = 0, len = 0, ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push(i);
        else {
            // ������������ǲ���Ҫ�ģ����
            if (st.empty()) mark[i] = 1;
            else st.pop();
        }
    }
    // 2.δƥ����������ǲ���Ҫ�ģ����
    while (!st.empty()) {
        mark[st.top()] = 1;
        st.pop();
    }
    // 3.Ѱ�ұ������֮�����󳤶�
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