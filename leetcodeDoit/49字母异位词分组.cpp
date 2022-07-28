/*
* hash-map实现，如果不是默认的数据类型，那么就需要重新定义数据类型
这里主要学到了lamda表达式
STL累加的算法
*/
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

/*
将一个字符串的很多组合写出来
首先进行排序，然后相同的就是一样的，不同的就不一样
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
* 做一个hash表，对应到每一个字母
由于互为字母异位词的两个字符串包含的字母相同，因此两个字符串中的相同字母出现的次数一定是相同的，
故可以将每个字母出现的次数使用字符串表示，作为哈希表的键。

由于字符串只包含小写字母，因此对于每个字符串，可以使用长度为 26 的数组记录每个字母出现的次数。
需要注意的是，在使用数组作为哈希表的键时，不同语言的支持程度不同，因此不同语言的实现方式也不同。


会将一个字符串以26位的数组（0、1位）记录成一个key，对应的value就是字符串
*/
vector<vector<string>> groupAnagrams2(vector<string>& strs) {
    /*1.实现hash表函数*/
    //建立hash表，以及对应的
    // 自定义对 array<int, 26> 类型的哈希函数
    //无符号int转为-->无符号64
    auto arrayHash = [fn = hash<int>{}](const array<int, 26>& arr)->size_t {
        //accumulate使用方式：参数(首，尾，初始值，累加方式)
        return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
            auto temp = fn(num);//num=1 temp对应的是它的hash值
            return (acc << 1) ^ fn(num);//acc =0 hash算法需要防止碰撞
            });
    };

    /*2.建立hash-map表*/
    //建立hashmap表  key-value   因为需要获得类型名，所以通过decltype从返回值那里获得类型名
    unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
    for (string& str : strs) {//对于每一个字符串进行计算
        array<int, 26>counts{};//建立26个长度的数组来保存字母
        int length = (int)str.length();
        for (int i = 0; i < length; ++i) {
            counts[str[i] - 'a'] ++;
        }
        mp[counts].emplace_back(str);
    }

    /*3.一样的放在一排里*/
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        ans.emplace_back(it->second);//将元素直接放在容器后面
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