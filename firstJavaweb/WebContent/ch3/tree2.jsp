<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.Enumeration" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<BR>客户使用的协议是:
   <% String protocol=request.getProtocol();
      out.println(protocol);
   %>
<BR>获取接受客户提交信息的页面：
   <% String path=request.getServletPath();
      out.println(path);
   %>
<BR>接受客户提交信息的长度：
   <% int length=request.getContentLength();
      out.println(length);
   %>
<BR>客户提交信息的方式：
   <% String method=request.getMethod();
      out.println(method);
   %>
<BR>获取HTTP头文件中User-Agent的值：：
   <% String header1=request.getHeader("User-Agent");
      out.println(header1);
   %>
<BR>获取HTTP头文件中accept的值：
   <% String header2=request.getHeader("accept");
      out.println(header2);
   %>
<BR>获取HTTP头文件中Host的值：
   <% String header3=request.getHeader("Host");
      out.println(header3);
   %>
<BR>获取HTTP头文件中accept-encoding的值：
   <% String header4=request.getHeader("accept-encoding");
      out.println(header4);
   %>
<BR>获取客户的IP地址：
   <% String  IP=request.getRemoteAddr();
      out.println(IP);
   %>
<BR>获取客户机的名称：
   <% String clientName=request.getRemoteHost();
      out.println(clientName);
   %> 
<BR>获取服务器的名称：
   <% String serverName=request.getServerName();
      out.println(serverName);
   %> 
<BR>获取服务器的端口号：
   <% int serverPort=request.getServerPort();
      out.println(serverPort);
   %> 
<BR>获取客户端提交的所有参数的名字：
   <% 
   Enumeration<String> names=request.getParameterNames();
       while(names.hasMoreElements())
            {String s=(String)names.nextElement();
             out.println(s);
            }      
      %> 
<BR>获取头名字的一个枚举：
   <% Enumeration<String> enum_headed=request.getHeaderNames();
      while(enum_headed.hasMoreElements())
            {String s=(String)enum_headed.nextElement();
             out.println(s);
            }      
   %>
<BR>获取头文件中指定头名字的全部值的一个枚举：
   <% Enumeration<String> enum_headedValues=request.getHeaders("cookie");
      while(enum_headedValues.hasMoreElements())
            {String s=(String)enum_headedValues.nextElement();
             out.println(s);
            }      
   %>
<BR>
   <P> 文本框text提交的信息：
   <%String str=request.getParameter("boy");
     byte  b[]=str.getBytes("ISO-8859-1");
     str=new String(b);
   %>
 <BR>
   <%=str%> 
<BR> 按钮的名字：
   <%String buttonName=request.getParameter("submit");
     byte  c[]=buttonName.getBytes("ISO-8859-1");
     buttonName=new String(c);
   %>
<BR>
   <%=buttonName%> 
</body>
</html>