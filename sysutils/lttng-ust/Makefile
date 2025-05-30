PORTNAME=	lttng-ust
DISTVERSION=	2.13.9
CATEGORIES=	sysutils
MASTER_SITES=	http://lttng.org/files/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libraries to instrument and trace user applications
WWW=		https://github.com/lttng/lttng-ust

LICENSE=		GPLv2 LGPL21 MIT
LICENSE_COMB=		dual
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		xmlto:textproc/xmlto
LIB_DEPENDS=	liburcu.so:sysutils/liburcu

USES=		autoreconf gmake libtool localbase pathfix pkgconfig python \
		shebangfix tar:bzip2
USE_LDCONFIG=	yes

SHEBANG_FILES=	tools/lttng-gen-tp

GNU_CONFIGURE=	yes
# XXX: build fails if cmake is detected, see PR 253327
CONFIGURE_ENV=	ac_cv_prog_HAVE_CMAKE=no

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

post-patch:
	@${GREP} -Rl --null '#!/bin/bash' ${WRKSRC}/tests | ${XARGS} -0 \
		${REINPLACE_CMD} -e '/#!/s,bash,sh,'

.include <bsd.port.mk>
