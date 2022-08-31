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

    

    ifs.get(*pbuf);//Ĭ�϶�ȡ��ֹ�ַ���'\n', ���Զ�ȡһ��ֹͣ����û�ж�ȡ'\n'��
    pbuf->sputc(ifs.get()); // '\n'��û�б���ȡ��pbuf��������Ҫget()����ȡ'\n',Ȼ���ú���sputc()�ӵ� pbuf �С�
    ifs.get(*pbuf);  // ������ȡ����'\n' �����ܶ�ȡ�ڶ���
    pbuf->sputc(ifs.get());
    /*
    ����ʹ���˺��� istream& get (streambuf& sb);
    ֮����ʹ�� istream& get (char* s, streamsize n);
    */
    char s[20];
    ifs.get(s, 20);//��Ȼ�������е����У�����û����ȡ��
    cout << "get:" << s << endl;  //����Ϊ��

    ofs.close();
    ifs.close();
    return 0;
}
