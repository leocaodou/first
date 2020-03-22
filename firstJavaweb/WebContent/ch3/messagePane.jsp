<%@ page contentType="text/html;charset=UTF-8"%>
<%@ page import="java.util.*"%>
<HTML>
<BODY>
	<%!
		Vector<String> v = new Vector<String>();
		int i = 0;
		ServletContext application;
	
		synchronized void sendMessage(String s) {
			application = getServletContext();
			i++;
			v.add("No." + i + "," + s);
			application.setAttribute("Mess", v);
		}
	%>
	<%
		request.setCharacterEncoding("UTF-8");
		String name = request.getParameter("peopleName");
		String title = request.getParameter("Title");
		String messages = request.getParameter("messages");
		if (name == null) {
			name = "guest" + (int) (Math.random() * 10000);
		}
		if (title == null) {
			title = "无标题";
		}
		if (messages == null) {
			messages = "无信息";
		}
		String s = "Name:" + name + "#" + "Title:" + title + "#" + "Content:" + "<BR>" + messages;
		sendMessage(s);
		out.print("您的信息已经提交！");
	%>
	<A HREF="submit.jsp">返回 </A>
</BODY>
</HTML>