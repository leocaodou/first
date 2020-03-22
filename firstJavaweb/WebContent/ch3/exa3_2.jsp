<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<FORM action="exa3_2.jsp" method=post name=form>
		<INPUT type="text" name="girl"> 
		<INPUT TYPE="submit" value="Enter" name="submit">
	</FORM>
	<%
		String textContent = request.getParameter("girl");
	    if (textContent==null || textContent.equals("") )
	    	textContent="0";
		double number = 0, r = 0;
		number = Double.parseDouble(textContent);
		if (number >= 0) {
			r = Math.sqrt(number);
			out.print("<BR>" + String.valueOf(number) + "的平方根：");
			out.print("<BR>" + String.valueOf(r));
		} else {
			out.print("<BR>" + "请输入一个正数");
		}
		/*
		try {
			if (textContent!=null && !textContent.equals("") ){
				number = Double.parseDouble(textContent);
				if (number >= 0) {
					r = Math.sqrt(number);
					out.print("<BR>" + String.valueOf(number) + "的平方根：");
					out.print("<BR>" + String.valueOf(r));
				} else {
					out.print("<BR>" + "请输入一个正数");
				}
			}
			
		} catch (NumberFormatException e) {
			out.print("<BR>" + "请输入数字字符");
		}*/
	%>
</body>
</html>