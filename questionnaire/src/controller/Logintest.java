package controller;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dao.impl.PaperDao;
import domain.Admin;
import service.IAdminService;
import service.impl.AdminServiceImpl;

public class Logintest extends HttpServlet{
	private static final long serialVersionUID = 1L;
	public Logintest() {
        super();
    }
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		response.setHeader("content-type", "text/html; charset=UTF-8");
		String reqMethod = request.getMethod();
		PrintWriter writer = response.getWriter();
		PaperDao paperdao = new PaperDao();
		String adminName = request.getParameter("adminName");
		String adminPaw = request.getParameter("adminPaw");
		IAdminService adminService = new AdminServiceImpl();
		Admin admin = adminService.loginAdmin(adminName, adminPaw);
		int n = paperdao.count(admin.getAdminID());
		switch(reqMethod) {
		case "GET":
			writer.println("{\"用户名\"：\""+adminName +"\"" + ",\"录入题数\"：\""+n + "\"}");
			break;
		case "POST":
			writer.println("{登陆成功，用户类型为管理员}");
			break;
		}
	}
}