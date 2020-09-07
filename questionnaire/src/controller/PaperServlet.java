package controller;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.*;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import domain.Paper;
import domain.Admin;
import dao.impl.PaperDao;
import javax.servlet.http.HttpSession;


public class PaperServlet extends HttpServlet{
	private static final long serialVersionUID = 1L;
	public PaperServlet() {
        super();
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		Paper paper = new Paper();
		HttpSession session = request.getSession();
		Admin admin = (Admin)session.getAttribute("admin");
		response.getWriter().append("Served at: ").append(request.getContextPath());
		paper.setTitle(request.getParameter("title"));
		paper.setAdminID(admin.getAdminID());
		DateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		try {
			paper.setOperateDate(df.parse(request.getParameter("od")));
			paper.setEndDate(df.parse(request.getParameter("ed")));
		}
		catch(ParseException e)
		{
			e.printStackTrace();
		}
		paper.setThanks(request.getParameter("thx"));
		PaperDao paperdao = new PaperDao();
		int paperID=paperdao.add(paper);
		session.setAttribute("paperID", paperID);
		request.getRequestDispatcher("/WEB-INF/pages/question.html").forward(request, response);
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}
}
