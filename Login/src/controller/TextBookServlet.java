package controller;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import domain.TextBook;
import domain.User;
import dao.TextBookDao;
import dao.UserDao;
/**
 * Servlet implementation class LoginServlet
 */
public class TextBookServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public TextBookServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String type = request.getParameter("type");
		switch(type){
		case"insert":doInsert(request,response);
		break;
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}
	protected void doInsert(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String className = request.getParameter("className");
		String bookName = request.getParameter("bookName");
		String publisher = request.getParameter("publisher");
		String num = request.getParameter("num");

		TextBook textBook = new TextBook();
		textBook.setClassName(className);
		textBook.setBookName(bookName);
		textBook.setPublisher(publisher);
		textBook.setNum( Integer.parseInt(num));
		
		TextBookDao textBookDao = new TextBookDao();
		int count = textBookDao.Insert(textBook);
		if (count==1)
		{
			request.getRequestDispatcher("/WEB-INF/pages/success.html")
			.forward(request, response);	
		}
		else
			response.sendRedirect("../AddTextBook.html");
	}
}
		
		
		

