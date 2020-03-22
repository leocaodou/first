<%@ page contentType="text/html;charset=UTF-8"%>
<%@ page import="java.util.*"%>
<HTML>
<BODY>
	<%
		request.setCharacterEncoding("UTF-8");
		Vector v = (Vector) application.getAttribute("Mess");
		for (int i = 0; i < v.size(); i++) {
			String message = (String) v.elementAt(i);
			StringTokenizer fenxi = new StringTokenizer(message, "#");
			while (fenxi.hasMoreTokens()) {
				String str = fenxi.nextToken();
				//byte a[] = str.getBytes("ISO-8859-1");
				//str = new String(a);
				out.print("<BR>" + str);
			}
		}
	%>
</BODY>
</HTML>