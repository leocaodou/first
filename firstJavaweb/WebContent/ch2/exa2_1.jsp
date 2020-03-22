<%@ page language="java" contentType="text/html; charset=UTF-8"%>
<html>
<head>
<meta http-equiv=Content-Type content="text/html; charset=UTF-8">
<title>Jsp的例子</title>
</head>

<body >
	<%!
	int i = 100;
	%>
	<%            
		i++;
		int j = 100;
		j++;
	%>
	<p>
		访问本网页的人均参与变量i的累加，现在i的值为：
		<%=i%>
		<br/> j的值为<%=j%>
</body>
</html>