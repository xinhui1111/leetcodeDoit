#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//https://www.cnblogs.com/mayunting/p/10426316.html
int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
    for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
    for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
    for (int i = 1; i <= word1.size(); i++) {
        for (int j = 1; j <= word2.size(); j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min({ dp[i - 1][j - 1] + 2, dp[i - 1][j] + 1, dp[i][j - 1] + 1 });
            }
        }
    }
    return dp[word1.size()][word2.size()];
}



//https://blog.csdn.net/wutcxthu/article/details/120462708
int LCS(string text1, string text2) {
	if (text1.size() == 0 || text2.size() == 0)
	{
		return 0;
	}
	int len1 = text1.size(), len2 = text2.size();
	if (text1[len1 - 1] == text2[len2 - 1])
	{
		text1.pop_back();
		text2.pop_back();
		return LCS(text1, text2) + 1;
	}
	else
	{
		string text11 = text1;
		text11.pop_back();
		string text22 = text2;
		text22.pop_back();
		return LCS(text11, text2) > LCS(text1, text22) ? LCS(text11, text2) : LCS(text1, text22);
	}

}


int main_583() {
    string word1 = "sea", word2 = "eat";
    int result=minDistance(word1, word2);
    cout << "result is:" << result << endl;


	cout << "LCS is:" << LCS(word1, word2) << endl;
	return 0;
}

