#include <iostream>//������������ 
using namespace std;
int main(int argc, char** argv) {
//main������������
        cout<<"�˳���һ����"<<argc<<"������"<<endl; 
		for(int i=0;i<argc;i++) {
			if(i==0){
				cout<<"�˳���ȫ·�����ǣ�"<<argv[i]<<endl;
			} 
			else{
				cout<<"��"<<i<<"��������"<<argv[i]<<endl;
			}	
		}
		system("pause");	
	return 0;
}