PORTNAME=	wheel
PORTVERSION=	0.44.0
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	044

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Built-package format for Python
WWW=		https://github.com/pypa/wheel

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.8:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	allflavors autoplist concurrent pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}wheel
PORTSCOUT=	ignore:1

# see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=268500
EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 /usr/bin/bsdtar
NO_ARCH=	yes

CONFLICTS_INSTALL=	py*-wheel

.include <bsd.port.mk>
