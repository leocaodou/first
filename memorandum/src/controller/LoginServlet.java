package controller;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import service.IUserService;
import service.impl.UserServiceImpl;
import domain.User;

public class LoginServlet extends HttpServlet{
	private static final long serialVersionUID = 1L;
	public LoginServlet() {
        super();
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		String userName = request.getParameter("userName");
		String userPaw = request.getParameter("password");
		IUserService userService = new UserServiceImpl();
		PrintWriter out = response.getWriter();
		User user = userService.loginUser(userName, userPaw);
		if(user != null)
		{
			HttpSession session = request.getSession();
			session.setAttribute("user",user);
			request.getRequestDispatcher("/WEB-INF/pages/main.jsp").forward(request, response);
		}
		else
		{
			out.print("<html>");
			out.print("<head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" /></head>");
			out.print("<script language='javascript' >alert('用户名或密码错误!!');window.location.href='index.html';</script>");
			out.print("</html>");
		}
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}
}
