PORTNAME=	rubymarshal
PORTVERSION=	1.2.10
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Read and write Ruby-marshalled data
WWW=		https://pypi.org/project/rubymarshal/

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mutagen>=0:devel/py-pytest-mutagen@${PY_FLAVOR}

USE_GITHUB=	yes  # tests are missing from PyPI distribution
GH_ACCOUNT=	d9pouces
GH_PROJECT=	RubyMarshal

USES=		python
USE_PYTHON=	autoplist distutils pytest
NO_ARCH=	yes

.include <bsd.port.mk>
