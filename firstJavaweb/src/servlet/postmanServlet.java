package servlet;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class postmanServlet extends HttpServlet{
	protected void service(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException 
	{
		req.setCharacterEncoding("UTF-8");
		res.setCharacterEncoding("UTF-8");
		res.setHeader("content-type", "text/html; charset=UTF-8");
		
		String reqMethod = req.getMethod(); //请求方式
		String data = ""; //返回数据
		PrintWriter writer = res.getWriter();
		
		switch(reqMethod) {
			case "GET":
				//获取列表
				if (req.getParameter("page") != null) {
					//查询数据库
						//...
						data = "{\"list\": [\"item1\", \"item2\", \"item3\", \"item4\"]}";
					//返回
					writer.println(data);
					break;
				}
				//根据id获取信息
				if(req.getParameter("id") != null) {
					//查询数据库
						//...
						data = "{\"detail\": \"itemDetail\"}";
					//返回
					writer.println(data);
					break;
				}
				//请求参数错误
				data = "{\"err\": \"GET请求，参数错误\"}";
				writer.println(data);
				break;
			case "POST":
				String userName = req.getParameter("userName");
				String passWord = req.getParameter("passWord");
				String token = req.getParameter("token");
				//登录
				if (userName!=null && passWord!=null && userName.equals("root") && passWord.equals("1")) {
					//查询验证
						//...
						data = "{\"token\": \"1qwr3dret\"}";
					//返回
					writer.println(data);
					break;
				}
				//添加
				if (token!=null && token.equals("1qwr3dret")) {
					//写入数据库
						//...
						data = "{\"result\": \"successed\"}";
					//返回
					writer.println(data);
					break;
				}
				//请求参数错误
				data = "{\"err\": \"POST请求，参数错误\"}";
				writer.println(data);
				break;
			default:
				data = "{\"err\": \"请求方式错误\"}";
				writer.println(data);
				break;
		}
	}	
}
