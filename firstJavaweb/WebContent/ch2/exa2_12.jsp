<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>多个代码段</title>
</head>
<body>
	<%!
	long continueSum(int n) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum = sum + i;
		}
		return sum;
	}%>
	<P>
		第一个代码段声明了一个long型变量sum：
		<%
		long sum;
	%>	
	<P>
		第二个代码段调用方法continueSum，
		<%
			sum = continueSum(51);
		%>	
	<P>
		第三个代码段将调用方法continueSum得到的值显示到客户： <BR>
	<P>
		1到n的连续和是：
		<%=sum%>
		<%
			if (sum >= 55) {
		%>
	<P>
		您计算的项数超过10项了。
		<%
			} //注意写法
			else {
		%>
	<P>
		您计算的项数没有超过10项。
		<%
			}
		%>
</body>
</html>