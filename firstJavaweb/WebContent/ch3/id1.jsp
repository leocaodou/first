<%@ page contentType="text/html;charset=UTF-8" %>
<HTML>
<BODY>
<P>
   <% String s=session.getId();
   %>
<P> 您的session对象的ID是：
   <BR>  
   <%=s%>
<p>单击超连接，可到id2页面
<a href="id2.jsp">
<br>欢迎到id2页面来。
</a> 
</BODY>
</HTML>