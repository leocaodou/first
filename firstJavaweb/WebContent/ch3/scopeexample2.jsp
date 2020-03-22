<%@page contentType="text/html;charset=GBK" %>
<html>
<body bgcolor="#ffccac">

<% pageContext.setAttribute("pageAttr","pageValue",PageContext.PAGE_SCOPE);
%>
<% java.util.Enumeration attribNames;
 int scopes[]={PageContext.PAGE_SCOPE,PageContext.REQUEST_SCOPE,PageContext.SESSION_SCOPE,PageContext.APPLICATION_SCOPE};
 String attribName;
 for(int i=0;i<4;i++)
 {
	 switch(scopes[i])
	 {
		 case PageContext.PAGE_SCOPE:out.println("<b>page:</b><br>");
		 break;
		case PageContext.REQUEST_SCOPE:out.println("<b>REQUEST:</b><br>");
		 break;
		case PageContext.SESSION_SCOPE:out.println("<b>SESSION:</b><br>");
		 break;
		 case PageContext.APPLICATION_SCOPE:out.println("<b>APPLICATION:</b><br>");
		 break;
	 }
	 attribNames=pageContext.getAttributeNamesInScope(scopes[i]);
	 while(attribNames.hasMoreElements())
	 {
		 out.print("<b>"+(attribName=(String)attribNames.nextElement())+"</b>");
		 out.print(pageContext.getAttribute(attribName,scopes[i]));
		 out.println("<br>");
	 }
	 out.println("<p>");
 }
 %>
   </body>
   </html>