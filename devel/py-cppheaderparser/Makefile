PORTNAME=	${_PYPI_NAME:tl}
PORTVERSION=	2.7.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${_PYPI_NAME}-${PORTVERSION}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Parse C++ header files and generate a data structure representing the class
WWW=		https://senexcanis.com/open-source/cppheaderparser/

# There is no license file,
# the license is specified directly in the source file.
LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist distutils
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

_PYPI_NAME=	CppHeaderParser

.include <bsd.port.mk>
