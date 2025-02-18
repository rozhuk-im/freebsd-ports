PORTNAME=	kwin
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-wm kde kde-plasma

PATCH_SITES=	https://invent.kde.org/plasma/kwin/-/commit/
# https://bugs.kde.org/show_bug.cgi?id=499846
PATCHFILES=	c97bc26ca9de8b1462f6ccb05fb2dafe01cd82cb.diff:-p1
# https://bugs.kde.org/500261
PATCHFILES+=	1e7421d6b0e7ac03d1cac8323c5436a867dfc3db.diff:-p1
PATCHFILES+=	c2f60491aa96222b0e8599901eb0a8ce3fcc65a9.diff:-p1

COMMENT=	Easy to use, but flexible, X Window Manager and Wayland Compositor
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		hwdata>0:misc/hwdata \
		wayland-protocols>0:graphics/wayland-protocols \
		Xwayland:x11-servers/xwayland
LIB_DEPENDS=	libdisplay-info.so:sysutils/libdisplay-info \
		libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libinput.so:x11/libinput \
		liblcms2.so:graphics/lcms2 \
		libpipewire-0.3.so:multimedia/pipewire \
		libqaccessibilityclient-qt6.so:accessibility/libqaccessibilityclient@qt6 \
		libudev.so:devel/libudev-devd \
		libwayland-client.so:graphics/wayland \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcvt.so:x11/libxcvt \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	hwdata>0:misc/hwdata \
		Xwayland:x11-servers/xwayland

CONFLICTS_INSTALL=	theseus-ship # bin/kwin_wayland

USES=		cmake gettext gl kde:6 pkgconfig python qt:6 shebangfix tar:xz \
		xorg
USE_GL=		egl gbm gl opengl
USE_KDE=	activities attica auth breeze colorscheme config \
		configwidgets coreaddons crash dbusaddons decoration \
		globalaccel globalacceld guiaddons i18n idletime kcmutils \
		kdeclarative kpipewire kscreenlocker libplasma newstuff \
		notifications package runner service svg wayland widgetsaddons \
		windowsystem xmlgui \
		ecm:build plasma-wayland-protocols:build
USE_QT=		base declarative multimedia sensors tools wayland
USE_XORG=	ice sm x11 xcb xext xi

BINARY_ALIAS=	python3=${PYTHON_CMD}
SHEBANG_FILES=	src/plugins/strip-effect-metadata.py

.include <bsd.port.mk>
