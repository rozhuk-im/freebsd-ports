PORTNAME=	converse.js
PORTVERSION=	12.0.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/conversejs/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Web-based XMPP/Jabber chat written in JavaScript
WWW=		https://conversejs.org/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:tgz
WRKSRC=		${WRKDIR}/package
NO_BUILD=	yes
NO_ARCH=	yes
PORTEXAMPLES=	index.html.sample
SUB_FILES=	pkg-message

do-install:
	# Prepare.
	@${FIND} ${WRKSRC} -type f \( \
		-name '*.orig' \
		-o -name '*.bak' \
		-o -name '.gitignore' \) -delete
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	# Install base files.
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${INSTALL_DATA} ${FILESDIR}/${PORTEXAMPLES} ${STAGEDIR}${WWWDIR}/

post-stage:
	# Generate plist.
	@${SETENV} ${CO_ENV} ${SH} ${SCRIPTSDIR}/check-stagedir.sh makeplist | \
		${GREP} -v ^\/ | \
		${SED} -e 's|%%WWWDIR%%|www/${PORTNAME}|' \
			-e 's|%%PORTEXAMPLES%%||' \
			> ${TMPPLIST}
	# Mark config files as samples in plist.
	@${REINPLACE_CMD} -E "s|(.*\.sample)$$|@sample \1|" ${TMPPLIST}
	# Fix perms.
	@${ECHO_CMD} "@postexec ${CHOWN} -R root:wheel ${WWWDIR}" >> ${TMPPLIST}
	@${ECHO_CMD} "@postexec ${CHMOD} -R u=rwX,g=rX,o=rX ${WWWDIR}" >> ${TMPPLIST}

.include <bsd.port.mk>
