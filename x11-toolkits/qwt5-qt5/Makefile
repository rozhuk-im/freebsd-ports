PORTNAME=	qwt5-qt5
PORTVERSION=	5.2.3g20210209
CATEGORIES=	x11-toolkits

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt Widgets for Technical Applications
WWW=		http://qwt.sourceforge.net/

LICENSE=	LGPL21 QWT
LICENSE_COMB=	multi
LICENSE_NAME_QWT=	QWT
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS_QWT=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

USES=		cmake compiler:c++17-lang pathfix qt:5
USE_QT=		core gui printsupport svg widgets buildtools:build qmake:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	SciDAVis
GH_TAGNAME=	2a9f1ae2

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=True \
		-DQWT_DESIGNER=False

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
