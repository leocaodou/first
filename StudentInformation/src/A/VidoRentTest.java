package A;
import java.util.Scanner; 
public class VidoRentTest
{
	public static void main(String[] args){
		Customer head = null;
		while(true)
		{
			System.out.println("请输入顾客的名字");
			Scanner in = new Scanner(System.in);
			String name = in.next();
			Customer p = CheckCustomer(name,head);
			if(p == null)
			{
				System.out.println("这名顾客没有在这租过影片");
				p = new Customer(name);
				p.next = head;
				head = p;
			}
			else
			{
				System.out.println("这名顾客在这租过影片");
			}
			while(true)
			{
				System.out.println("请输入这名顾客租过影片的类型和天数");
				name = in.next();
				int day = in.nextInt();
				vido x = new vido(name,day);
				p.addVido(x);
				System.out.println("这名顾客还有租过其他影片吗？是的话输入1，不是的话输入2");
				int i = in.nextInt();
				if(i == 2)
					break;
			}
			System.out.println("这名顾客需要支付：" + p.getSumRent() +"元");
			System.out.println("这名顾客有积分：" + p.getAp() + '\n');
			System.out.println("这要录入其他顾客信息吗？是的话输入1，不是的话输入2");
				int i = in.nextInt();
				if(i == 2)
					break;
		}
	}
	private static Customer CheckCustomer(String name, Customer head) {
		Customer p = head;
		while(true)
		{
			if(p == null)
				return p;
			if(p.name.equals(name))
			{
				return p;
			}
			else
			{
				p = p.next;
			}
		}
	}
}
