<%@ page language="java" contentType="text/html; charset=UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv=Content-Type content="text/html; charset=UTF-8">
<title>Jsp的例子</title>
<BODY>
	<FONT size=4>
		<P>
			文本框提交的用户名为：
			<%
			request.setCharacterEncoding("UTF-8");
			String textContent = request.getParameter("boy");
			 //byte  b[]=textContent.getBytes("ISO-8859-1");
			 //textContent=new String(b);
		%>
			<BR>
			<%=textContent%>
		<P>
			客户端提交的按钮的名字为：
			<%
			String buttonName = request.getParameter("submit");
		%>
			<BR>
			<%=buttonName%>
	</FONT>
</BODY>
</HTML>
