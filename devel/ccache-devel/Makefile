PORTNAME=	ccache
PORTVERSION=	4.11.3.20250608
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	devel
PKGNAMESUFFIX=	-devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Tool to minimize the compile time of C/C++ programs
WWW=		https://ccache.samba.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/GPL-3.0.txt

CONFLICTS_INSTALL?= ccache-[0-9]* ccache-static-[0-9]* \
		ccache-memcached-[0-9]* ccache-memcached-static-[0-9]*

PORTDOCS=	AUTHORS.adoc AUTHORS.html LICENSE.html MANUAL.adoc \
		MANUAL.html NEWS.adoc NEWS.html

LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libzstd.so:archivers/zstd \
		libxxhash.so:devel/xxhash

USES=		cmake:noninja pathfix pkgconfig shebangfix compiler:c++17-lang
USE_GITHUB=	yes
GH_TAGNAME=	9c51f45f34ec0d09d292870e399e47f4c9bb784b
SUB_FILES=	world-ccache ccache-update-links.sh ccache_clean
# Prevent infinite recursion.
NO_CCACHE_DEPEND=yes
.export NO_CCACHE_DEPEND

CMAKE_OFF=	ENABLE_IPO \
		ENABLE_COVERAGE \
		ENABLE_SANITIZER_ADDRESS \
		ENABLE_SANITIZER_MEMORY \
		ENABLE_SANITIZER_UNDEFINED_BEHAVIOR \
		ENABLE_SANITIZER_THREAD \
		ENABLE_CPPCHECK \
		ENABLE_CLANG_TIDY

OPTIONS_DEFINE=		DOCS CLANGLINK LLVMLINK RSHTTP RSREDIS STATIC TEST
OPTIONS_DEFAULT=	CLANGLINK LLVMLINK
OPTIONS_SUB=		yes

DOCS_ALL_TARGET=	all doc
DOCS_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
DOCS_CMAKE_BOOL=	ENABLE_DOCUMENTATION
DOCS_USES=		perl5

CLANGLINK_DESC=		Create clang compiler links if clang is installed
LLVMLINK_DESC=		Create llvm compiler links if llvm is installed

RSHTTP_DESC=		Enable HTTP remote storage
RSHTTP_CMAKE_BOOL=	HTTP_STORAGE_BACKEND
#RSHTTP_BUILD_DEPENDS=	cpp-httplib>0:www/cpp-httplib

RSREDIS_DESC=		Enable Redis remote storage
RSREDIS_CMAKE_BOOL=	REDIS_STORAGE_BACKEND
RSREDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis

STATIC_CMAKE_BOOL=	STATIC_LINK
STATIC_LDFLAGS=		-static

TEST_DEPENDS=		bash:shells/bash
TEST_CMAKE_BOOL=	ENABLE_TESTING
TEST_TARGET=		check

.include <bsd.port.pre.mk>

CCLINKDIR=		libexec/ccache
PLIST_SUB+=		CCLINKDIR="${CCLINKDIR}"

.if ${ARCH}=="i386"
CCACHE_COMPILERS+=	icc icpc
.endif

GNU_COMPILERS+=		48 8 9 10 11 12	13 14 15 16 17 18 19 20
CCACHE_COMPILERS+=	cc c++ CC gcc g++ ${GNU_COMPILERS:S|^|gcc|} \
			${GNU_COMPILERS:S|^|g++|} \
			${GNU_COMPILERS:S|^|cpp|}

.if ${PORT_OPTIONS:MCLANGLINK}
CLANG_COMPILERS+=	10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 \
			26 27 28 29 30 31 32 -devel
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
