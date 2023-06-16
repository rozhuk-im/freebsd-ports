PORTNAME=	uwsgi-tasks
PORTVERSION=	0.7.3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Asynchronous tasks management with UWSGI server
WWW=		https://github.com/Bahus/uwsgi_tasks

LICENSE=	MIT

RUN_DEPENDS=	uwsgi-${PYTHON_VER}:www/uwsgi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
