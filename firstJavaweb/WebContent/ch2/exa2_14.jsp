<%@ page contentType="text/html; charset=ISO-8859-1"
	pageEncoding="UTF-8"%>
<%@ page info="info中常常写JSP页面的版本及作者等信息"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>page指令</title>
</head>
<body>
	<%
		String s = getServletInfo();
		out.println(s);
	%>
</body>
</html>