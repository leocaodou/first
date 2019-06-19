#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class letter{
    public:
    int len;
    char let[100]; 
    int count[3];
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
    letter ()
    {
        count[0]=0;
        count[1]=0;
        count[2]=0;
    }
};
int main(){                                                                           
    letter str;
    str.sum();
    ofstream dataFile("test.txt",ios::out|ios::binary);
    if (!dataFile)
    {
        cout << "不能打开文件:test.txt\n";
        exit(0);
    }
    dataFile.write((char *)&str, sizeof(letter));
    dataFile.close();
    ifstream infile("test.txt", ios::in | ios::binary); 
    if (!infile){
        cout << "不能打开输入文件：test.txt\n";
        return 0;
    }
    letter s;
    infile.read((char *)&s, sizeof(letter));
    cout<<s.len<<endl<<s.count[0]<<endl<<s.count[1]<<endl<<s.count[2]<<endl<<s.let;
    cout << endl;
    infile.close();
    return 0;
}