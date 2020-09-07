package controller;

import java.io.IOException;
import java.io.PrintWriter;
import java.text.*;
import java.util.Date;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import domain.Select;
import domain.Question;
import dao.impl.SelectDao;
import javax.servlet.http.HttpSession;

public class SelectServlet extends HttpServlet{
	private static final long serialVersionUID = 1L;
	public SelectServlet() {
        super();
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		Select select = new Select();
		HttpSession session = request.getSession();
		int questionID = Integer.parseInt(session.getAttribute("questionID").toString());
		response.getWriter().append("Served at: ").append(request.getContextPath());
		select.setQuestionID(questionID);
		select.setSelectOrder(request.getParameter("selectOrder"));
		select.setSelectContent(request.getParameter("title"));
		SelectDao  selectdao = new SelectDao();
		selectdao.add(select);
		PrintWriter out = response.getWriter();
		if(request.getParameter("next").equals("设置下一个选项"))
			request.getRequestDispatcher("/WEB-INF/pages/select.html").forward(request, response);
		else if(request.getParameter("next").equals("设置下一个问题"))
			request.getRequestDispatcher("/WEB-INF/pages/question.html").forward(request, response);
		else
		{
			out.print("<html>");
			out.print("<head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" /></head>");
			out.print("<script language='javascript' >alert('问卷设置成功!');window.location.href='./main';</script>");
			out.print("</html>");
		}
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}
}
