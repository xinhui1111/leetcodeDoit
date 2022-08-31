//https://leetcode.cn/problems/n-queens/
/*
问题描述：
    n皇后问题研究的是如何将n个皇后放置在n×n的棋盘上，并且使皇后彼此之间不能相互攻击。
	输入：n = 4
示例：
    输出：{{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}}
    解释：如上图所示，4 皇后问题存在两个不同的解法。
*/

#include<iostream>
using namespace std;

#include<vector>
#include<string>
#include<cmath>
/*
思路实现：每一行以及每一列都只有一个皇后
          并且斜线也只有一个
*/
vector<vector<string>> solveNQueens(int n) {
	//设置vector的大小
    vector<vector<string>>NQueens = {};
    NQueens.resize(n, vector<string>(n));

	//设置一个pair对来保存已经标记为n皇后的坐标
	vector<pair<int, int>>coordinate = { {0,0} };
	NQueens[0][0] = "Q";
	
	//设置n皇后
	for (int k = 1; k < n; k++) {//判断n个层a[k][i]
		//从第k个开始
		for (int j = 0; j < n; j++) {
			int flag = 0;
			// 遍历已经保存的coordinate
			int blog = 0;//标记遍历了多少个，如果没有coordinate的个数就说明冲突了，不满足n皇后的要求
			for (int i = 0; i < coordinate.size(); ++i) {
				int add = coordinate[i].first + coordinate[i].second;
				int subtract = max(coordinate[i].first, coordinate[i].second) - min(coordinate[i].first, coordinate[i].second);
				//判断斜线以及同行同列的情况
				if ((k + j) == add || abs(k - j) == subtract || j == coordinate[i].second) {
					blog++;
					//// 将其保存在坐标中，并在矩阵中置为q
					//coordinate.push_back(make_pair(k, j));
					//NQueens[k][j] = "Q";
					flag = 1;//这就说明有一个等于，那就不行
					//break;
				}
			}
			if (flag == 0) {//就说明是正确的
				// 将其保存在坐标中，并在矩阵中置为q
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



//使用一个数组记录每行放置的皇后的列下标，依次在每一行放置一个皇后。
//每次新放置的皇后都不能和已经放置的皇后之间有攻击：即新放置的皇后不能和任何一个
//已经放置的皇后在同一列以及同一条斜线上，并更新数组中的当前行的皇后列下标。
//当 NN 个皇后都放置完毕，则找到一个可能的解。当找到一个可能的解之后，将数组转换成表示棋盘状态的列表，
//并将该棋盘状态的列表加入返回列表。
#include<unordered_set>
//给对应的Board赋值
vector<string> generateBoard(vector<int>& queens, int n) {
    auto board = vector<string>();
    for (int i = 0; i < n; i++) {
        string row = string(n, '.');
        row[queens[i]] = 'Q';
        board.push_back(row);
    }
    return board;
}

//回溯，计算board，将board保存下来
void backtrack(vector<vector<string>>& solutions, vector<int>& queens, int n, int row,
    unordered_set<int>& columns, unordered_set<int>& diagonals1, unordered_set<int>& diagonals2)
{
	//1.设置结束条件
    if (row == n) {
        //计算出一个board就保存下来到solutions
        vector<string> board = generateBoard(queens, n);
        solutions.push_back(board);
    }
	//2.遍历步骤（竖向、正反斜线）
    else {
        for (int i = 0; i < n; i++) {
            //在集合中找的到i
            if (columns.find(i) != columns.end()) {
                continue;
            }
            //正向斜线
            int diagonal1 = row - i;
            if (diagonals1.find(diagonal1) != diagonals1.end()) {
                continue;
            }
            //反向斜线
            int diagonal2 = row + i;
            if (diagonals2.find(diagonal2) != diagonals2.end()) {
                continue;
            }
            queens[row] = i;//行列保存在queens中了
            columns.insert(i);//多少行保存下来了
            diagonals1.insert(diagonal1);//将斜线对应的差也保存下
            diagonals2.insert(diagonal2);//将斜线对应的和也保存
			//递归进行调用n皇后，进行下一列查找，0 2之后怎么处理呢？会被continue到n那里去，然后就开始回溯
			//3.往下一列进行递归
            backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
            //进行回溯，回到之前的那个节点，所以需要将这一节点重置并进行删除
			//4.回溯到前一个节点
            queens[row] = -1;
            columns.erase(i);
            diagonals1.erase(diagonal1);
            diagonals2.erase(diagonal2);
        }
    }
}


//封装n皇后算法
vector<vector<string>> solveNQueens2(int n) {
    auto solutions = vector<vector<string>>();
    auto queens = vector<int>(n, -1);
	//利用三个不同方向的集合去保存
    auto columns = unordered_set<int>();
    auto diagonals1 = unordered_set<int>();
    auto diagonals2 = unordered_set<int>();
	//实际
    backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
    return solutions;
}


int main_n() {
    int n=4;
    /*cout << "输入n皇后的个数" << endl;
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