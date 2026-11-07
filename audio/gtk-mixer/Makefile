PORTNAME=	gtk-mixer
DISTVERSION=	1.0.5
CATEGORIES=	audio

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	GTK based volume control tool
WWW=		https://github.com/rozhuk-im/gtk-mixer

LICENSE=	GPLv2

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	rozhuk-im:DEFAULT \
		rozhuk-im:ssbs \
		freebsd:voss
GH_PROJECT=	ssbs:ssbs \
		virtual_oss:voss
GH_SUBDIR=	3rdparty/ssbs:ssbs \
		3rdparty/virtual_oss:voss
GH_TAGNAME=	8bf593f27f91dae31d9252d65602fee58af1ce24:DEFAULT \
		2579b9e8fcb5aaa2a6cdd3101d0ee7f990d44b5e:ssbs \
		v1.3.3:voss
USE_GNOME=	cairo gdkpixbuf gtk30

DESKTOP_ENTRIES=	"GTK-Mixer" \
			"${COMMENT}" \
			"multimedia-volume-control" \
			"${PORTNAME}" \
			"GTK;AudioVideo;Audio;Mixer;" \
			true

PLIST_FILES=	bin/gtk-mixer

do-build:
	@${WRKSRC}/make.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build-release/gtk-mixer ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
