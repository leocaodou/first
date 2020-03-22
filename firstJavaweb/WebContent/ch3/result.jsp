<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		String str = request.getParameter("num");
		if (str == null) {
			str = "0";
		}
		int guessNumber = Integer.parseInt(str);
		Integer integer = (Integer) session.getAttribute("save");
		int realnumber = integer.intValue();
		if (guessNumber == realnumber) {
			int n = ((Integer) session.getAttribute("count")).intValue();
			n = n + 1;
			session.setAttribute("count", new Integer(n));
			response.sendRedirect("success.jsp");
		} else if (guessNumber > realnumber) {
			int n = ((Integer) session.getAttribute("count")).intValue();
			n = n + 1;
			session.setAttribute("count", new Integer(n));
			response.sendRedirect("large.jsp");
		} else if (guessNumber < realnumber) {
			int n = ((Integer) session.getAttribute("count")).intValue();
			n = n + 1;
			session.setAttribute("count", new Integer(n));

			response.sendRedirect("small.jsp");
		}
	%>
</body>
</html>