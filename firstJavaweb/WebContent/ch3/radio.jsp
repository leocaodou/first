<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<form action="answer.jsp" method="post" name=form>
		<p>
			1. 诗人李清照是中国历史上哪个朝代的人？ <br /> 
			<input type="radio" name="girl"	value="a" checked="aa">a 清朝 
			<input type="radio" name="girl" value="b">b 唐朝 
			<input type="radio" name="girl" value="c">c 明朝
			<input type="radio" name="girl" value="d">d 宋朝 
			<br>
		<p>
			2. 《史记》的作者是谁？ <br /> 
			<input type="radio" name="boy" value="a">a 曹雪芹
			<input type="radio" name="boy" value="b">b 罗贯中 
			<input type="radio" name="boy" value="c">c 李白
			<input type="radio" name="boy" value="d">d 司马迁 
			<input type="submit" name="submit" value="提交答案">
	</form>
</body>
</html>