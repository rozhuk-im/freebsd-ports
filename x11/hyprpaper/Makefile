PORTNAME=	hyprpaper
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	x11 wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	03cd362f494d.patch:-p1 # https://github.com/hyprwm/hyprpaper/issues/169

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Blazing fast Wayland wallpaper utility with IPC controls
WWW=		https://github.com/hyprwm/hyprpaper

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libwayland-client.so:graphics/wayland \
		libwebp.so:graphics/webp

USES=		compiler:c++11-lib cmake gnome jpeg localbase:ldflags pkgconfig
USE_GNOME=	cairo
USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm
PLIST_FILES=	bin/${PORTNAME}

post-patch:
# Extract (snapshot) version from the port instead of Git
	@${REINPLACE_CMD} -i .nogit -e '/Get git info/,/^#$$/d' \
		-e 's/$${GIT_BRANCH}/main/' \
		-e 's/$${GIT_COMMIT_HASH}/${GH_TAGNAME}/' \
		-e '/$${GIT_COMMIT_MESSAGE}/d' \
		-e 's/$${GIT_DIRTY}/portbld/' \
		${WRKSRC}/CMakeLists.txt
# Drop unused dependencies
	@${REINPLACE_CMD} -e 's/ pango pangocairo//' \
		-e '/OpenGL/d; /GLESv2/d' \
		-e '/ rt)/d' \
		${WRKSRC}/CMakeLists.txt
# Respect consolekit2 as XDG_RUNTIME_DIR fallback
	@${REINPLACE_CMD} 's,/run/user,/var&,' \
		${WRKSRC}/src/ipc/Socket.cpp

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
