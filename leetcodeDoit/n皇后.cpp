//��ȷʾ����

#include<iostream>
using namespace std;
int N; //N�ֶ����룬ȷ��ΪN�ʺ�
int queenPos[100];//�����±��ʾ�У�Ԫ�ر�ʾ���еĻʺ������һ��
void NQueen(int k) {//�ݹ麯��
    if (k == N) {//�ݹ���ڣ���N���ʺ��Ѿ��ں������������лʺ��Ѿ��ں���
        for (int i = 0; i < N; i++) { //
            cout << queenPos[i] + 1 << " ";
        }
        cout << endl;
        return;
    }
    else {
        for (int i = 0; i < N; i++) {//������k�е�ÿ����Ԫ��
            bool flag = true;
            for (int j = 0; j < k && flag; j++) {//�����Ѿ��ںõ�ǰk-1�е������� ���Ƿ���Ҫ�ڷŵ�λ��i��ͻ
                if (queenPos[j] == i || abs(queenPos[j] - i) == abs(j - k)) {
                    flag = false;
                    break;//��ͻ������ѭ��
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
