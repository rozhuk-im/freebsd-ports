PORTNAME=	ng_ipacct
PORTVERSION=	20210316
PORTREVISION=	2
CATEGORIES=	net-mgmt

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Netgraph IP accounting
WWW=		https://github.com/vstakhov/ng_ipacct/

LICENSE=	BSD2CLAUSE

BROKEN_armv6=		fails to build: ng_ipacct_hash.h:52:2: implicit declaration of function 'MALLOC' is invalid in C99
BROKEN_armv7=		fails to build: ng_ipacct_hash.h:52:2: implicit declaration of function 'MALLOC' is invalid in C99
BROKEN_riscv64=		fails to build: ng_ipacct.c:972:2: error: implicit declaration of function 'INP_HASH_RLOCK' is invalid in C99

USE_GITHUB=	yes
USES=		kmod uidfix

GH_ACCOUNT=	vstakhov

MAKE_ARGS+=	OSVERSION=${OSVERSION} MANDIR=${PREFIX}/share/man/ru.KOI8-R/man
MAKE_ENV+=	BINDIR="${PREFIX}/sbin"

USE_RC_SUBR=	ng_ipacct
SUB_FILES=	pkg-message
CFLAGS+=	-DMEM_USE_ZONE -DVIMAGE

post-patch:
	@${REINPLACE_CMD} 's,{MANDIR},{DESTDIR}$$&,' ${WRKSRC}/man_ru/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/netgraph
	${INSTALL_DATA} ${WRKSRC}/ng_ipacct/ng_ipacct.h ${STAGEDIR}${PREFIX}/include/netgraph
	${INSTALL_DATA} ${FILESDIR}/ng_ipacct.conf \
		${STAGEDIR}${PREFIX}/etc/ng_ipacct.conf.sample

.include <bsd.port.mk>
