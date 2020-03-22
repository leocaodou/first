<%@ page language="java" contentType="text/html; charset=UTF-8"%>
<html>
	<head>
		<title>返回值</title>
	</head>
	<body>
	提交的文本信息为：
		<%
			request.setCharacterEncoding("UTF-8");
			String text1 = request.getParameter("first");
			
		%>
			<%=text1%>
			<br>
	列表的选择为：
		<%
			String text2 = request.getParameter("second");
		%>
			<%=text2%>
			<br>
	</body>
</html>
