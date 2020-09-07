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
import domain.Paper;
import domain.Question;
import dao.impl.QuestionDao;
import javax.servlet.http.HttpSession;

public class QuestionServlet extends HttpServlet{
	private static final long serialVersionUID = 1L;
	public QuestionServlet() {
        super();
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		Question question = new Question();
		HttpSession session = request.getSession();
		int paperID = Integer.parseInt(session.getAttribute("paperID").toString());
		response.getWriter().append("Served at: ").append(request.getContextPath());
		question.setTitle(request.getParameter("title"));
		question.setPaperID(paperID);
		question.setQuestionOrder(Integer.parseInt(request.getParameter("questionOrder")));
		question.setQuestionType(request.getParameter("type"));
		QuestionDao questiondao = new QuestionDao();
		int questionID=questiondao.add(question);
		session.setAttribute("questionID", questionID);
		request.getRequestDispatcher("/WEB-INF/pages/select.html").forward(request, response);
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}
}
