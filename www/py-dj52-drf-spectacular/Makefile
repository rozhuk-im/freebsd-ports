PORTNAME=	drf-spectacular
DISTVERSION=	0.28.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj52-
DISTNAME=	drf_spectacular-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Sane/flexible OpenAPI 3 schema generation for Django REST framework
WWW=		https://github.com/tfranzel/drf-spectacular

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=2.2:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-djangorestframework>=3.10.3:www/py-dj52-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inflection>=0.3.1:devel/py-inflection@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.6.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uritemplate>=2.0.0:net/py-uritemplate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

OPTIONS_DEFINE=		SIDECAR
OPTIONS_DEFAULT=	SIDECAR

SIDECAR_DESC=	Enable self-contained Swagger/Redoc UI installation
SIDECAR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj52-drf-spectacular-sidecar>0:www/py-dj52-drf-spectacular-sidecar@${PY_FLAVOR}

.include <bsd.port.mk>
