PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	0.0.16
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical UI/UX design tool
WWW=		http://akiraux.org/

LICENSE=	GPLv3+

LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgoocanvas-3.0.so:graphics/goocanvas3 \
		libgranite.so:x11-toolkits/granite \
		libjson-glib-1.0.so:devel/json-glib

USES=		desktop-file-utils gettext gnome libarchive meson pkgconfig \
		python:build shared-mime-info shebangfix vala:build
USE_GNOME=	cairo gdkpixbuf gtk30
USE_GITHUB=	yes
GH_ACCOUNT=	akiraux
GH_PROJECT=	Akira
GLIB_SCHEMAS=	com.github.akiraux.akira.gschema.xml
SHEBANG_FILES=	build-aux/meson/post_install.py

post-patch:
	@${REINPLACE_CMD} -e 's,The Linux,The UI/UX,' ${WRKSRC}/po/*.po \
		${WRKSRC}/data/com.github.akiraux.akira.appdata.xml.in.in \
		${WRKSRC}/data/com.github.akiraux.akira.desktop.in.in \
		${WRKSRC}/README.md ${WRKSRC}/src/Dialogs/SettingsDialog.vala

post-install:
	${LN} -sf com.github.akiraux.akira ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
