
 
/**
 * 哈希表查找（除留余数法）
 * @author calm
 *
 */
public class test {
	static int key[]={47,7,29,11,16,22,92,3,8,22};
	static int N=key.length;	//散列表长度
	static int ht[]=new int[N];
	public static void main(String[] args) {
		for (int i = 0; i < ht.length; i++) {
			ht[i]=-1;	//初始化，可根据实际情况初始化
		}
	//	System.out.println(N);
		System.out.print("散列地址:");
		for (int i = 0; i < ht.length; i++) {
			System.out.print(i+"	");
		}
		
		for (int i = 0; i < key.length; i++) {
			hashSearch(ht,N,key[i]);
		}
		
		System.out.println();
		System.out.print("关键码:");
		for (int i = 0; i < ht.length; i++) {
			System.out.print(ht[i]+"	");
		}
		
	}
	//散列表下标
	static int h(int v){
		return v%N;
	}
	
	static int hashSearch(int ht[],int len,int k){
		int j=h(k);
		if (ht[j]==k) {//查找成功
			return j;
		}else if(ht[j]==-1){//该位置为空，插入，返回
			ht[j]=k;
			return j;
		}
		int i=(j+1)%N;
		while (ht[i]!=-1&&i!=j) {//循环遍历散列表
			if(ht[i]==k){
				return i;
			}else {
				i=(++i)%N;
			}
		}
		if (i==j) {//遍历散列表一遍，没找到，满
			System.err.println("哈希表溢出！");
		}else {
			ht[i]=k;
			return i;
		}
		return 0;
	}
	
}
 
