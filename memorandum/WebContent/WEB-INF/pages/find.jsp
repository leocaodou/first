<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<%@ page import="dao.impl.*"%><!-- 使用JavaBean的dao.impl包的所有类 -->
<%@ page import="domain.*" %><!-- 使用JavaBean的domain包的所有类 -->
<%@ page import="util.Conn" %><!-- 使用JavaBean的Conn类 -->
<%@ page import="java.util.Date"%>
<%@ page import="java.time.LocalDateTime" %>
<%@ page import="java.text.*"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>查找备忘录</title>
	<link rel="stylesheet" type="text/css" href="css/main.css">
</head>
<body>
	<%!int n,id; %>
	<%
		User user = (User)session.getAttribute("user");
		if(user != null)
		{
			id = user.getUserID();
			MemorandumDao memdao = new MemorandumDao();
			Date date=new Date();
			DateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
			String dateString = df.format(date);
			
	%>
	<form action="./find" class="center"><!-- 连接的就是本页面 -->
		查找的开始时间<input type="text" value="2020-01-01 00:00:00" name="begin">
		查找的结束时间<input type="text" value="<%=dateString%>" name="end">
		<input type="submit" value="查找">
	</form>
	<%
			request.setCharacterEncoding("UTF-8");
			String begin = request.getParameter("begin");
			String end = request.getParameter("end");
			Date beg=null;
			Date en=null;
			if(begin == null || end == null)
			{
	%>
	<h1>请输入查找的时间</h1>
	<%
			}
			else
			{
				try {
					beg = df.parse(begin);
					en = df.parse(end);
				}
				catch(ParseException e)
				{
					e.printStackTrace();
				}
				Connection con;
				ResultSet rs;
				try
				{
					Conn conn = new Conn();
					con = conn.getCon();
					PreparedStatement pstmt = con.prepareStatement("select * from memorandum WHERE userID=? and createDate>=? and createDate<=?");
					pstmt.setInt(1, id);
					Timestamp t = new Timestamp(beg.getTime());
					pstmt.setTimestamp(2, t);
					t = new Timestamp(en.getTime());
					pstmt.setTimestamp(3, t);
					rs = pstmt.executeQuery();
					while(rs.next())
					{
						String content = rs.getString("content");
						Timestamp timestamp = rs.getTimestamp("createDate");
						Date createDate = new Date(timestamp.getTime());
						String dateString2 = df.format(createDate);
	%>
		<div class="notepaper">
		  	<figure class="quote">
		    	<blockquote class="curly-quotes">
		      		<%=content %>
		    	</blockquote>
		    	<figcaption class="quote-by">写于<%=dateString2%></figcaption>
		  	</figure>
		</div>
	<%
					}
				}
				catch(Exception e)
				{
					throw new RuntimeException(e);
				}
			}
	%>
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