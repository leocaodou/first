<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<%@ page import="dao.impl.PaperDao"%>
<%@ page import="domain.Admin" %>
<%@ page import="util.Conn" %>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>查询问卷结果</title>
</head>
<body>
	<%!int n,id; %>
	<%
		Admin admin = (Admin)session.getAttribute("admin");
		if(admin != null)
		{
			id = admin.getAdminID();
			PaperDao paperdao = new PaperDao();
			n = paperdao.count(id);
	%>
	<h2>你一共创建了<%=n%>了个问卷</h2>
	<%
			request.setCharacterEncoding("UTF-8");
			Connection con;
			ResultSet rs;
			try
			{
				Conn conn = new Conn();
				con = conn.getCon();
				PreparedStatement pstmt = con.prepareStatement("select * from paper WHERE adminID=?");
				pstmt.setInt(1, id);
				rs = pstmt.executeQuery();
				while(rs.next())
				{
					int paperID=rs.getInt("paperID");
					String title=rs.getString("title");
					request.setAttribute("PaperTitle", title);
	%>
		<a href="./checkit?paperID=<%=paperID%>"><%=title%></a><br>
	<%
				}
				rs.previous();
			}
			catch(Exception e)
			{
				throw new RuntimeException(e);
			}
	%>
	<h2>请选择你要查看的问卷</h2>
	<% 
		}
		else
		{
			out.println("<h1>请您先登陆，谢谢</h1>");
			out.println("<br><h1>经过5秒之后，将自动返回index.html</h1>");
			response.setHeader("Refresh","5;URL=index.html");
		}
	%>
	
</body>
</html>