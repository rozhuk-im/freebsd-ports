PORTNAME=	ordered-set
PORTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	MutableSet that remembers its order, so that every entry has an index
WWW=		https://github.com/LuminosoInsight/ordered-set

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYTHON_VER} test/test_ordered_set.py

.include <bsd.port.mk>
