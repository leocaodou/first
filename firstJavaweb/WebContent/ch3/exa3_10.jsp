<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<title>Insert title here</title>
</head>
<body>
	<P>
		动态设置mime类型的例子 <BR/>
		setContentType方法
	<P>当你点击按钮时当前页面就会显示在word文档下
	<FORM action="" method="get" name=form>
		<INPUT TYPE="submit" value="yes" name="submit">
	</FORM>
	<% String str=request.getParameter("submit");
      if(str==null) 
         {str="";
         }
      if(str.equals("yes"))
         {
    	  response.setContentType("text/plain;charset=UTF-8");
         }
%>
</body>
</html>