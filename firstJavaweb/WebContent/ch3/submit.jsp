<%@ page contentType="text/html;charset=UTF-8" %>
<HTML>
<BODY>
 <FORM action="messagePane.jsp" method="post" name="form">
    <P>输入您的名字：
    <INPUT  type="text" name="peopleName">
     <BR>
     <P>输入您的留言标题：
    <INPUT  type="text"  name="Title">
     <BR>
     <P>输入您的留言：
    <BR>
    <TEXTAREA name="messages" ROWs="10" COLS=36 WRAP="physical">
    </TEXTAREA>
    <BR>
    <INPUT type="submit" value="提交信息" name="submit">
 </FORM>
 
 <FORM action="showMessage.jsp" method="post" name="form1">
    <INPUT type="submit" value="查看留言板" name="look">
 </FORM>
</BODY>
</HTML>