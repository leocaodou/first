//ȫ��������
#include<stdio.h>
#include<string.h>
 
int n;
char  a[15];
char re[15];
int vis[15];
//������n���ַ�Ҫ���У����������ηŵ�n��������
//��Ҫ��������Ƿ�Ϊ�գ����л���ʲô�ַ��������ǷŽ�����ǡ�
//����һ��Ҫ�ָ���ʼ״̬������n+1������ʱ��һ�������Ѿ�����
void dfs(int step)
{
    int i;
    if(step==n+1)//�жϱ߽�
    {
        for(i=1;i<=n;i++)
            printf("%c",re[i]);
        printf("\n");
        return ;
    }
    for(i=1;i<=n;i++)//����ÿһ�����
    {
        if(vis[i]==0)//check����
        {
            re[step]=a[i];
            vis[i]=1;//���
            dfs(step+1);//��������
            vis[i]=0;//�ָ���ʼ״̬
        }
    }
    return ;
}
 
int main(void)
{
    int T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));//�Դ����ݵ�����ֱ��ʼ��
        scanf("%s",a+1);
        n=strlen(a+1);
        dfs(1);//�ӵ�һ�����ӿ�ʼ
    }
    return 0;
}
