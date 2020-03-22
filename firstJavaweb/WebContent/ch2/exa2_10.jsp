<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<p>
		请输入正方形边长 <br />
	<form action="exa2_10.jsp" method="get" name=form>
		<input type="text" name="cat"> <input type="submit"
			name="submit" value="送出">
	</form>
	<%!
	   public class square {
		double r;
		square(double r) {
			this.r = r;
		}
		double getarea() {
			return r * r;
		}
		double getlength() {
			return r * 4;
		}
	}%>
	<%
		String s = request.getParameter("cat");
		double r;
		if (s != null) {
			r = Double.valueOf(s).doubleValue();
		} else {
			r = 1;
		}
		square cc = new square(r); //创建对象
	%>
	<P>
		方的面积是： <BR />
		<%=cc.getarea()%>
	<p>
		方的周长是
		<%=cc.getlength()%>
</body>
</html>