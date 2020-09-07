<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<%@ page import="dao.impl.PaperDao"%>
<%@ page import="domain.Admin" %>
<%@ page import="dao.impl.SelectDao" %>
<%@ page import="dao.impl.PaperDao" %>
<%@ page import="domain.Paper" %>
<%@ page import="util.Conn" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<style>
	li{list-style-type:none;}
</style>
<title>展示问卷结果</title>
</head>
<body>
	<%
		Connection con;
		ResultSet rs;
		int paperID = Integer.parseInt(session.getAttribute("paperID").toString());
		PaperDao paperdao = new PaperDao();
		Paper paper=paperdao.find(paperID);
		String paperTitle=paper.getTitle();
	%>
	<h1><%=paperTitle%></h1>
	<ul>
	<%
		try
		{
			Conn conn = new Conn();
			con = conn.getCon();
			PreparedStatement pstmt = con.prepareStatement("select * from question WHERE paperID=?");
			pstmt.setInt(1, paperID);
			ResultSet rs2;
			rs = pstmt.executeQuery();
			while(rs.next())
			{
				String title=rs.getString("title");
				int questionID=rs.getInt("questionID");
				String type=rs.getString("questionType");
				int questionOrder=rs.getInt("questionOrder");
	%>
	<li><%=questionOrder%>.<%=title%>(<%=type%>)<ul>
	<%
				PreparedStatement pstmt2 = con.prepareStatement("select * from select_table WHERE questionID=?");
				pstmt2.setInt(1, questionID);
				rs2 = pstmt2.executeQuery();
				while(rs2.next())
				{
					String content=rs2.getString("selectContent");
					int selectID=rs2.getInt("selectID");
					String selectOrder=rs2.getString("selectOrder");
	%>
		<li><%=selectOrder%>.<%=content%>------->
	<%
				SelectDao  selectdao = new SelectDao();
				int n=selectdao.num(selectID);
	%>
		有<%=n%>人选择了这个选项</li>
	<%
				}
	%>
	</ul></li>
	<%
			}
		}
		catch(Exception e)
		{
			throw new RuntimeException(e);
		}
	%>
	<a href="./main">返回主界面</a>
</body>
</html>