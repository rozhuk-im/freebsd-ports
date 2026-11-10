PORTNAME=	dokuwiki
PORTVERSION=	20261110
CATEGORIES=	www
PKGNAMESUFFIX=	-devel

#PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
#PATCHFILES+=	4b867325b0bce2a430cace11805d1b09c43f1ee1.patch:-p1 # https://github.com/splitbrain/dokuwiki/pull/3620

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Simple and easy to use wiki, no database required
WWW=		https://www.dokuwiki.org/

LICENSE=		BSD3CLAUSE GPLv2 GPLv2+ GPLv3 MIT
LICENSE_COMB=		multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/vendor/simplepie/simplepie/LICENSES/BSD-3-Clause.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv2+ =	${WRKSRC}/vendor/geshi/geshi/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/vendor/composer/LICENSE

CONFLICTS_INSTALL=	dokuwiki

USE_GITHUB=	yes
GH_ACCOUNT=	splitbrain
GH_TAGNAME=	b17325710c666925e619382c4c43e41d9807cf06
USES=		cpe php:web,flavors shebangfix tar:tgz
USE_PHP=	ctype filter gd hash json iconv mbstring openssl pcre \
		session simplexml xml xmlrpc zlib
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
BBCODE_GH_TUPLE=	dokufreaks:plugin-bbcode:f5a86833b470470edf36b0af12c7450b322418c0:plugin_bbcode

BLOG_DESC=		Use DokuWiki as blogging tool
BLOG_GH_TUPLE=		dokufreaks:plugin-blog:c4b00e79a13fc5a88a3b9bb4d4669bb18427c802:plugin_blog
BLOG_IMPLIES=		INCLUDE PAGELIST

CATLIST_DESC=		Adds a form to create a new page in the current namespace
CATLIST_GH_TUPLE=	xif-fr:dokuwiki-plugin-catlist:edf7bc2be51a5b85b2ef5ed7cbd766736251cc8e:plugin_catlist

CLEANUP_DESC=		Perform file cleanup in the wiki
CLEANUP_GH_TUPLE=	cosmocode:dokuwiki-plugin-cleanup:86b105108a11b855b3fbfdddbd03f4d74290e48e:plugin_cleanup

CLOUD_DESC=		Shows a word cloud from different sources
CLOUD_GH_TUPLE=		dokufreaks:plugin-cloud:6829ca053b247c9ec3fe45ee3b99bcbbaa2f8d3f:plugin_cloud

CHEM_DESC=		Format a molecular formula
CHEM_GH_TUPLE=		iobataya:dokuwiki-plugin-chem:b2cf09601134160385822a989fb450f41a3996e0:plugin_chem

CUSTOMBUTTONS_DESC=	Adding custom buttons to the toolbar
CUSTOMBUTTONS_GH_TUPLE=	ConX:dokuwiki-plugin-custombuttons:fe62df3de7f643225d6767b481f478e901f35a40:plugin_custombuttons
CUSTOMBUTTONS_CONFIGS=	config.json

EDITTABLE_DESC=		Provides a visual table editing and inserting interface
EDITTABLE_GH_TUPLE=	cosmocode:edittable:a380ed2019114773538ab7e47b5e3d5be74b3745:plugin_edittable

HTMLDETAILSTAG_DESC=	Use the HTML <details> and <summary> tag for toggling information
HTMLDETAILSTAG_GH_TUPLE= revolution-arts:dokuwiki-plugin-htmldetailstag:6be4a2af74e95bdde95eb3a07b0a51492f7b5165:plugin_htmldetailstag

INCLUDE_DESC=		Include another wiki page into the current one
INCLUDE_GH_TUPLE=	dokufreaks:plugin-include:6e31ef49dbf8ba836ad951ca916b2d316029e504:plugin_include
INCLUDE_IMPLIES=	TAG

MINDTHEDARK_DESC=	light and a dark color scheme
MINDTHEDARK_GH_TUPLE=	MrReSc:MindTheDark:f95843c041a33fdbb525ce49cb4f6429ac6fc35d:theme_mindthedark

MOVE_DESC=		Move and rename pages and namespaces whilst maintaining the links
MOVE_GH_TUPLE=		michitux:dokuwiki-plugin-move:5316a909509f2fe5e8b1df181bcf88781a787dfe:plugin_move

NOTE_DESC=		Allows to create nice notes
NOTE_GH_TUPLE=		lpaulsen93:dokuwiki_note:86cd79fb7c4be03be652e4e9f58f87b4ab965fec:plugin_note

PAGEBUTTONS_DESC=	Provides buttons to create/delete the current page
PAGEBUTTONS_GH_TUPLE=	SoarinFerret:dokuwiki-plugin-pagebuttons:b8e3cec0da303167d48394b5238b8011207f69c1:plugin_pagebuttons

PAGELIST_DESC=		Lists pages in a nice looking table or unordered list
PAGELIST_GH_TUPLE=	dokufreaks:plugin-pagelist:53f63e4842a91d5f1bc5eb1259d0cffc33fe110a:plugin_pagelist

SEARCHINDEX_DESC=	Rebuild the search index
SEARCHINDEX_GH_TUPLE=	splitbrain:dokuwiki-plugin-searchindex:4b51babf3034b6ba25a2b1c353a80acf3e7ee1aa:plugin_searchindex

SECTIONTOGGLE_DESC=	Toggle sections open and closed by clicking on section headers
SECTIONTOGGLE_GH_TUPLE=	turnermm:sectiontoggle:1bd9ae74aed5c806d6b5eb8c08a0ea6711e9a428:plugin_sectiontoggle

TAG_DESC=		Assign category tags to wiki pages
TAG_GH_TUPLE=		dokufreaks:plugin-tag:6c862059cc41df6938a24ad9a49fc4812b467b21:plugin_tag
TAG_IMPLIES=		PAGELIST

THEMES_DESC=		Additional themes for DoKuWiKi

TRANSLATION_DESC=	Help with translation efforts in a multilingual wiki
TRANSLATION_GH_TUPLE=	splitbrain:dokuwiki-plugin-translation:1b65306a38f1b5fd939f347eea03e7d07738c17b:plugin_translation

UPGRADE_DESC=		Update with a few clicks from the admin interface
UPGRADE_GH_TUPLE=	splitbrain:dokuwiki-plugin-upgrade:a963e7a2ec1dd272b2b62b5d745f09175b530983:plugin_upgrade

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
