PORTNAME=	pragtical
PORTVERSION=	3.5.2
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
GH_TAGNAME=	2bf05fe2a16c3a9a83cee44ae233fa23ac95c6d1:clr \
		28056e06d85684fc3f428996d2c93b3337f38d0c:fmtrs \
		4877681674664b7a5a602002c1d17924de015104:plg \
		ed5ddf661211db630dfe06adb742cd4821ea5099:lsp \
		a2637c377da8a92eb4bd966d12ab6a45e71c4e43:wgt
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
