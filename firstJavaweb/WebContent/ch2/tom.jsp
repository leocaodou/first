<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<body>
<p>我是接收者tom
<%
	String str = request.getParameter("computer");
%>
   <P>您传过来的值是:<BR>
    <%=str%>
</body>
</html>