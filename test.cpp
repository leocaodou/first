#include<iostream>
#include<string>
#include<stdio.h>
#include<fstream>
using namespace std;
int main() {
    
    int a = 0;
    int A = 0;
    int n = 0;
    int num = 0;
    string str;
    cout << "请输入字符串：\n";
    cin >> str;//str.length str.at()
    for (int i = 0; i <str.length();i++) {
        if (str.at(i) >= 'a' && str.at(i) <= 'z')
            a++;

        else if (str.at(i) >= 'A' && str.at(i) <= 'Z')
            A++;

        else if (str.at(i) >= '0' && str.at(i) <= '9')
            n++;

        
    }
    num = a + A + n;
    //cout << a << ' ' << A << ' ' << n << ' ' << num << " "<<endl;

    //string str1;
    //cin >> str1;
    //str1 = str1 + str;
    int Array[] = { a,A,n,num };
    string c;
	int x[4];
    fstream file("test.txt", ios::out | ios::binary);
    if (!file) {//验证打开没 
        cout << "Error opening file.";
        return 0;
    }
    file.write((char *)&(Array), sizeof(int[4]));//写入文件 out.write((char *)&a, sizeof(int))
    file.write((char *)&(str), sizeof(str));
    file.close();

    ifstream file2("test.txt", ios::in | ios::binary);
    file2.read((char *) &x, sizeof(x));
    cout << x[0]<<' '<<x[1]<<' '<<x[2]<<' '<<x[3]<<endl;
    file2.read((char *) &c, sizeof(str));//读取文件 reinterpret_cast 可用于强制编译器解释一个类型的位
    cout << c;
    //printf("%s", c);
    //file.read((char *) &str, sizeof(str));
    /*for (int i = 0; i < 4+ str.length(); ++i) {
        cout << Array[i] << " ";
    }*/
    


    file.close();
    //getchar();
    //getchar();
    return 0;


}
