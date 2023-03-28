PORTNAME=	sshfs
PORTVERSION=	3.7.4
PORTREVISION=	3
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	filesystems
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Mount remote directories over ssh
WWW=		https://github.com/rozhuk-im/sshfs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 fuse:3 gnome meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	rozhuk-im
GH_TAGNAME=	1dac7050efd1736d00a9aefc04d45643761246dc
USE_GNOME=	glib20

CFLAGS+=	-DNDEBUG

PLIST_FILES=	bin/sshfs

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	rst2man:textproc/py-docutils
DOCS_PLIST_FILES=	share/man/man1/sshfs.1.gz

.include <bsd.port.mk>
