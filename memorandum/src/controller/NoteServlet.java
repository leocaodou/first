package controller;

import java.io.IOException;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import dao.impl.MemorandumDao;
import domain.Memorandum;
import domain.User;

public class NoteServlet extends HttpServlet{
	private static final long serialVersionUID = 1L;
	public NoteServlet() {
        super();
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		Memorandum mem = new Memorandum();
		int userID = Integer.parseInt(request.getParameter("userID"));
		mem.setContent(request.getParameter("content"));
		String date = request.getParameter("date");
		DateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		try {
			mem.setCreateDate(df.parse(date));
		}
		catch(ParseException e)
		{
			e.printStackTrace();
		}
		mem.setUserID(userID);
		MemorandumDao memdao = new MemorandumDao();
		memdao.add(mem);
		request.getRequestDispatcher("/WEB-INF/pages/main.jsp").forward(request, response);
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}
}
