//正确示例：

#include<iostream>
using namespace std;
int N; //N手动输入，确定为N皇后
int queenPos[100];//数组下标表示行，元素表示该行的皇后摆在哪一列
void NQueen(int k) {//递归函数
    if (k == N) {//递归出口；第N个皇后已经摆好啦，代表所有皇后都已经摆好了
        for (int i = 0; i < N; i++) { //
            cout << queenPos[i] + 1 << " ";
        }
        cout << endl;
        return;
    }
    else {
        for (int i = 0; i < N; i++) {//遍历第k行的每个列元素
            bool flag = true;
            for (int j = 0; j < k && flag; j++) {//遍历已经摆好的前k-1行的所有列 看是否与要摆放的位置i冲突
                if (queenPos[j] == i || abs(queenPos[j] - i) == abs(j - k)) {
                    flag = false;
                    break;//冲突；跳出循环
                }
            }
            if (flag) {
                queenPos[k] = i;
                NQueen(k + 1);
            }
        }
    }

}

int main()
{
    cin >> N;
    NQueen(0);
    return 0;
}
