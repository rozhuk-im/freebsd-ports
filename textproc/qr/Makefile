PORTNAME=	qr
DISTVERSION=	g20200216
PORTREVISION=	2
CATEGORIES=	textproc graphics

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Generate textual QR codes using terminal
WWW=		https://github.com/Y2Z/qr

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libqrencode.so:graphics/libqrencode
TEST_DEPENDS=	${LOCALBASE}/share/fonts/freefont-ttf/FreeMono.ttf:x11-fonts/freefont-ttf \
		autom4te:devel/autoconf \
		zbarimg:graphics/zbar

USES=		gmake magick:6,test
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	Y2Z
GH_TAGNAME=	20713de

MAKE_ARGS=	LIBS="-I${LOCALBASE}/include -L${LOCALBASE}/lib -lqrencode -lm"
TEST_TARGET=	test

PLIST_FILES=	bin/${PORTNAME}

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
