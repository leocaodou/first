<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="domain.User" %><!-- 使用JavaBean的User类 -->
<%@ page import="java.util.Date"%>
<%@ page import="java.text.*"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>欢迎界面</title>
	<link rel="stylesheet" type="text/css" href="css/main.css">
</head>
<body>
	<%
		User user = (User)session.getAttribute("user");
		int id = user.getUserID();
		Date date = new java.util.Date();
		DateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		String dateString = df.format(date);
		request.setAttribute("date", dateString);
		if(user != null)
		{
			String name = user.getUserName();	
	%>
	<h1><%=name%>，欢迎你</h1>
	<br><br>
	<div class="center">
		<a href="index.html">退出登陆</a>
	</div>
	<h1>马上创建备忘录？</h1>
	<form method="post" name="note" action="note?date=<%=dateString%>&userID=<%=id%>"><!-- 连接的是NoteServlet -->
		<div class="notepaper">
		  	<figure class="quote">
		    	<blockquote class="curly-quotes">
		      		<textarea name="content" ></textarea>
		    	</blockquote>
		    	<figcaption class="quote-by">写于<%=dateString%></figcaption>
		  	</figure>
		</div>
		<div class="center">
			<input type="submit" value="写好啦" class="but">
		</div>
	</form>
	<br><br>
	<br>
	<div class="center">
		<a href="./check">查找备忘录</a>
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