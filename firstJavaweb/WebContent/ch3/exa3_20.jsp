<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>3_20</title>
</head>
<body>
	<%!
	    synchronized void countPeople() {
			ServletContext application = getServletContext();
			Integer number = (Integer) application.getAttribute("Count");
			if (number == null) {
				number = new Integer(1);
				application.setAttribute("Count", number);
			} else {
				number = new Integer(number.intValue() + 1);
				application.setAttribute("Count", number);
		}
	}%>
	<%
		if (session.isNew()) {
			countPeople();
			Integer myNumber = (Integer) application.getAttribute("Count");
			session.setAttribute("MyCount", myNumber);
		}
		else
			out.print("不是新用户");
	%>
	<P>
	<P>
		您是第
		<%
		int a = ((Integer) session.getAttribute("MyCount")).intValue();
	%>
		<%=a%>
		个访问本站的客户。
</body>
</html>