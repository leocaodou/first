<%@ page contentType="text/html;charset=GB2312" isErrorPage="true" %>
<html>
<head>
<title>Exception.jsp</title>
</head>
<body>
<h2> exception ∂‘œÛ</h2>
Exception£∫<%= exception %><br>
Message£∫<%= exception.getMessage() %><br>
Localized Message£∫<%= exception.getLocalizedMessage() %><br>
Stack Trace£∫<% exception.printStackTrace(new java.io.PrintWriter(out));
%><br>
</body>
</html>