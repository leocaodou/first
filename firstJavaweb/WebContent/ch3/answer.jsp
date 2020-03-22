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
		int num = 0;
		String s1 = request.getParameter("girl");
		String s2 = request.getParameter("boy");
		if (s1 == null)
			s1 = "";
		if (s2 == null)
			s2 = "";
		if (s1.equals("d"))
			num++;
		if (s2.equals("d"))
			num++;
	%>
	<p>
		您得了<%=num%>分
</body>
</html>