PORTNAME=	hashdb
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0-8
PORTREVISION=	2
DISTVERSIONSUFFIX=	-g1da1b9f
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Block hash database tool and API
WWW=		https://github.com/NPS-DEEP/hashdb

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig:devel/swig \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
LIB_DEPENDS=	libewf.so:devel/libewf

USES=		autoreconf compiler:c++11-lang gmake libtool localbase:ldflags \
		python ssl
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_GITHUB=	yes
GH_ACCOUNT=	NPS-DEEP
CONFIGURE_ARGS=	ac_cv_lib_ssl_SSL_library_init=yes \
		--disable-static --enable-shared # enable-shared fails: https://github.com/NPS-DEEP/hashdb/issues/9

INSTALL_TARGET=	install-strip

CONFIGURE_ENV=	PYTHON=${PYTHON_CMD}

CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC

PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}

post-configure:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} 's| -lstdc++ | |'

.include <bsd.port.mk>
