package controller;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import service.IAdminService;
import service.impl.AdminServiceImpl;
import domain.Admin;

public class RegisteServlet extends HttpServlet{
	private static final long serialVersionUID = 1L;
	public RegisteServlet() {
        super();
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		Admin admin = new Admin();
		response.getWriter().append("Served at: ").append(request.getContextPath());
		admin.setAdminName(request.getParameter("Name"));
		admin.setPassword(request.getParameter("Paw1"));
		admin.setRealName(request.getParameter("RealName"));
		IAdminService adminService = new AdminServiceImpl();
		boolean rs = adminService.registerAdmin(admin);
		PrintWriter out = response.getWriter();
		if(rs == true)
		{
			out.print("<html>");
			out.print("<head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" /></head>");
			out.print("<script language='javascript' >alert('注册成功，登陆吧!');window.location.href='index.html';</script>");
			out.print("</html>");
		}
		else
		{
			out.print("<html>");
			out.print("<head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" /></head>");
			out.print("<script language='javascript' >alert('注册失败，您已经注册过了，请直接登陆!');window.location.href='index.html';</script>");
			out.print("</html>");
		}
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}
}
