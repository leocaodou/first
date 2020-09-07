<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="domain.Admin" %>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>欢迎界面</title>
	<link rel="stylesheet" type="text/css" href="css/main.css">
</head>
<body>
	<%
		Admin admin = (Admin)session.getAttribute("admin");
		if(admin != null)
		{
			String name = admin.getAdminName();	
	%>
	<h1><%=name%>，欢迎你</h1>
	<form name="logout" class="center" action="logout" method="post">
		<p><input class="but" value="退出登陆" type="submit"></p>
	</form>
	<div class="center">
		<p>请选择你管理员功能</p>
		<br><br><br><br><br>
		<br><br><br><br><br>
		<br><br>
		<form name="makepaper" action="makepaper" method="post">
			<p><input class="but" value="创建问卷" type="submit">
		</form>
		<a href="./check">查看问卷结果</a>
	</div>
	<%
		}
		else
		{
			out.println("<h1>请您先登陆，谢谢</h1>");
			out.println("<br><h1>经过5秒之后，将自动返回index.html</h1>");
			response.setHeader("Refresh","5;URL=index.html");
		}
	%>
</body>
</html>