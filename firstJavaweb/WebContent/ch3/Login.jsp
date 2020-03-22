<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<title>Insert title here</title>
</head>
<body>
	<form action="Login.jsp" method="POST">
		Login Name: <input type="text" name="Name" /><br /> 
		Login Password:<input type="password" name="Password" /><br /> 
		<input type="submit"  value="Send" /><br />
	</form>
	<%
		String Name = request.getParameter("Name");
		String Password = request.getParameter("Password");
		if (Name != null && Password != null) {
			if (Name.equals("zhangsan") && Password.equals("12345678")) {
				session.setAttribute("Login", "OK");
				response.sendRedirect("Member.jsp");
			} else {
				out.println("登录失败，请输入正确名称");
			}
		}
	%>
</body>
</html>