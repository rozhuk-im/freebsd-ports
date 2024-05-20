PORTNAME=	pragtical
PORTVERSION=	3.3.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Practical and pragmatic code editor
WWW=		https://pragtical.dev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpcre2-8.so:devel/pcre2 \
		libuchardet.so:textproc/uchardet

USES=		desktop-file-utils localbase:ldflags meson pkgconfig sdl
USE_SDL=	sdl2
MESON_ARGS=	-Duse_system_lua=true -Dppm=false

USE_GITHUB=	yes
GH_PROJECT=	colors:clr \
		formatter:fmtrs \
		lsp:lsp \
		plugins:plg \
		widget:wgt
GH_TAGNAME=	65e929ea68ece09bb7b3ef76ac36e1a83b30f752:clr \
		0c77df3b67f9eb7ffc0dcbfe9c035282e6ef0e62:fmtrs \
		75c6db676830bb1017b47fb23133db7bbee076b0:plg \
		a1f7b75bfb508d46cdcc36f4e08afbae05b259dd:lsp \
		48293bf57f843328542e881d2777a52f17d64094:wgt
GH_SUBDIR=	data/widget:wgt \
		data/plugins/formatter:fmtrs \
		data/plugins/lsp:lsp \
		subprojects/colors:clr \
		subprojects/plugins:plg

PORTDOCS=	changelog.md licenses.md

OPTIONS_DEFINE=	JIT DOCS
OPTIONS_DEFAULT=	JIT
OPTIONS_SUB=	yes

JIT_DESC=	Use Lua JIT compiler
JIT_USES=	luajit
JIT_USES_OFF=	lua:54
JIT_MESON_OFF=	-Djit=false

post-extract:
	@${RM} 	${WRKSRC}/subprojects/plugins/plugins/font_nonicons.lua \
		${WRKSRC}/subprojects/plugins/plugins/font_symbols_nerdfont_mono_regular.lua \
		${WRKSRC}/subprojects/plugins/plugins/jsonmod.lua \
		${WRKSRC}/subprojects/plugins/plugins/lite-debugger.lua \
		${WRKSRC}/subprojects/plugins/plugins/nerdicons.lua \
		${WRKSRC}/subprojects/plugins/plugins/nonicons.lua
.for sp in colors plugins
	@cd ${WRKSRC}/subprojects && ${CP} -a packagefiles/${sp}/* ${sp}
.endfor
	@${CP} -a ${WRKSRC}/subprojects/plugins/plugins ${WRKSRC}/data/

post-patch:
	@${REINPLACE_CMD} -e '/host_machine\.system/s,linux,${OPSYS:tl},' \
		${WRKSRC}/meson.build
	@${REINPLACE_CMD} -e "s|USERDIR|\"${DATADIR}\"|g" \
		${WRKSRC}/data/plugins/lsp/config.lua \
		${WRKSRC}/data/plugins/lsp/init.lua \
		${WRKSRC}/data/plugins/lsp/ui/symbolstree.lua
	@${FIND} ${WRKSRC} -type f -name '*.bak' -delete

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/changelog.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
