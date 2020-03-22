#include <iostream>//输入输出流类库 
using namespace std;
int main(int argc, char** argv) {
//main函数参数测试
        cout<<"此程序一共有"<<argc<<"个参数"<<endl; 
		for(int i=0;i<argc;i++) {
			if(i==0){
				cout<<"此程序全路径名是："<<argv[i]<<endl;
			} 
			else{
				cout<<"第"<<i<<"个参数是"<<argv[i]<<endl;
			}	
		}
		system("pause");	
	return 0;
}