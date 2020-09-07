package controller;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dao.impl.SelectDao;
import dao.impl.PaperDao;
import domain.Paper;
import javax.servlet.http.HttpSession;
import util.Conn;

public class CheckitServlet extends HttpServlet{
	private static final long serialVersionUID = 1L;
	public CheckitServlet() {
        super();
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		int paperID=Integer.parseInt(request.getParameter("paperID"));
		HttpSession session = request.getSession();
		session.setAttribute("paperID", paperID);
		request.getRequestDispatcher("/WEB-INF/pages/show.jsp").forward(request, response);
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}
}
