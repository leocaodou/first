<%@ page info="JSP隐含对象page" contentType="text/html;charset=gb2312" %>

<html>
<head>
  <title>PageInfo.jsp</title>
</head>
<body>

<h2>page隐含对象</h2>
Page Info = 
     <%= ((javax.servlet.jsp.HttpJspPage)page).getServletInfo() %>

</body>
</html>