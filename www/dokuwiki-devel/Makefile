PORTNAME=	dokuwiki
PORTVERSION=	20220127
CATEGORIES=	www
PKGNAMESUFFIX=	-devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	4b867325b0bce2a430cace11805d1b09c43f1ee1.patch:-p1 # https://github.com/splitbrain/dokuwiki/pull/3620
PATCHFILES+=	1498ac42d54ece2fdac23a00662a18ec8019fcf1.patch:-p1 # https://github.com/splitbrain/dokuwiki/pull/3620

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Simple and easy to use wiki, no database required

LICENSE=		BSD3CLAUSE GPLv2 GPLv2+ GPLv3 MIT
LICENSE_COMB=		multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/vendor/simplepie/simplepie/LICENSE.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv2+ =	${WRKSRC}/vendor/geshi/geshi/LICENSE
LICENSE_FILE_GPLv3=	${WRKSRC}/vendor/marcusschwarz/lesserphp/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/vendor/composer/LICENSE

CONFLICTS_INSTALL=	dokuwiki

USE_GITHUB=	yes
GH_ACCOUNT=	splitbrain
GH_TAGNAME=	4ef5d38db53e045a81f129b29a8b886cecc38497
USES=		cpe php:web shebangfix
USE_PHP=	gd hash json mbstring openssl pcre session xml xmlrpc zlib
NO_ARCH=	YES
NO_BUILD=	YES

SHEBANG_FILES=	bin/*.php
SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME}
SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}
CONF_FILES=	acl.auth.php local.php local.php.bak plugins.local.php \
		plugins.local.php.bak users.auth.php

OPTIONS_GROUP=	PLUGINS 3RDPARTY THEMES
OPTIONS_GROUP_PLUGINS=	AUTHAD AUTHLDAP AUTHPDO POPULARITY
OPTIONS_GROUP_3RDPARTY=	BBCODE BLOG CATLIST CLEANUP CLOUD CHEM \
			CUSTOMBUTTONS EDITTABLE HTMLDETAILSTAG INCLUDE \
			MOVE NOTE PAGEBUTTONS PAGELIST \
			SEARCHINDEX SECTIONTOGGLE TAG TRANSLATION \
			UPGRADE
OPTIONS_GROUP_THEMES=	MINDTHEDARK
OPTIONS_DEFAULT=	CLEANUP CUSTOMBUTTONS EDITTABLE HTMLDETAILSTAG \
			MOVE NOTE PAGEBUTTONS PAGELIST SEARCHINDEX TAG
OPTIONS_SUB=		yes

3RDPARTY_DESC=		3rd party plugins

AUTHAD_DESC=		Active Directory Auth Plugin

AUTHLDAP_DESC=		Provides user authentication against an LDAP server

AUTHPDO_DESC=		Authenticate against a database via PDO

POPULARITY_DESC=	Send anonymous data about your wiki to the DokuWiki developers

BBCODE_DESC=		Makes the use of BBcode syntax possible
BBCODE_GH_TUPLE=	dokufreaks:plugin-bbcode:5b1b2404797cf7ed8678d83d283e24dfc336225f:plugin_bbcode

BLOG_DESC=		Use DokuWiki as blogging tool
BLOG_GH_TUPLE=		dokufreaks:plugin-blog:4d16b4a9d848a3023cae5a9c71ba968a22eea2cf:plugin_blog
BLOG_IMPLIES=		INCLUDE PAGELIST

CATLIST_DESC=		Adds a form to create a new page in the current namespace
CATLIST_GH_TUPLE=	xif-fr:dokuwiki-plugin-catlist:065f8d2f4817409989b9342b901163452fb9f547:plugin_catlist

CLEANUP_DESC=		Perform file cleanup in the wiki
CLEANUP_GH_TUPLE=	cosmocode:dokuwiki-plugin-cleanup:dc8184bc282ab1ef78586026d5dced37c5705eb6:plugin_cleanup

CLOUD_DESC=		Shows a word cloud from different sources
CLOUD_GH_TUPLE=		dokufreaks:plugin-cloud:c24efb5af1a911a9496d06681af077d43411f31a:plugin_cloud

CHEM_DESC=		Format a molecular formula
CHEM_GH_TUPLE=		iobataya:dokuwiki-plugin-chem:b2cf09601134160385822a989fb450f41a3996e0:plugin_chem

CUSTOMBUTTONS_DESC=	Adding custom buttons to the toolbar
CUSTOMBUTTONS_GH_TUPLE=	ConX:dokuwiki-plugin-custombuttons:fe62df3de7f643225d6767b481f478e901f35a40:plugin_custombuttons
CUSTOMBUTTONS_CONFIGS=	config.json

EDITTABLE_DESC=		Provides a visual table editing and inserting interface
EDITTABLE_GH_TUPLE=	cosmocode:edittable:3e7b1bdcbf8a188f6f2f3b97232f3ccbed899645:plugin_edittable

HTMLDETAILSTAG_DESC=	Use the HTML <details> and <summary> tag for toggling information
HTMLDETAILSTAG_GH_TUPLE= revolution-arts:dokuwiki-plugin-htmldetailstag:6be4a2af74e95bdde95eb3a07b0a51492f7b5165:plugin_htmldetailstag

INCLUDE_DESC=		Include another wiki page into the current one
INCLUDE_GH_TUPLE=	dokufreaks:plugin-include:213595c25b149ceabbdae9f25b977d25c598f68a:plugin_include
INCLUDE_IMPLIES=	TAG

MINDTHEDARK_DESC=	light and a dark color scheme
MINDTHEDARK_GH_TUPLE=	MrReSc:MindTheDark:96718ab71e30f22092ee4067a80d01b8dce3f189:theme_mindthedark

MOVE_DESC=		Extended edit functions such as renaming or deleting a page
MOVE_GH_TUPLE=		michitux:dokuwiki-plugin-move:f2416147498d9b33e36445820b54e015f1968776:plugin_move

NOTE_DESC=		Allows to create nice notes
NOTE_GH_TUPLE=		lpaulsen93:dokuwiki_note:86cd79fb7c4be03be652e4e9f58f87b4ab965fec:plugin_note

PAGEBUTTONS_DESC=	Provides buttons to create/delete the current page
PAGEBUTTONS_GH_TUPLE=	SoarinFerret:dokuwiki-plugin-pagebuttons:74aec0bbc023ba219866429f8bee3e6f66c7787d:plugin_pagebuttons

PAGELIST_DESC=		Lists pages in a nice looking table or unordered list
PAGELIST_GH_TUPLE=	dokufreaks:plugin-pagelist:f07f56614330356190d44d26dd55e22718683433:plugin_pagelist

SEARCHINDEX_DESC=	Rebuild the search index
SEARCHINDEX_GH_TUPLE=	splitbrain:dokuwiki-plugin-searchindex:32e56a59996ea3a10b3a70f0239fc13d58f1174b:plugin_searchindex

SECTIONTOGGLE_DESC=	Toggle sections open and closed by clicking on section headers
SECTIONTOGGLE_GH_TUPLE=	turnermm:sectiontoggle:8c0bd851d2e800962fb914394aed0b74b8b0d3fd:plugin_sectiontoggle

TAG_DESC=		Assign category tags to wiki pages
TAG_GH_TUPLE=		dokufreaks:plugin-tag:43e7b584f35e6242758fdf42b45e96571abb1ef1:plugin_tag
TAG_IMPLIES=		PAGELIST

THEMES_DESC=		Additional themes for DoKuWiKi

TRANSLATION_DESC=	Help with translation efforts in a multilingual wiki
TRANSLATION_GH_TUPLE=	splitbrain:dokuwiki-plugin-translation:c3bb052a4dbd63809835e68809b904fafb5e613e:plugin_translation

UPGRADE_DESC=		Update with a few clicks from the admin interface
UPGRADE_GH_TUPLE=	splitbrain:dokuwiki-plugin-upgrade:dd8327d13a27f455530fc12f7b0cfaeca0b415b3:plugin_upgrade

.include <bsd.port.pre.mk>

post-extract:
	# Remove disabled.
.for __OPT in ${OPTIONS_GROUP_PLUGINS}
.  if !${PORT_OPTIONS:M${__OPT}}
	@${RM} -rf ${WRKSRC}/lib/plugins/${__OPT:tl}/
.  endif
.endfor
	# Install selected plugins.
.for __OPT in ${OPTIONS_GROUP_3RDPARTY}
.  if ${PORT_OPTIONS:M${__OPT}}
	@${MKDIR} ${WRKSRC}/lib/plugins/${__OPT:tl}/
	@${MV} ${WRKSRC_plugin_${__OPT:tl}}/${${__OPT}_WRKSRC_SUBDIR}/* ${WRKSRC}/lib/plugins/${__OPT:tl}/
.    for __CONF in ${${__OPT}_CONFIGS}
	@${TOUCH} "${WRKSRC}/lib/plugins/${__OPT:tl}/${__CONF}.sample"
.    endfor
.  endif
.endfor
	# Install selected themes.
.for __OPT in ${OPTIONS_GROUP_THEMES}
.  if ${PORT_OPTIONS:M${__OPT}}
	@${MKDIR} ${WRKSRC}/lib/tpl/${__OPT:tl}/
	@${MV} ${WRKSRC_theme_${__OPT:tl}}/${${__OPT}_WRKSRC_SUBDIR}/* ${WRKSRC}/lib/tpl/${__OPT:tl}/
.  endif
.endfor

do-install:
	# Prepare.
	@${FIND} ${WRKSRC} -type f \( \
		-name '*.orig' \
		-o -name '*.bak' \
		-o -name 'deleted.files' \
		-o -name '.gitignore' \) -delete
.for __FILE in ${CONF_FILES}
	# Create config files to set perm on install.
	@${TOUCH} "${WRKSRC}/conf/${__FILE}"
	# Rename config files to .sample.
	@${MV} "${WRKSRC}/conf/${__FILE}" "${WRKSRC}/conf/${__FILE}.sample"
.endfor
	# Install base files.
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

post-stage:
	# Generate plist.
	@${SETENV} ${CO_ENV} ${SH} ${SCRIPTSDIR}/check-stagedir.sh makeplist | \
		${GREP} -v ^\/ | \
		${SED} -e 's|%%WWWDIR%%|www/${PORTNAME}|' \
			-e 's|%%PORTEXAMPLES%%||' \
			-e 's|%%EXAMPLESDIR%%|share/examples/${PORTNAME}|' \
			> ${TMPPLIST}
	# Mark config files as samples in plist.
	@${REINPLACE_CMD} -E "s|(.*\.sample)$$|@sample \1|" ${TMPPLIST}
	# Force perms.
	@${ECHO_CMD} "@postexec chown -R root:${WWWGRP} ${WWWDIR}" >> ${TMPPLIST}
	@${ECHO_CMD} "@postexec chmod -R =t,u=rwX,g=rX,o= ${WWWDIR}" >> ${TMPPLIST}
	@${ECHO_CMD} "@postexec chmod -R -t,u=rwX,g=rwX,o= ${WWWDIR}/data" >> ${TMPPLIST}
	@${ECHO_CMD} "@postexec chmod -t,u=rwX,g=rwX,o= ${WWWDIR}/conf" >> ${TMPPLIST}
.for __FILE in ${CONF_FILES}
	@${ECHO_CMD} "@postexec chmod 0660 ${WWWDIR}/conf/${__FILE}" >> ${TMPPLIST}
.endfor
.for __OPT in ${OPTIONS_GROUP_3RDPARTY}
.  if ${PORT_OPTIONS:M${__OPT}}
.    for __CONF in ${${__OPT}_CONFIGS}
	@${ECHO_CMD} "@postexec chmod 0660 ${WWWDIR}/lib/plugins/${__OPT:tl}/${__CONF}" >> ${TMPPLIST}
.    endfor
.  endif
.endfor

.include <bsd.port.mk>
