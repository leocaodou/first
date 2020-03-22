<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>jsp notes</title>
</head>
<body>
	<br/>HTML注释的例子：
	<!--This page was loaded on <%=(new java.util.Date()).toString()%> 这是一个HTML注释 -->
	<br />隐藏注释也称为JSP注释的例子：
	<%--需要显示当前时间(隐藏注释也称为JSP注释) --%>
	<%=(new java.util.Date()).toString()%>
	<br />脚本注释的例子：
	<%
		int i = 8;
		i = i * i; //去i的平方
		out.print(i);//输出i的最终结果
	%>
</body>
</html>