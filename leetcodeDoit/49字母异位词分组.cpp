/*
* hash-mapʵ�֣��������Ĭ�ϵ��������ͣ���ô����Ҫ���¶�����������
������Ҫѧ����lamda���ʽ
STL�ۼӵ��㷨
*/
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

/*
��һ���ַ����ĺܶ����д����
���Ƚ�������Ȼ����ͬ�ľ���һ���ģ���ͬ�ľͲ�һ��
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string& str : strs) {
        string key = str;
        sort(key.begin(), key.end());
        mp[key].emplace_back(str);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        ans.emplace_back(it->second);
    }
    return ans;
}

#include<unordered_map>
#include<array>
/*
* ��һ��hash����Ӧ��ÿһ����ĸ
���ڻ�Ϊ��ĸ��λ�ʵ������ַ�����������ĸ��ͬ����������ַ����е���ͬ��ĸ���ֵĴ���һ������ͬ�ģ�
�ʿ��Խ�ÿ����ĸ���ֵĴ���ʹ���ַ�����ʾ����Ϊ��ϣ��ļ���

�����ַ���ֻ����Сд��ĸ����˶���ÿ���ַ���������ʹ�ó���Ϊ 26 �������¼ÿ����ĸ���ֵĴ�����
��Ҫע����ǣ���ʹ��������Ϊ��ϣ��ļ�ʱ����ͬ���Ե�֧�̶ֳȲ�ͬ����˲�ͬ���Ե�ʵ�ַ�ʽҲ��ͬ��


�Ὣһ���ַ�����26λ�����飨0��1λ����¼��һ��key����Ӧ��value�����ַ���
*/
vector<vector<string>> groupAnagrams2(vector<string>& strs) {
    /*1.ʵ��hash����*/
    //����hash���Լ���Ӧ��
    // �Զ���� array<int, 26> ���͵Ĺ�ϣ����
    //�޷���intתΪ-->�޷���64
    auto arrayHash = [fn = hash<int>{}](const array<int, 26>& arr)->size_t {
        //accumulateʹ�÷�ʽ������(�ף�β����ʼֵ���ۼӷ�ʽ)
        return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
            auto temp = fn(num);//num=1 temp��Ӧ��������hashֵ
            return (acc << 1) ^ fn(num);//acc =0 hash�㷨��Ҫ��ֹ��ײ
            });
    };

    /*2.����hash-map��*/
    //����hashmap��  key-value   ��Ϊ��Ҫ���������������ͨ��decltype�ӷ���ֵ������������
    unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
    for (string& str : strs) {//����ÿһ���ַ������м���
        array<int, 26>counts{};//����26�����ȵ�������������ĸ
        int length = (int)str.length();
        for (int i = 0; i < length; ++i) {
            counts[str[i] - 'a'] ++;
        }
        mp[counts].emplace_back(str);
    }

    /*3.һ���ķ���һ����*/
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        ans.emplace_back(it->second);//��Ԫ��ֱ�ӷ�����������
    }
    return ans;
}


#include<string>
int main_39() {
    vector<string>strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    vector<vector<string>>result=groupAnagrams2(strs);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j]<<" ";
        }
        cout << endl;
    }
	return 0;
}