<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
	<html>
		<head>
			<style type="text/css">
  				@import url("2018011252-刘科宏-9-homework.css");
			</style>
			<title>Leo刘科宏</title>
		</head>
		<body>
			<h2>XSL element</h2>
			<table border = "1">
				<tr bgcolor ="#0080FF">
					<th >Name</th>
       				<th>Descrption</th>
       			</tr>
       			<xsl:for-each select = "elements/kind">
       				<tr>
       					<td><xsl:value-of select = "name"/></td>
       					<td><xsl:value-of select = "descrption"/></td>
       				</tr>
       			</xsl:for-each>
       		</table>
       	</body>
	</html>
</xsl:template>
</xsl:stylesheet>