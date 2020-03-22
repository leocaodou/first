<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%	
	String Login = (String)session.getAttribute("Login");
	
	if (Login != null && Login.equals("OK")) {		
		out.println("欢迎您的到来!");
		session.invalidate();	
	}	
	else {		
		out.println("请您先登陆，谢谢");
		out.println("<br>经过3秒之后，将自动返回Login.jsp");
		
		response.setHeader("Refresh","3;URL=Login.jsp");	
	}
%>

</body>
</html>