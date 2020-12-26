import org.apache.hadoop.io.Text;
import org.apache.hadoop.io.WritableComparable;
import org.apache.hadoop.io.WritableComparator;


public class SortComparator extends WritableComparator {
	protected SortComparator(){
		super(Text.class,true);
	}
	@Override
	public int compare(WritableComparable key1, WritableComparable key2) {
		// TODO Auto-generated method stub
		int key1_0=Integer.parseInt(key1.toString().split(" ")[0]);
		int key1_1=Integer.parseInt(key1.toString().split(" ")[1]);
		int key2_0=Integer.parseInt(key2.toString().split(" ")[0]);
		int key2_1=Integer.parseInt(key2.toString().split(" ")[1]);
		if(key1_0==key2_0){
			if(key1_1>key2_1){
				return 1;
			}else if(key1_1<key2_1){
				return -1;
			}else{
				return 0;
			}
		}else{
			if(key1_0>key2_0){
				return 1;
			}else if(key1_0<key2_0){
				return -1;
			}
		}
		return 0;
	}
	
}
