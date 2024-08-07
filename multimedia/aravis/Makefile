PORTNAME=		aravis
DISTVERSION=		0.8.31
CATEGORIES=		multimedia

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Camera control and image acquisition viewer
WWW=			https://github.com/AravisProject/aravis

LICENSE=		LGPL21+
LICENSE_FILE=		${WRKSRC}/COPYING

LIB_DEPENDS=		libaravis-0.8.so:devel/libaravis \
			libnotify.so:devel/libnotify

USES=			gettext gnome gstreamer meson pkgconfig
USE_GNOME=		cairo glib20 intltool gtk30

USE_GITHUB=		yes
GH_ACCOUNT=		AravisProject

MESON_ARGS=		-Dpacket-socket=disabled -Dviewer=enabled	\
			-Ddocumentation=disabled -Dintrospection=disabled \
			-Dgst-plugin=disabled -Dtests=false -Dusb=disabled

post-patch:
	@${REINPLACE_CMD} -e "s|subdir ('src')|aravis_dependencies += dependency ('aravis-0.8', version: '>=0.8', required: true)|g" \
		-e 's|meson.override_dependency.*||g' \
		${WRKSRC}/meson.build
	@${REINPLACE_CMD} -e "s|.*aravis_library.*||g" \
		-e "s|library_inc|include_directories('../src')|g" \
		${WRKSRC}/viewer/meson.build

.include <bsd.port.mk>
