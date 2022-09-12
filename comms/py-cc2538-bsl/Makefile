PORTNAME=	cc2538-bsl
DISTVERSION=	20220803
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	TI CC13xx/CC2538/CC26xx Serial Boot Loader
WWW=		https://github.com/JelmerT/cc2538-bsl

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>=3.4:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}intelhex>=0:devel/py-intelhex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-magic>=0:devel/py-python-magic@${PY_FLAVOR}

USES=		python:3.4+ shebangfix
USE_PYTHON=	flavors
USE_GITHUB=	yes
GH_ACCOUNT=	JelmerT
GH_TAGNAME=	538ea0deb99530e28fdf1b454e9c9d79d85a3970
SHEBANG_FILES=	cc2538-bsl.py

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|tty.usbserial|cua|g" \
		${WRKSRC}/cc2538-bsl.py

# This is to prevent Mk/Uses/python.mk do-configure target from firing.
do-configure:
	@${ECHO} 'No configure'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cc2538-bsl.py ${STAGEDIR}${PREFIX}/bin/
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/cc2538-bsl.py

post-install:
	# Regenerate .PLIST.pymodtemp to get all installed files from
	# ${STAGEDIR}.
	@${FIND} ${STAGEDIR} -type f -o -type l | \
		${SORT} | ${SED} -e 's|${STAGEDIR}||' \
		>> ${WRKDIR}/.PLIST.mktmp

.include <bsd.port.mk>
