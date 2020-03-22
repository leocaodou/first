<%@page contentType="text/html;charset=GBK"%>
<html>
<body bgcolor="#ffccac">
	Value being seting...
	<% 
	   pageContext.setAttribute("pageAttr","pageValue",PageContext.PAGE_SCOPE);
	   pageContext.setAttribute("requestAttr","requestValue",PageContext.REQUEST_SCOPE);
	   session.setAttribute("sessionAttr","sessionValue");
	   application.setAttribute("appAttr","appValue");
	   pageContext.forward("scopeexample2.jsp");
   %>
</body>
</html>