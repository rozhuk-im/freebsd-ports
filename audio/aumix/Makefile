PORTNAME=	aumix
PORTVERSION=	2.9.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF \
		http://jpj.net/~trevor/aumix/ \
		http://jpj.net/~trevor/aumix/old/

MAINTAINER=	unix4all@gulic.org
COMMENT=	Audio mixer for X11, terminal, or command line
WWW=		http://jpj.net/~trevor/aumix.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--enable-own-labels \
		--libdir="${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
# Fix build with clang11
CFLAGS+=	-fcommon

PLIST_FILES=	bin/aumix bin/mute bin/xaumix \
		share/man/man1/aumix.1.gz \
		share/man/man1/xaumix.1.gz \
		share/man/man1/mute.1.gz
.for ii in ansi aumix.xpm fadein.set fadeout.set vt100 xterm
PLIST_FILES+=	share/aumix/${ii}
.endfor

OPTIONS_DEFINE=	NLS GTK2

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls
.for ii in ca de el es fr gl it ja nl pl pt_BR ru sv uk zh_CN
NLS_PLIST_FILES+=	share/locale/${ii}/LC_MESSAGES/aumix.mo
.endfor

GTK2_USES=	gnome
GTK2_USE=	GNOME=gtk20
GTK2_CONFIGURE_OFF=--without-gtk

pre-patch:
	@${REINPLACE_CMD} -e "s:/etc:${PREFIX}/etc:" ${WRKSRC}/src/common.[ch]

.include <bsd.port.mk>
