PORTNAME=	xzgv
DISTVERSION=	0.9.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	m.ne@gmx.net
COMMENT=	Image viewer with thumbnail-based file selector for X
WWW=		https://sourceforge.net/projects/xzgv/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gawk:lang/gawk
LIB_DEPENDS=	libexif.so:graphics/libexif \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		cpe gmake gnome pkgconfig xorg
USE_GNOME=	cairo gdkpixbufextra:run gtk20
USE_XORG=	x11

LDFLAGS+=	-L${LOCALBASE}/lib -lX11 -lm
PLIST_FILES=	bin/xzgv share/man/man1/xzgv.1.gz

post-patch:
	${REINPLACE_CMD} -e 's|^CC|#CC|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s|^PREFIX|#PREFIX|g' ${WRKSRC}/config.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xzgv ${STAGEDIR}${LOCALBASE}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/xzgv.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
