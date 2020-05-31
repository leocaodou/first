package controller;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import domain.User;
import dao.UserDao;
/**
 * Servlet implementation class LoginServlet
 */
public class RegisteServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public RegisteServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub

		response.getWriter().append("Served at: ").append(request.getContextPath());
		String yourName = request.getParameter("yourname");
		String yourPass = request.getParameter("yourpass");
//		String yourEmail = request.getParameter("youremail");
		String yourAge = request.getParameter("yourage");
		
		User user = new User();
		user.setUserID(8);
		user.setName(yourName);
		user.setPwd(yourPass);
		user.setAge(Integer.parseInt(yourAge));
		UserDao userDao = new UserDao();
		userDao.add(user);
		response.sendRedirect("../index.html");
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}
}
