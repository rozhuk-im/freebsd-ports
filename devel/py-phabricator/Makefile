PORTNAME=	phabricator
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Phabricator API Bindings
WWW=		https://github.com/disqus/python-phabricator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>0:devel/py-responses@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils
USE_GITHUB=	yes

GH_ACCOUNT=	disqus
GH_PROJECT=	python-${PORTNAME}

PORTDOCS=	CHANGES LICENSE README.rst

OPTIONS_DEFINE=	DOCS TESTS

TESTS_DESC=		Include test suite requirements
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
