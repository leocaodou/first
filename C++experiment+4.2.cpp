#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class letter{//用于储存输入的数据，便于输入到文件和从文件输出
public:
    int len;//用于存储输入的字符长度
    char let[100]; //储存输入的字符
    int count[3];//3个数字，用来记录大写字母，小写字母以及数字
    void sum ()
    {
        scanf("%s",let);
        len=strlen(let);
        for(int i=0;i<len;i++)
        {
            if(let[i]>='A'&&let[i]<='Z')
                count[0] ++;
            if(let[i]>='a'&&let[i]<='z')
                count[1]++;
            if(let[i]<='9'&&let[i]>='0')
                count[2]++;
        }
    }
    letter()//无参的构造函数，把所有数据初始化
    {
        count[0]=0;
        count[1]=0;
        count[2]=0;
    }
};
int main(){                                                                           
    letter str;
    str.sum();//调用函数来输入字符
    ofstream dataFile("test.txt",ios::out|ios::binary);//以流入的方式打开二进制文件
    if (!dataFile)//判断文可否打开
    {
        cout << "不能打开文件:test.txt\n";
        exit(0);
    }
    dataFile.write((char *)&str, sizeof(letter));//用write来写入二进制字符
    dataFile.close();
    ifstream infile("test.txt", ios::in | ios::binary); //以流出的方式打开二进制文件
    if (!infile)//判断文件可否打开
    {
        cout << "不能打开输入文件：test.txt\n";
        return 0;
    }
    letter s;
    infile.read((char *)&s, sizeof(letter));//用read来读取文件的二进制内容，然后存入s中
    cout<<s.len<<endl<<s.count[0]<<endl<<s.count[1]<<endl<<s.count[2]<<endl<<s.let;//输出提取出来的内容
    cout << endl;
    infile.close();//关闭打开的文件
    return 0;
}