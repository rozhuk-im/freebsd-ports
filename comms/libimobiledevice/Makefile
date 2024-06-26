PORTNAME=	libimobiledevice
PORTVERSION=	1.3.0
PORTREVISION?=	1
CATEGORIES?=	comms
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER?=	jhale@FreeBSD.org
COMMENT?=	Library to communicate with Apple iOS devices
WWW=		https://www.libimobiledevice.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

SLAVE_PORT?=	no

USES+=		cpe libtool localbase:ldflags pathfix pkgconfig ssl tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS+=openssl_CFLAGS="-I${OPENSSLINC}" \
		openssl_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
INSTALL_TARGET=	install-strip

.if ${SLAVE_PORT} == no

LIB_DEPENDS=	libplist-2.0.so:devel/libplist \
		libusbmuxd-2.0.so:comms/libusbmuxd

USES+=		gnome
USE_GNOME=	glib20
CONFIGURE_ARGS+=--without-cython
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS NEWS README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's, *@ssl_requires@,,' \
		${WRKSRC}/src/${PORTNAME}*.pc.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.endif # ${SLAVE_PORT} == no

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
