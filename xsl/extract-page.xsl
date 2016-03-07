<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">
  <xsl:output method="html" indent="yes"/>
  <xsl:param name="page">2</xsl:param>

  <xsl:template match="//div[@class = 'TEI']">
    <html>
      <head></head>
      <body>
        <xsl:apply-templates select="(//span[@class = 'pb-title'])[position() = $page]"/>
        <!-- <xsl:copy-of select="//span[@class = 'pb-title']"/> -->
      </body>
    </html>
  </xsl:template>

  <xsl:template match="span[@class = 'pb-title']">
    <xsl:copy-of select="following-sibling::* | following-sibling::text()"/>
  </xsl:template>
  
  <xsl:template match="text()">
  </xsl:template>
</xsl:stylesheet>
