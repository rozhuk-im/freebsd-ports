# $FreeBSD$

PORTNAME=	uefi-edk2-bhyve
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	UEFI-EDK2 firmware for bhyve

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	bash:shells/bash \
		nasm:devel/nasm \
		${PYTHON_LIBDIR}/lib-dynload/_sqlite3.so:databases/py-sqlite3@${PY_FLAVOR}

USES=		gmake \
		python:2.7,build
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	uefi-edk2
GH_TAGNAME=	aa8d718

PLIST_FILES=	${PREFIX}/share/uefi-firmware/BHYVE_UEFI${PLIST_SUFFIX}.fd

OPTIONS_DEFINE=	DEBUG

DEBUG_VARS=	uefi_target=DEBUG
DEBUG_VARS_OFF=	uefi_target=RELEASE

MAKE_ARGS+=	AS="${AS}" \
		AR="${AR}" \
		LD="${LD}" \
		OBJCOPY="${OBJCOPY}" \
		CC="${CC}" \
		CXX="${CXX}" \
		CFLAGS='-Wno-error -I../h -I../support/set -DUSER_ZZSYN=1'

BUILD_ARGS=-DDEBUG_ON_SERIAL_PORT=TRUE -D FD_SIZE_2MB

.include <bsd.port.options.mk>

.if defined(WITH_CSM)
PLIST_SUFFIX=	_CSM
BUILD_ARGS+=	-DCSM_ENABLE=TRUE
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|' ${WRKSRC}/BaseTools/Tests/GNUmakefile \
							${WRKSRC}/BaseTools/BinWrappers/PosixLike/*
	@${REINPLACE_CMD} -e 's|mStringFileName == .*)|mStringFileName == NULL)|' \
		${WRKSRC}/EdkCompatibilityPkg/Sample/Tools/Source/UefiVfrCompile/VfrUtilityLib.cpp \
		${WRKSRC}/BaseTools/Source/C/VfrCompile/VfrUtilityLib.cpp
	@${REINPLACE_CMD} -e 's|while (StringPtr != .*)|while (StringPtr)|' \
		${WRKSRC}/MdeModulePkg/Library/UefiHiiLib/HiiLib.c
	# Clang specific.
	@${REINPLACE_CMD} -e 's|-Wno-unused-but-set-variable|-Wno-error|g' \
		-e 's|--oformat=elf64-x86-64|--format=elf64-x86-64|g' \
		${WRKSRC}/BaseTools/Conf/tools_def.template

do-build:
	unset ARCH; unset MAKEFLAGS; ${MAKE_CMD} ${MAKE_ARGS} -C ${BUILD_WRKSRC}/BaseTools
	${MKDIR} ${BUILD_WRKSRC}/Build;
	@for f in ${CC}:gcc ${LD}:ld ${GMAKE}:make ${AR}:ar ${OBJCOPY}:objcopy nasm; do \
		${LN} -vsf $$(command -v $${f%:*}) ${BUILD_WRKSRC}/Build/$${f##*:}; \
	done
.if defined(WITH_CSM)
	bash -c " \
		cd ${BUILD_WRKSRC}; \
		source edksetup.sh;\
		unset ARCH; unset MAKEFLAGS; \
	        ${MAKE_CMD} ${MAKE_ARGS} GCC48_BIN=${BUILD_WRKSRC}/Build/ -C ${BUILD_WRKSRC}/BhyvePkg/Csm/BhyveCsm16/"
.endif
	bash -c " \
		cd ${BUILD_WRKSRC}; \
		source edksetup.sh;\
		unset ARCH; unset MAKEFLAGS; \
		export GCC48_BIN=${BUILD_WRKSRC}/Build/; \
		build -t GCC48 -a X64 -b ${UEFI_TARGET} -p BhyvePkg/BhyvePkgX64.dsc ${BUILD_ARGS} \
	"

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/uefi-firmware/
	${INSTALL} ${BUILD_WRKSRC}/Build/BhyveX64/${UEFI_TARGET}_GCC48/FV/BHYVE.fd \
		${STAGEDIR}${PREFIX}/share/uefi-firmware/BHYVE_UEFI${PLIST_SUFFIX}.fd

.include <bsd.port.mk>
RUN_DEPENDS:=	${RUN_DEPENDS:Ngcc*}
