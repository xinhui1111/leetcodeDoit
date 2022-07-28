#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<math.h>
#include <random>
#include<ctime>
using namespace std;

/// <summary>
/// 矩阵相乘
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
vector<vector<double> > MatrixMult(vector<vector<double>> a, vector<vector<double>> b)//return res=a*b,矩阵乘法
{
	int n1 = a.size();
	int n2 = a[0].size();
	int n3 = b.size();
	int n4 = b[0].size();

	vector<vector<double>> res(n1, vector<double>(n4, 0));

	if (n2 != n3)
	{
		cout << "错误:规模不匹配" << endl;
		system("PAUSE ");
		return res;
	}
	else
	{
		for (int i = 0; i < n1; i++)
		{
			for (int j = 0; j < n4; j++)
			{
				double temp = 0;
				for (int k = 0; k < n2; k++)
				{
					temp += a[i][k] * b[k][j];
				}
				res[i][j] = temp;
			}
		}
	}
	return res;
}

/// <summary>
/// 矩阵转置
/// </summary>
/// <param name="a"></param>
/// <returns></returns>
vector<vector<double> > transform(vector<vector<double>> a)		//转置
{
	int n1 = a.size();
	int n2 = a[0].size();
	vector<vector<double>> temp(n2, vector<double>(n1, 0));
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			temp[i][j] = a[j][i];
		}
	}

	return temp;
}


/// <summary>
/// 损失函数计算
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="w"></param>
/// <returns></returns>
double costfun(vector<vector<double>> x, vector<vector<double>> y, vector<vector<double>> w)	//代价函数
{
	int num = y.size();		//数据的个数
	int size = w.size();		//w的维数 ,系数个数
	double res = 0;
	vector<vector<double>> temp;
	temp = MatrixMult(x, transform(w));
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = 0; j < temp[i].size(); j++)
		{
			res += (temp[i][j] - y[i][j]) * (temp[i][j] - y[i][j]);
		}
	}

	return res / num;
}

/// <summary>
/// 梯度下降方法
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="w"></param>
/// <param name="alpha"></param>
/// <param name="epoch"></param>
/// <returns></returns>
vector<double> GD(vector<vector<double>> x, vector<vector<double>> y, vector<vector<double>> w, double alpha, int epoch)
{
	int num = y.size();		//数据的个数
	int size = w[0].size();		//w的维数,系数个数
	vector<double> cost;

	//		w=w-(alpha/num)*(x*w.T-y).T*x;
	for (int i = 0; i < epoch; i++)
	{
		cout << "epoch:" << i + 1 << endl;

		vector<vector<double>> temp(w);

		temp = MatrixMult(x, transform(w));

		for (int row = 0; row < temp.size(); row++)
		{
			for (int col = 0; col < temp[row].size(); col++)
			{
				temp[row][col] -= y[row][col];
			}
		}

		temp = MatrixMult(transform(temp), x);

		for (int row = 0; row < temp.size(); row++)
		{
			for (int col = 0; col < temp[row].size(); col++)
			{
				w[row][col] -= (alpha / double(num)) * temp[row][col];
				cout << "w[row][col]:" << w[row][col] << " ";
			}
			cout << endl;
		}

		cost.push_back(costfun(x, y, w));
		cout << "cost[i]=" << cost[i] << endl << endl;
		if (cost[i] < 0.00001)			//提前结束 
			break;
	}
	return cost;
}

/// <summary>
/// 线性回归方法
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="alpha"></param>
/// <param name="epoch"></param>
/// <returns></returns>
vector<vector<double>> LinearRegression(vector<vector<double>> x, vector<vector<double>> y, double alpha, int epoch)
{
	for (int i = 0; i < x.size(); i++)			//加上常数项 
	{
		x[i].push_back(1);
	}
	vector<vector<double>> w(1, vector<double>(x[0].size()));		//随机生成系数，范围0-2
	srand((unsigned int)(time(NULL)));
	for (int i = 0; i < w[0].size(); i++)
	{
		w[0][i] = double(rand() % 20 + 0) / 10;
	}


	cout << "*********************************************************" << endl;
	vector<double> cost;
	cost=GD(x, y, w, alpha, epoch);		//梯度下降 
	for (auto temp : cost)
		cout << temp ;
	cout << endl << endl;

	cout << endl << "Y=";			//输出公式 
	for (int i = 0; i < w[0].size() - 1; i++)
	{
		cout << w[0][i] << "X" << i + 1 << "+";
	}
	cout << w[0][w[0].size() - 1] << endl;
	return w;
}

int main_sgd()
{
	double alpha = 0.001;
	int epoch = 10000;
	vector<vector<double>> x = { {1,2,3},{2,3,4},{3,4,5},{4,5,6},{5,6,7},{6,7,8},{7,8,9} };
	vector<vector<double>> y = { {6},{9},{12},{15},{18},{21},{24} };
	vector<vector<double>> w;
	w = LinearRegression(x, y, alpha, epoch);

	return 0;
}
