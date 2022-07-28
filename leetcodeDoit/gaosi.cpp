#include<iostream>
using namespace std;
#define MaxNumber 100
int main_gaosi() {
	float** Number = new float* [MaxNumber];
	for (int i = 0; i < MaxNumber; i++)
	{
		Number[i] = new float[MaxNumber];
	}
	cout << "�����������";
	int left = 0;
	int right = 0;
	cin >> left;
	cout << endl;
	cout << "δ֪����������";
	cin >> right;
	cout << endl;
	cout << "����ϵ�����飺" << endl;;
	for (int i = 0; i < left; i++)
	{
		for (int j = 0; j <= right; j++)
		{
			cin >> Number[i][j];
		}
	}
	cout << "----------------------------------" << endl;
	cout << "              ����¼�����        " << endl;
	cout << "----------------------------------" << endl;
	cout << "�������" << endl;
	for (int i = 0; i < left; i++)
	{
		for (int j = 0; j <= right; j++)
		{
			if (j != 0 && Number[i][j] > 0 && j != right) {
				cout << "+";
			}
			cout << Number[i][j];
			if (j != right) {
				cout << char('a' + j);
			}
			if (j == right - 1) {
				cout << "=";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < left; i++)
	{
		for (int j = i + 1; j < left; j++)
		{
			float a = Number[j][i] / Number[i][i];
			for (int n = 0; n <= right; n++)
			{
				Number[j][n] -= Number[i][n] * a;
			}
		}
	}
	float* answer = new float[right];
	for (int i = 0; i < right; i++)
	{
		answer[i] = 1.0;
	}
	for (int i = left - 1; i >= 0; i--)
	{
		for (int j = left - 1; j > i; j--) {
			Number[i][right] -= Number[i][j] * answer[j];
		}
		answer[i] = Number[i][right] / Number[i][i];
	}



	cout << "----------------------------------" << endl;
	cout << "              �������        " << endl;
	cout << "----------------------------------" << endl;
	cout << "������:" << endl;
	for (int i = 0; i < right; i++)
	{
		cout << "��" << i + 1 << "��δ֪����" << answer[i] << endl;;
	}
	return 0;
}
