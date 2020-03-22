<%@ page contentType="text/html;charset=UTF-8" %>
<HTML>
<BODY>
   <% String s=session.getId();
   %>
<P> 您在id3页面中的session对象的ID是：  
 <br>  <%=s%>
<P> 点击超链接，连接到id1的页面。
<A HREF="id1.jsp"> 
 <BR>  欢迎到id1页面来。
</A>   
</BODY>
</HTML>