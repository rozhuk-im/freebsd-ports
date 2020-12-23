# Created by: Rozhuk Ivan
# $FreeBSD$

PORTNAME=		minipro
PORTVERSION=		1.0.0
CATEGORIES=		devel

MAINTAINER=		rozhuk.im@gmail.com
COMMENT=		An open source program for controlling the MiniPRO TL866xx series of chip programmers

LICENSE=		GPLv3
LICENSE_FILE=		${WRKSRC}/LICENSE

USE_GITHUB=		yes
GH_ACCOUNT=		rozhuk-im
GH_TAGNAME=		2a6fa3414e2224e7083833bc13771f232be63241

USES=			cmake pkgconfig
USE_LDCONFIG=		yes

OPTIONS_DEFINE=		MANPAGES MPHEX
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MPHEX_DESC=		miniprohex (req. srecord)
MPHEX_RUN_DEPENDS=	srec_cat:devel/srecord

.include <bsd.port.options.mk>

PLIST_FILES=	bin/minipro \
		%%MPHEX%%bin/miniprohex \
		%%MANPAGES%%man/man1/minipro.1.gz

.include <bsd.port.mk>
