#include <iostream>     // std::cout, std::streambuf, std::streamsize
#include <fstream>      // std::ifstream
using namespace std;

#include<string>
int main_ifstream() {
    string s1="";
    cin >> s1;
    std::ifstream ifs("test.txt");
    ifs >> s1;
    std::ofstream ofs("out.txt");
    ofs << "this is ofs";
    std::streambuf* pbuf = ofs.rdbuf();

    

    ifs.get(*pbuf);//默认读取截止字符是'\n', 所以读取一行停止，且没有读取'\n'。
    pbuf->sputc(ifs.get()); // '\n'并没有被读取到pbuf，所以需要get()来读取'\n',然后用函数sputc()加到 pbuf 中。
    ifs.get(*pbuf);  // 从流中取出了'\n' ，才能读取第二行
    pbuf->sputc(ifs.get());
    /*
    上面使用了函数 istream& get (streambuf& sb);
    之后不能使用 istream& get (char* s, streamsize n);
    */
    char s[20];
    ifs.get(s, 20);//虽然输入流有第三行，但是没法读取。
    cout << "get:" << s << endl;  //内容为空

    ofs.close();
    ifs.close();
    return 0;
}
