PORTNAME=	warpinator
DISTVERSION=	1.2.9
CATEGORIES=	net-p2p gnome
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	gnome

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Share files across the LAN

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.16.0:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=0:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xapp>=1.6.0:x11/py-python-xapp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=0:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zeroconf>=0.27.0:net/py-zeroconf@${PY_FLAVOR} \
		xapp>=0:x11/xapp

USES=		gettext gnome meson python:3.6+ shebangfix
USE_GNOME=	glib20 gtk30 pygobject3
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
MESON_ARGS=	-Dinclude-firewall-mod=false \
		-Dflatpak-build=false \
		-Dbundle-zeroconf=false
BINARY_ALIAS=	python3=${PYTHON_CMD}
SHEBANG_FILES=	generate-protobuf bin/warpinator.in testing/testrun
SHEBANG_GLOB=	*.py
GLIB_SCHEMAS=	org.x.Warpinator.gschema.xml

.include <bsd.port.mk>
