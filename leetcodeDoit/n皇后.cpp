//https://leetcode.cn/problems/n-queens/
/*
����������
    n�ʺ������о�������ν�n���ʺ������n��n�������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������
	���룺n = 4
ʾ����
    �����{{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}}
    ���ͣ�����ͼ��ʾ��4 �ʺ��������������ͬ�Ľⷨ��
*/

#include<iostream>
using namespace std;

#include<vector>
#include<string>
#include<cmath>
/*
˼·ʵ�֣�ÿһ���Լ�ÿһ�ж�ֻ��һ���ʺ�
          ����б��Ҳֻ��һ��
*/
vector<vector<string>> solveNQueens(int n) {
	//����vector�Ĵ�С
    vector<vector<string>>NQueens = {};
    NQueens.resize(n, vector<string>(n));

	//����һ��pair���������Ѿ����Ϊn�ʺ������
	vector<pair<int, int>>coordinate = { {0,0} };
	NQueens[0][0] = "Q";
	
	//����n�ʺ�
	for (int k = 1; k < n; k++) {//�ж�n����a[k][i]
		//�ӵ�k����ʼ
		for (int j = 0; j < n; j++) {
			int flag = 0;
			// �����Ѿ������coordinate
			int blog = 0;//��Ǳ����˶��ٸ������û��coordinate�ĸ�����˵����ͻ�ˣ�������n�ʺ��Ҫ��
			for (int i = 0; i < coordinate.size(); ++i) {
				int add = coordinate[i].first + coordinate[i].second;
				int subtract = max(coordinate[i].first, coordinate[i].second) - min(coordinate[i].first, coordinate[i].second);
				//�ж�б���Լ�ͬ��ͬ�е����
				if ((k + j) == add || abs(k - j) == subtract || j == coordinate[i].second) {
					blog++;
					//// ���䱣���������У����ھ�������Ϊq
					//coordinate.push_back(make_pair(k, j));
					//NQueens[k][j] = "Q";
					flag = 1;//���˵����һ�����ڣ��ǾͲ���
					//break;
				}
			}
			if (flag == 0) {//��˵������ȷ��
				// ���䱣���������У����ھ�������Ϊq
				coordinate.push_back(make_pair(k, j));
				NQueens[k][j] = "Q";
				break;
			}
			/*if(flag==1)
				break;*/
		}
	}
	return NQueens;
}



//ʹ��һ�������¼ÿ�з��õĻʺ�����±꣬������ÿһ�з���һ���ʺ�
//ÿ���·��õĻʺ󶼲��ܺ��Ѿ����õĻʺ�֮���й��������·��õĻʺ��ܺ��κ�һ��
//�Ѿ����õĻʺ���ͬһ���Լ�ͬһ��б���ϣ������������еĵ�ǰ�еĻʺ����±ꡣ
//�� NN ���ʺ󶼷�����ϣ����ҵ�һ�����ܵĽ⡣���ҵ�һ�����ܵĽ�֮�󣬽�����ת���ɱ�ʾ����״̬���б�
//����������״̬���б���뷵���б�
#include<unordered_set>
//����Ӧ��Board��ֵ
vector<string> generateBoard(vector<int>& queens, int n) {
    auto board = vector<string>();
    for (int i = 0; i < n; i++) {
        string row = string(n, '.');
        row[queens[i]] = 'Q';
        board.push_back(row);
    }
    return board;
}

//���ݣ�����board����board��������
void backtrack(vector<vector<string>>& solutions, vector<int>& queens, int n, int row,
    unordered_set<int>& columns, unordered_set<int>& diagonals1, unordered_set<int>& diagonals2)
{
	//1.���ý�������
    if (row == n) {
        //�����һ��board�ͱ���������solutions
        vector<string> board = generateBoard(queens, n);
        solutions.push_back(board);
    }
	//2.�������裨��������б�ߣ�
    else {
        for (int i = 0; i < n; i++) {
            //�ڼ������ҵĵ�i
            if (columns.find(i) != columns.end()) {
                continue;
            }
            //����б��
            int diagonal1 = row - i;
            if (diagonals1.find(diagonal1) != diagonals1.end()) {
                continue;
            }
            //����б��
            int diagonal2 = row + i;
            if (diagonals2.find(diagonal2) != diagonals2.end()) {
                continue;
            }
            queens[row] = i;//���б�����queens����
            columns.insert(i);//�����б���������
            diagonals1.insert(diagonal1);//��б�߶�Ӧ�Ĳ�Ҳ������
            diagonals2.insert(diagonal2);//��б�߶�Ӧ�ĺ�Ҳ����
			//�ݹ���е���n�ʺ󣬽�����һ�в��ң�0 2֮����ô�����أ��ᱻcontinue��n����ȥ��Ȼ��Ϳ�ʼ����
			//3.����һ�н��еݹ�
            backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
            //���л��ݣ��ص�֮ǰ���Ǹ��ڵ㣬������Ҫ����һ�ڵ����ò�����ɾ��
			//4.���ݵ�ǰһ���ڵ�
            queens[row] = -1;
            columns.erase(i);
            diagonals1.erase(diagonal1);
            diagonals2.erase(diagonal2);
        }
    }
}


//��װn�ʺ��㷨
vector<vector<string>> solveNQueens2(int n) {
    auto solutions = vector<vector<string>>();
    auto queens = vector<int>(n, -1);
	//����������ͬ����ļ���ȥ����
    auto columns = unordered_set<int>();
    auto diagonals1 = unordered_set<int>();
    auto diagonals2 = unordered_set<int>();
	//ʵ��
    backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
    return solutions;
}


int main_n() {
    int n=4;
    /*cout << "����n�ʺ�ĸ���" << endl;
    cin >> n;*/

	vector<vector<string>>NQueens = solveNQueens2(n);
	for (size_t i = 0; i < NQueens.size(); i++)
	{
		for (size_t j = 0; j < NQueens[i].size(); j++) {
			cout << NQueens[i][j] << "  ";
		}
		cout << endl;
	}
    return 0;
}