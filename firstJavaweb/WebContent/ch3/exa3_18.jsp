<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<P>
		随机分给了你一个1到100之间的数，请猜！
	<%    
     int number=(int)(Math.random()*100)+1;
     session.setAttribute("count",new Integer(0));
     session.setAttribute("save",new Integer(number));
  	%>
	<BR/>
	<P>输入你的所猜的数
	<FORM action="result.jsp" method="post" name=form>
		<INPUT type="text" name="num"> 
		<INPUT TYPE="submit" value="送出" name="submit">
	</FORM>
	
</body>
</html>