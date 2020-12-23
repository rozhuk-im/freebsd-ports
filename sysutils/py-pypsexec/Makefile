PORTNAME=	pypsexec
PORTVERSION=	0.3.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Run commands on a remote Windows host using SMB/RPC
WWW=		https://github.com/jborean93/pypsexec

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}smbprotocol>=0:net/py-smbprotocol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
