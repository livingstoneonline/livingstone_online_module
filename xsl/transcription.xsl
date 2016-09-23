<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema" xmlns:xd="http://www.oxygenxml.com/ns/doc/xsl"
	xmlns:tei="http://www.tei-c.org/ns/1.0" xmlns:jc="http://james.blushingbunny.net/ns.html"
	xpath-default-namespace="http://www.tei-c.org/ns/1.0" exclude-result-prefixes="xs xd tei jc"
	version="2.0">
	<xd:doc scope="stylesheet">
		<xd:desc>
			<xd:p><xd:b>Author:</xd:b> James Cummings</xd:p>
			<xd:p>First attempt at LEAP to HTML conversion</xd:p>
			<xd:p>Updated in Feb/Mar 2015.</xd:p>
		</xd:desc>
		<xd:desc>
			<xd:p><xd:b>Author:</xd:b> Adrian S. Wisnicki</xd:p>
			<xd:p>Extensive revisions</xd:p>
			<xd:p>Updated in Aug 2016.</xd:p>
		</xd:desc>
	</xd:doc>
	
	<xsl:output method="xml" indent="no"/>
	<!-- It's necessary that this be "no" or otherwise extra space is kicked in when there are two <span>s in a row. It also appearst to solve other minor formatting issues -->

	<!-- Incoming parameters -->
	<xsl:param name="page" select="'0001'"/>
	<xsl:param name="paged" select="'true'"/>

	<!-- Transform these to global variables in case I need to use them anywhere -->
	<xsl:variable name="pagenumber" select="$page"/>
	<xsl:variable name="isPaged" select="$paged"/>

	<!-- When not producing full HTML files, this template could be removed but javascript and CSS will need to be copied to correct location. -->
	<xsl:template match="/">
		<html>
			<xsl:comment>This HTML has been generated from an XML original. Do not manually modify this as a source.</xsl:comment>
			<head>
				<meta charset="UTF-8"/>
				<link rel="stylesheet" type="text/css" href="style.css"/>
				<title>
					<xsl:value-of select="//teiHeader//title[2]"/>
				</title>
				<!--<link type="text/css" rel="stylesheet" href="http://jamescummings.github.io/LEAP/style.css"/>-->
			</head>
			<body>
				<xsl:apply-templates select="TEI"/>
			</body>
		</html>
	</xsl:template>

	<!-- Don't show -->
	<xsl:template match="teiHeader|facsimile|surface|zone"/>

	<!-- TEI -->
	<xsl:template match="TEI">
		<div class="transcription">
			<!--<button id="toggle" title="toggle" type="button" class="hidden">Show unedited text</button>-->
			<!-- The above is the diplomatic/edited toggle button, which we've turned off because we're using tooltips instead. AW -->
			<!--<h2>
        <xsl:value-of select="//teiHeader//title[2]"/>
			</h2>-->
		<span class="idno"><xsl:value-of select="//idno[@type='LEAP-ID']"/> - project id</span><br/><br/>
			<div class="TEI">
				<xsl:comment><xsl:value-of select="$isPaged"/></xsl:comment>
				<xsl:choose>
					<xsl:when test="$isPaged='true' and //jc:page[@n=$pagenumber]">
						<xsl:apply-templates select="//jc:page[@n=$pagenumber]"/>
					</xsl:when>
					<xsl:when test="$isPaged='false'">
						<xsl:apply-templates select="text"/>
					</xsl:when>
					<xsl:when test="//jc:page[@n=$pagenumber]">
						<xsl:apply-templates select="//jc:page[@n=$pagenumber]"/>
					</xsl:when>
					<xsl:otherwise>
						<xsl:apply-templates select="text"/>
					</xsl:otherwise>
				</xsl:choose>
			</div>
		</div>
	</xsl:template>

	<!-- General match -->
	<xsl:template match="*" priority="-10">
		<xsl:variable name="class">
			<xsl:if test="@rend">
				<xsl:value-of select="translate(@rend, '-', '')"/>
				<xsl:text> </xsl:text>
			</xsl:if>
			<xsl:if test="@place">
				<xsl:value-of select="translate(@place, '-', '')"/>
				<xsl:text> </xsl:text>
			</xsl:if>
			<xsl:if test="@type">
				<xsl:value-of select="translate(@type, '-', '')"/>
				<xsl:text> </xsl:text>
			</xsl:if>
		</xsl:variable>
		<xsl:variable name="title">
			<xsl:for-each select="@*">
				<xsl:sort/>
				<xsl:if test="not(name()='status')">
					<xsl:value-of select="concat(name(),': ', ., '; ')"/>
				</xsl:if>
			</xsl:for-each>
		</xsl:variable>
		<span>
			<xsl:if test="$class/text()">
				<xsl:attribute name="class">
					<xsl:value-of select="$class"/>
				</xsl:attribute>
			</xsl:if>
			<!--<xsl:if test="$title/text()">
				<xsl:attribute name="title">
					<xsl:value-of select="$title"/>
				</xsl:attribute>
			</xsl:if>-->
			<!-- Necessary to turn this off, otherwise it creates wonky tooltips.
			Tooltips as needed should be set on the specific element. -->
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<!-- Make rend class -->
	<xsl:template match="*/@rend" priority="-1">
		<xsl:attribute name="class">
			<xsl:value-of select="concat(parent::node()/name(), ' ')"/>
			<xsl:value-of select="translate(., '-', '')"/>
		</xsl:attribute>
	</xsl:template>


	<!-- Textual divisions -->
	<xsl:template match="text|body|front|back">
		<div class="{concat(name(), ' ', translate(@rend, '-', ''))}">
			<xsl:apply-templates/>
		</div>
	</xsl:template>

	<xsl:template match="div">
		<div class="{concat(name(), ' ', translate(@rend, '-', ''))}">
			<xsl:apply-templates/>
		</div>
		<br/>
	</xsl:template>

	<xsl:template match="lb">
		<xsl:variable name="class">
			<xsl:if test="@rend">
				<xsl:value-of select="translate(@rend, '-', '')"/>
				<xsl:text> </xsl:text>
			</xsl:if>
			<xsl:if test="@place">
				<xsl:value-of select="translate(@place, '-', '')"/>
				<xsl:text> </xsl:text>
			</xsl:if>
			<xsl:if test="@type">
				<xsl:value-of select="translate(@type, '-', '')"/>
				<xsl:text> </xsl:text>
			</xsl:if>
		</xsl:variable>
		<!--<br><xsl:if test="$class/text()"><xsl:attribute name="class"><xsl:value-of select="$class"/></xsl:attribute></xsl:if></br>-->
		<br/>
		<xsl:variable name="num">
			<xsl:number level="any" from="pb"/>
		</xsl:variable>
		<xsl:if test="number($num) mod 5 =0">
			<span class="linenumber">
				<xsl:value-of select="$num"/>
			</span>
		</xsl:if>
	</xsl:template>

	<xsl:template match="choice">
		<xsl:apply-templates/>
	</xsl:template>

	
	<xsl:template match="choice/sic">
			<xsl:variable name="choice-orig-sic">
			<xsl:choose>
				<!-- If there are orig and reg values in the corr, show the orig -->
				<xsl:when test="../corr/choice/orig">
					<xsl:value-of select="../corr/choice/orig"/>
				</xsl:when>
				<!-- If there are sic and corr values in the corr, show both sic and corr -->
				<xsl:when test="../corr/choice/sic">
					<xsl:value-of select="../corr/choice/sic"/> [or] <xsl:value-of select="../corr/choice/corr"/>
				</xsl:when>
				<!-- If there are two rdgs, show both rdgs -->
				<xsl:when test="../corr/app/rdg">
					<xsl:value-of select="../corr/app/rdg[1]"/> [or] <xsl:value-of select="../corr/app/rdg[2]"/>
				</xsl:when>
				<xsl:when test="../corr[not(text())]">[no text]</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="../corr"/>
				</xsl:otherwise>
			</xsl:choose>			
			</xsl:variable>
			<!--<xsl:if test="../corr">
				<xsl:attribute name="title">The editors suggest a correction as follows: <xsl:value-of select="../corr"/></xsl:attribute>
			</xsl:if>-->
			<xsl:copy>
			<xsl:attribute name="title">The editors suggest a correction as follows: <xsl:value-of select="$choice-orig-sic"/></xsl:attribute>
			</xsl:copy>
		<span class="sic diplomatic">	
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<!--<xsl:template match="choice/corr">
		<span class="corr edited hidden">
			<xsl:if test="../sic">
				<xsl:attribute name="title">sic: <xsl:value-of select="../sic"/></xsl:attribute>
			</xsl:if>
			<xsl:apply-templates/>
		</span>
	</xsl:template>-->

	<!-- "Choice" variants begin here -->

	<xsl:template match="abbr|orig">
		<xsl:apply-templates/>
	</xsl:template>

	<xsl:template match="corr|expan|reg|supplied"/>
	
	<!-- Text below removed for annotated edition; also see app, supplied & unclear -->
	
	<!--<xsl:template match="choice/abbr">
		<span class="abbr diplomatic">
			<xsl:if test="../expan">
				<xsl:attribute name="title"><xsl:value-of select="../expan"/></xsl:attribute>
			</xsl:if>
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<xsl:template match="choice/expan">
		<span class="abbr edited hidden">
			<xsl:if test="../abbr">
				<xsl:attribute name="title"><xsl:value-of select="."/></xsl:attribute>
			</xsl:if>
			<xsl:apply-templates select="../abbr[1]/node()"/>
		</span>
	</xsl:template>

	<xsl:template match="choice/orig|choice/reg">
		<xsl:apply-templates/>
	</xsl:template>

	<xsl:template match="orig">
		<xsl:apply-templates/>
	</xsl:template>

	<xsl:template match="reg" priority="10"> </xsl:template>-->

	<!-- "Choice" variants end here -->

	<!-- Alphabetical list of elements. Alphabetized by last element in path *or* first element among options. -->

	<xsl:template match="ab|p">
		<p class="{concat(name(), ' ', translate(@rend, '-', ''))}">
			<xsl:apply-templates/>
		</p>
	</xsl:template>

	<xsl:template match="cb/ab" priority="10">
		<xsl:apply-templates/>
	</xsl:template>

	<!-- For "abbr" see above -->

	<xsl:template match="add">
			<span class="{concat(name(), ' ', translate(@rend, '-', ''), ' ', translate(@place, '-', ''))}">
			<xsl:apply-templates/></span>
	</xsl:template>

	<xsl:template match="add[@place='marginleft']|add[@place='marginright']" priority="10">
		<span class="addmargin"> [<xsl:apply-templates/>] </span>
	</xsl:template>

	<xsl:template match="add[@place='over-text']">
		<span class="{concat(name(), ' ', translate(@rend, '-', ''), ' ', translate(@place, '-', ''))}" title="Addition written over existing text">{<xsl:apply-templates/>}</span>
	</xsl:template>

	<xsl:template match="opener/add">
		<span
			class="opener-add {concat(name(), ' ', translate(@rend, '-', ''), ' ', translate(@place, '-', ''))}">
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<xsl:template match="address">
		<span class="address">
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<xsl:template match="addrLine">
		<br/>
		<span class="{concat(name(), ' ', translate(@rend, '-', ''))}">
			<xsl:apply-templates/>
		</span>
	</xsl:template>


	<!-- Start of addSpan/anchor -->

	<xsl:template match="tei:addSpan[preceding-sibling::node()[1][name()='p']]|tei:addSpan[preceding-sibling::node()[2][name()='p']]|p/addSpan">
		<br/>
		<xsl:apply-templates/>
	</xsl:template>

	<xsl:template match="tei:addSpan|p/anchor">
		<xsl:apply-templates/>
	</xsl:template>

	<xsl:template match="tei:anchor">		
		<xsl:apply-templates/>
		<br/>
	</xsl:template>

	<!-- End of addSpan/anchor -->


	<!-- app: show first rdg -->
	<xsl:template match="app">
		<!-- Hidden for annotated version. Also choice, supplied & unclear. -->
		<!--<span class="app">
			<xsl:attribute name="title">
				<xsl:for-each select="rdg">
					<xsl:value-of select="concat(name(),': ', ., '; ')"/>
				</xsl:for-each>
			</xsl:attribute>
			<xsl:apply-templates select="rdg[1]"/>
		</span>-->
		<xsl:apply-templates select="rdg[1]"/>
	</xsl:template>

	<!-- For "back" see above -->

	<!-- For "body" see above -->

	<xsl:template match="cb">
		<br/>
		<xsl:apply-templates/>
	</xsl:template>

	<xsl:template match="div/cb">
		<xsl:apply-templates/>
	</xsl:template>

	<!-- For "choice" see above -->

	<xsl:template match="closer">
		<span class="{concat(name(), ' ', translate(@rend, '-', ''))}">
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<!-- For "corr" see above -->

	<xsl:template match="dateline">
		<span class="{concat(name(), ' ', translate(@rend, '-', ''))}">
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<xsl:template match="del">
		<span class="del cancelled">
			<xsl:if test="@*">
				<xsl:attribute name="title">
					<xsl:value-of select="concat(name(), 'etion, ')"/>
					<xsl:for-each select="@*">
						<xsl:sort/>
						<xsl:if test="not(name()='status')">
							<xsl:value-of select="concat(name(),': ', ., '; ')"/>
						</xsl:if>
					</xsl:for-each>
				</xsl:attribute>
			</xsl:if>
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<xsl:template match="del[following-sibling::add[@place='over-text']]" priority="10">
		<span class="del-by-over-text" title="Text deleted by over-writing"><xsl:apply-templates/></span>
	</xsl:template>

	<!-- For "div" see above -->

	<!-- For "expan" see above -->

	<!-- For "facsimile" see above -->

	<!-- For "front" see above -->

	<!--<xsl:template match="figure">
		<xsl:choose>
		<xsl:when test="head">
			<span class="figure" title="{concat('&quot;', head, '.&quot; ', figDesc)}">{figure}</span>
		</xsl:when>
		<xsl:otherwise>
			<span class="figure" title="{figDesc}">{figure}</span>
		</xsl:otherwise>
		</xsl:choose>
	</xsl:template>--><!-- Replaced with templated provided by James Cummings -->

	<xsl:template match="figure">
		<!-- newFigDesc goes away and applies templates to content to get it into a single dedupped string -->
		<xsl:variable name="newFigDesc">
			<xsl:apply-templates select="figDesc" mode="normalizeFigDesc"/>
		</xsl:variable>
		<xsl:choose>
			<xsl:when test="head and $newFigDesc/text()">
				<span class="figure" title="{concat('&quot;', head, '.&quot; ', $newFigDesc)}">{figure}</span>
			</xsl:when>
			<xsl:when test="head and not($newFigDesc/text())">
				<span class="figure" title="{concat('&quot;', head, '.&quot; ')}">{figure}</span>
			</xsl:when>
			<xsl:when test="not(head) and $newFigDesc/text()">
				<span class="figure" title="{$newFigDesc}">{figure}</span>
			</xsl:when>
			<xsl:otherwise>
				<span class="figure">{figure}</span>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<!-- Template passes through abbr, sic, and orig in figDesc in normalizeFigDesc mode -->
	<xsl:template match="figDesc//abbr|figDesc//sic|figDesc//orig" mode="normalizeFigDesc">
		<xsl:apply-templates/>
	</xsl:template>

	<!-- Template kills through expan, corr, reg, and supplied in figDesc in normalizeFigDesc mode -->
	<xsl:template match="figDesc//expan|figDesc//corr|figDesc//reg|figDesc//supplied"
		mode="normalizeFigDesc"/>

	<xsl:template match="add[@place='marginleft']/figure|add[@place='marginright']/figure" priority="10">
		<xsl:choose>
		<xsl:when test="head">
			<span class="figure" title="{concat('&quot;', head, '.&quot; ', figDesc)}">figure</span>
		</xsl:when>
		<xsl:otherwise>
			<span class="figure" title="{figDesc}">figure</span>
		</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<!-- An undefined foreign word. -->
	<xsl:template match="foreign[not(term[@xml:lang])]">
		<!--<xsl:variable name="title">A foreign word (not defined).</xsl:variable>
		<span class="foreign" title="{$title}">-->
			<xsl:apply-templates/>
		<!--</span>-->
	</xsl:template>

	<xsl:template match="fw[@type='catch']|fw[@type='pageno']">
		<span class="{concat(name(), ' ', @type, ' ', @rend)}" title="">
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<xsl:template match="gap[@extent][@unit]" priority="10">
		<xsl:choose>
			<xsl:when test="@unit='chars'"><span class="gap" title="{concat(name(), ', extent: ',@extent, ' ', @unit, ', cause: ', @agent)}">[<xsl:for-each select="1 to @extent">&#x00A0;</xsl:for-each>]</span></xsl:when>
			<xsl:when test="@unit='words'"><span class="gap" title="{concat(name(), ', extent: ',@extent, ' ', @unit, ', cause: ', @agent)}">[<xsl:for-each select="1 to @extent">&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;</xsl:for-each>]</span></xsl:when>
			<xsl:otherwise><span class="gap" title="{concat(name(), ', extent: ',@extent, ' ', @unit, ', cause: ', @agent)}">[<xsl:for-each select="1 to @extent">&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;</xsl:for-each>]</span></xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<!-- remove gb spans -->
	<xsl:template match="gb">
		<xsl:apply-templates/>
	</xsl:template>

	<!-- do not show graphic -->
	<xsl:template match="graphic"/>

	<xsl:template match="head">
		<xsl:variable name="num" select="count(ancestor::*)"/>
		<xsl:element name="{concat('h', $num)}">
			<xsl:apply-templates select="@*|node()"/>
		</xsl:element>
	</xsl:template>

	<xsl:template match="idno[@type='LEAP-ID']">
		<span class="idno"><xsl:apply-templates/></span>
	</xsl:template>

	<xsl:template match="list/item">
		<span class="listitem" title="item">
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<!-- For "lb" see above -->

	<xsl:template match="list">
		<span class="list" title="list">
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<xsl:template match="metamark"><span class="metamark italic" title="Editorial symbol, mark, or unusual character"
		>#</span></xsl:template>

	<xsl:template match="add[@place='marginleft']/metamark|add[@place='marginright']/metamark" priority="10">
		<span class="metamark italic" title="Editorial symbol, mark, or unusual character">#</span>
	</xsl:template>


	<xsl:template match="milestone">
		<hr class="{concat(name(), ' ', translate(@rend, '-', ''))}">
			<xsl:if test="@*">
				<xsl:attribute name="title">
					<xsl:value-of select="concat(name(), ': ')"/>
					<xsl:for-each select="@*">
						<xsl:sort/>
						<xsl:value-of select="concat(name(),': ', ., '; ')"/>
					</xsl:for-each>
				</xsl:attribute>
			</xsl:if>
		</hr>
	</xsl:template>

	<xsl:template match="note">
		<span class="{concat(name(), ' ', @type, ' ', @rend, ' ', @anchored)}">[<xsl:apply-templates/>]</span>
	</xsl:template>

	<xsl:template match="note[ancestor::add[@place='marginleft']]" priority="10">
		<span class="{concat(name(), ' ', @type, ' ', @rend)}">
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<xsl:template match="p/note" priority="8">
		<span class="{concat(name(), ' ', @type, ' ', @rend)}">[<xsl:apply-templates/>]</span>
	</xsl:template>

	<xsl:template match="opener">
		<span class="{concat(name(), ' ', translate(@rend, '-', ''))}">
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<!-- For "orig" see above -->

	<!-- Not sure what this does. AW -->
	<xsl:template match="jc:page">
		<div class="page">
			<span class="pb-title">
				<xsl:value-of select="@n"/>
			</span>
			<xsl:apply-templates/>
		</div>
	</xsl:template>

	<xsl:template match="pb">
		<span class="pb-title">
			<xsl:value-of select="@n"/>
		</span>
	</xsl:template>

	<xsl:template match="del/pb" priority="10">
		<span class="pb-title del-pb">
			<xsl:value-of select="@n"/>
		</span>
	</xsl:template>

	<!-- @placeName plus others. To eliminate two spans and addition of whitespace in HTML -->
	<xsl:template match="placeName/geogName|placeName/bloc|placeName/country|placeName/region|placeName/settlement">
		<xsl:apply-templates/>
	</xsl:template>

	<xsl:template match="postscript">
		<xsl:apply-templates/>
	</xsl:template>

	<!-- For "reg" see above -->

	<xsl:template match="rdg">
		<xsl:apply-templates/>
	</xsl:template>

	<xsl:template match="opener/salute">
		<span class="opener-salute">
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<xsl:template match="closer/salute">
		<span class="closer-salute">
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<!-- For "sic" see above -->

	<xsl:template match="signed">
		<span class="signed">
			<xsl:apply-templates/>
		</span>
	</xsl:template>

	<xsl:template match="space[@extent][@unit]" priority="10">
		<xsl:choose>
			<xsl:when test="@unit='chars'">
				<span class="space" title="{concat(name(), ': ',@extent, ' ', @unit, ' ', @agent)}">
					<xsl:for-each select="1 to @extent">&#x00A0;&#x00A0;</xsl:for-each>
				</span>
			</xsl:when>
			<xsl:when test="@unit='words'">
				<span class="space" title="{concat(name(), ': ',@extent, ' ', @unit, ' ', @agent)}">
					<xsl:for-each select="1 to @extent"
						>&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;</xsl:for-each>
				</span>
			</xsl:when>
			<xsl:when test="@dim='vertical'">
				<span class="verticalSpace" title="{concat('vertical space: ',@extent, ' ', @unit)}">
					[&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;&#x00A0;]
					<br class="verticalSpace"/></span>
			</xsl:when>
			<xsl:otherwise>
				<span class="space-other" title="{concat(name(), ': ', @extent, ' ', @unit, ' ', @agent)}">
					[<xsl:for-each select="1 to @extent">&#x00A0;&#x00A0;</xsl:for-each>]</span>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<xsl:template match="subst">
		<xsl:apply-templates/>
	</xsl:template>

	<!-- Text below removed for annotated edition; also see app, choice & unlcear -->
	<!--<xsl:template match="supplied">
		<span class="supplied edited hidden"> <xsl:if test="@*"> <xsl:attribute name="title">
			<xsl:value-of select="concat(name(), ', certainty: ', @cert, ', reason: ', @reason)"/>
			</xsl:attribute> </xsl:if>[<xsl:apply-templates select="node()"/>]</span>
	</xsl:template>-->

	<!-- For "surface" see above -->

	<!-- Beginning of elements that go with table -->
	<xsl:template match="table">
		<table>
			<xsl:apply-templates/>
			<!-- select="@*|node()" -->
		</table>
	</xsl:template>

	<xsl:template match="row">
		<tr>
			<xsl:apply-templates/>
			<!-- select="@*|node()" -->
		</tr>
	</xsl:template>

	<xsl:template match="cell">
		<td> &#x00A0;<xsl:apply-templates/>&#x00A0;<!-- select="@*|node()" --> </td>
	</xsl:template>
	<!-- End of elements that go with table -->

	<!-- For "TEI" see above -->

	<!-- For "teiHeader" see above -->

	<xsl:template match="term[@type]" priority="1">
		<!--<span class="term" title="{@type}">-->
		<xsl:apply-templates/>
		<!--</span>-->
	</xsl:template>

	<!-- For "text" see above -->

	<xsl:template match="unclear">
		<span class="unclear">
			<xsl:if test="@cert">
				<xsl:attribute name="title">
					<xsl:value-of select="concat(name(), ', certainty of reading: ', @cert)"/>
				</xsl:attribute>
			</xsl:if>
			<xsl:apply-templates select="node()"/>
		</span>
	</xsl:template>

	<xsl:template match="w">
		<xsl:apply-templates/>
	</xsl:template>

	<!-- For "zone" see above -->


	<!-- Code not in use, but that could be useful -->

	<!--  <xsl:template match="*[not(@type)][not(@reason)][not(@unit)][not(@extent)]" priority="-1">
		<span class="{name()}"><xsl:apply-templates select="@*|node()"/></span>
		</xsl:template> -->

	<!--<xsl:template match="choice/orig">
		<span class="orig diplomatic">
			<xsl:if test="../reg">
				<xsl:attribute name="title">reg: <xsl:value-of select="../reg"/></xsl:attribute>
			</xsl:if>
			<xsl:apply-templates/>
		</span>
	</xsl:template>-->

	<!--<xsl:template match="choice/reg" priority="10">
		<span class="reg edited hidden">
			<xsl:if test="../orig">
				<xsl:attribute name="title">orig: <xsl:value-of select="../orig"/></xsl:attribute>
			</xsl:if>
			<xsl:apply-templates select="../orig/node()"/>
		</span>
	</xsl:template>-->

	<!--<xsl:template match="figure/head">
		<span class="figHead">
			<xsl:apply-templates/>
		</span>
	</xsl:template>-->

	<!--<xsl:template match="figure/figDesc">
		<xsl:variable name="title"><xsl:apply-templates/></xsl:variable>
		<span class="figfigDesc" title="{$title}">{figure}</span>
	</xsl:template>-->


	<!-- foreign should be italiced in edited view -->
	<!-- <xsl:template match="foreign" xml:space="preserve">
		<span class="foreign diplomatic">
		<xsl:if test="@xml:lang">
			<xsl:attribute name="title">
				<xsl:value-of select="concat('lang: ', @xml:lang)"/>
			</xsl:attribute>
		</xsl:if>
				<xsl:apply-templates/>
		</span>
		<span class="foreign foreignItalic edited hidden" style="font-style:italic;">
		<xsl:if test="@xml:lang">
			<xsl:attribute name="title">
				<xsl:value-of select="concat('lang: ', @xml:lang)"/>
			</xsl:attribute>
		</xsl:if>
			<xsl:apply-templates/></span>
		</xsl:template>-->

	<!--<xsl:template match="fw[@type='pageno']">
		<span class="fw pageno" title="">
			<xsl:apply-templates/>
		</span>
		<br/>
	</xsl:template>-->

	<!--<xsl:template match="lb">
		<br/>
		<xsl:variable name="num">
			<xsl:number level="any" from="pb"/>
		</xsl:variable>
		<xsl:if test="number($num) mod 5 =0">
			<span class="linenumber">
				<xsl:value-of select="$num"/>
			</span>
		</xsl:if>
	</xsl:template>-->
	<!--[not(ancestor::note)]-->

	<!--<xsl:template match="space[@extent][@unit][@dim='vertical']" priority="1">
		<span class="space-other vertical verticalSpace">
			<xsl:attribute name="title">
				<xsl:for-each select="@*">
					<xsl:sort/>
					<xsl:value-of select="concat(name(),': ', ., '; ')"/>
				</xsl:for-each>
			</xsl:attribute>
			<xsl:for-each select="1 to @extent">
				<br class="verticalSpace"/>
			</xsl:for-each>
		</span>
	</xsl:template>-->

	<!--<xsl:template match="term[@type]" priority="1">
		<span class="term" title="{@type}">
		<xsl:apply-templates/>
		</span>
	</xsl:template>-->

	<!-- Tooltip text: ailment, ethnic-group, foreign-word, geogName, orgName, persName/people, region, quote, settlement-->

</xsl:stylesheet>
