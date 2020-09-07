package controller;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import service.IAdminService;
import service.impl.AdminServiceImpl;
import domain.Admin;
import dao.impl.PaperDao;

public class LoginServlet extends HttpServlet{
	private static final long serialVersionUID = 1L;
	public LoginServlet() {
        super();
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		String adminName = request.getParameter("adminName");
		String adminPaw = request.getParameter("adminPaw");
		IAdminService adminService = new AdminServiceImpl();
		PrintWriter out = response.getWriter();
		Admin admin = adminService.loginAdmin(adminName, adminPaw);
		if(admin != null)
		{
			HttpSession session = request.getSession();
			session.setAttribute("admin",admin);
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
