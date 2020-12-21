# Created by: Dominic Marks <d.marks@student.umist.ac.uk>
# $FreeBSD$

PORTNAME=	ccache
PORTVERSION=	4.1.20201211
CATEGORIES=	devel
PKGNAMESUFFIX=	-devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
#PATCHFILES+=	

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Tool to minimize the compile time of C/C++ programs

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/GPL-3.0.txt

CONFLICTS_INSTALL?= ccache-[0-9]* ccache-static-[0-9]* \
		ccache-memcached-[0-9]* ccache-memcached-static-[0-9]*

PORTDOCS=	AUTHORS.adoc AUTHORS.html MANUAL.html MANUAL.adoc \
		NEWS.adoc NEWS.html

USES=		cmake:noninja pathfix shebangfix compiler:c++11-lang
USE_GITHUB=	yes
GH_TAGNAME=	238553a1c470e4cadc08c720a1ab915ac8d41e13
SUB_FILES=	world-ccache ccache-update-links.sh ccache_clean
# Prevent infinite recursion.
NO_CCACHE_DEPEND= yes

# /bin/bash -> /bin/sh to reduce tests dep.
SHEBANG_FILES=	test/*
SHEBANG_GLOB=	*.sh *.bash
bash_CMD=	/bin/sh

CMAKE_OFF=	WARNINGS_AS_ERRORS \
		ENABLE_IPO \
		ZSTD_FROM_INTERNET \
		ENABLE_TRACING \
		STATIC_LINK

OPTIONS_DEFINE=	DOCS CLANGLINK LLVMLINK STATIC TEST
OPTIONS_DEFAULT=CLANGLINK LLVMLINK
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS= a2x:textproc/asciidoc
DOCS_ALL_TARGET=all doc

CLANGLINK_DESC=	Create clang compiler links if clang is installed
LLVMLINK_DESC=	Create llvm compiler links if llvm is installed

STATIC_LDFLAGS=	-static

TEST_CMAKE_BOOL=ENABLE_TESTING
TEST_TARGET=	check

.include <bsd.port.pre.mk>

CCLINKDIR=		libexec/ccache
PLIST_SUB+=		CCLINKDIR="${CCLINKDIR}"

.if ${ARCH}=="i386"
CCACHE_COMPILERS+=	icc icpc
.endif

GNU_COMPILERS+=		34 42 43 44 45 46 47 48 49 5 6 7 8 9 10 11 12
CCACHE_COMPILERS+=	cc c++ CC gcc g++ ${GNU_COMPILERS:S|^|gcc|} \
			${GNU_COMPILERS:S|^|g++|} \
			${GNU_COMPILERS:S|^|cpp|}

.if ${PORT_OPTIONS:MCLANGLINK}
CLANG_COMPILERS+=	33 34 35 36 37 38 39 40 50 60 70 80 90 10 11 12 -devel
CCACHE_COMPILERS+=	clang clang++ ${CLANG_COMPILERS:S|^|clang|} \
			${CLANG_COMPILERS:S|^|clang++|} \
			${CLANG_COMPILERS:S|^|cpp|}
.endif

.if ${PORT_OPTIONS:MLLVMLINK}
CCACHE_COMPILERS+=	llvm-gcc llvm-c++ llvm-g++
.endif

CCACHE_COMPILERS+=	${EXTRA_COMPILERS}
SUB_LIST+=		CCACHE_COMPILERS="${CCACHE_COMPILERS}" \
			CCLINKDIR="${CCLINKDIR}"

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's|add_subdirectory(doc)||g' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${CCLINKDIR}/world
	${INSTALL_SCRIPT} ${WRKDIR}/world-ccache \
		${STAGEDIR}${PREFIX}/${CCLINKDIR}/world/ccache
	${INSTALL_SCRIPT} ${WRKDIR}/ccache-update-links.sh \
		${STAGEDIR}${PREFIX}/bin/ccache-update-links
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/ccache_clean \
		${STAGEDIR}${PREFIX}/etc/periodic/daily

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.adoc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
