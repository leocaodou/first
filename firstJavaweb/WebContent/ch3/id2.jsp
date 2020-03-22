<%@ page contentType="text/html;charset=UTF-8"%>
<body>

<% String sid=session.getId();
   
%>
<p>您在id2.jsp中的id号为：
<br><%=sid%>

<p>单击超连接，可到id3页面
<a href="id3.jsp">
<br>欢迎到jid3页面来。
</a>
</body>
</html>