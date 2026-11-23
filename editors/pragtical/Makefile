PORTNAME=	pragtical
PORTVERSION=	3.15.0
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
USE_SDL=	sdl3 image3 mixer3
MESON_ARGS=	-Dnet=false -Duse_system_lua=true -Dppm=false

USE_GITHUB=	yes
GH_PROJECT=	colors:clr \
		formatter:fmtrs \
		lua-linenoise:linenoise \
		lsp:lsp \
		plugins:plg \
		widget:wgt
GH_TAGNAME=	17b6205986534fa576b59a84bd854f03123e1fc2:clr \
		7a47859a70b73eb5d6ef5b741f0ab8a7bf10bff1:fmtrs \
		5c972eb4d59de5bee551cd9ad96e5b01abd69b0a:plg \
		e78e236c8d85c078fdd9fc4e1f08716058aa1a42:linenoise \
		b2a09f5a3c03685218cd0daddc88d3d1032f4f89:lsp \
		c9b106dbbcfd217944c63fb46279df4a8a3cddf7:wgt
GH_SUBDIR=	data/widget:wgt \
		data/plugins/formatter:fmtrs \
		subprojects/linenoise:linenoise \
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
		${WRKSRC}/subprojects/plugins/plugins/input_latency.lua \
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
