PORTNAME=	virtual_midi
DISTVERSION=	1.0.0
CATEGORIES=	audio multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Creates soft MIDI devices for H/W sound cards without MIDI support
WWW=		https://github.com/rozhuk-im/virtual_midi

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${LOCALBASE}/share/sounds/sf2/FluidR3_GM.sf2:audio/fluid-soundfont
LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	rozhuk-im
GH_PROJECT=	virtual_midi
GH_TAGNAME=	9e0dedeb3cef118fe10b0581c2ec23d2079cc857

PKGMESSAGE=	${WRKSRC}/pkg-message
SUB_FILES=	pkg-message

PLIST_FILES=	bin/virtual_midi \
		bin/virtual_oss_sequencer \
		etc/rc.d/virtual_midi \
		etc/rc.d/virtual_oss_sequencer

.include <bsd.port.mk>
