PORTNAME=	virtual_midi
DISTVERSION=	1.0.1
CATEGORIES=	audio multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Creates soft MIDI devices for H/W sound cards without MIDI support
WWW=		https://github.com/rozhuk-im/virtual_midi

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${LOCALBASE}/share/sounds/sf2/FluidR3_GM.sf2:audio/fluid-soundfont
LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

USES=		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	rozhuk-im
GH_PROJECT=	virtual_midi:DEFAULT \
		ssbs:ssbs
GH_SUBDIR=	3rdparty/ssbs:ssbs
GH_TAGNAME=	5b0cb3bac78f58790f80fb6a599ff2fa1247ea14:DEFAULT \
		2579b9e8fcb5aaa2a6cdd3101d0ee7f990d44b5e:ssbs

USE_RC_SUBR=	virtual_midi virtual_oss_sequencer
PKGMESSAGE=	${WRKSRC}/pkg-message
SUB_FILES=	pkg-message

PLIST_FILES=	bin/virtual_midi \
		bin/virtual_oss_sequencer \
		etc/rc.d/virtual_midi \
		etc/rc.d/virtual_oss_sequencer

do-build:
	@${WRKSRC}/make.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build-release/virtual_midi \
		${WRKSRC}/build-release/virtual_oss_sequencer \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
