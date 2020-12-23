# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD: head/multimedia/kodi-addon-game.libretro.play-devel/Makefile 528699 2020-03-19 07:54:02Z tobik $

PORTNAME=	game.libretro.play
PORTVERSION=	0.30.0
DISTVERSIONSUFFIX=	-Leia
CATEGORIES=	multimedia games
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Sega - MS/MD/CD/32X (PicoDrive) for Kodi

LICENSE_FILE=	${WRKSRC}/depends/common/play/COPYING

BUILD_DEPENDS=	kodi-devel>=19.0.a20200318:multimedia/kodi-devel
LIB_DEPENDS=	libicuuc.so:devel/icu
RUN_DEPENDS=	kodi-devel>=19.0.a20200318:multimedia/kodi-devel \
		kodi-addon-game.libretro-devel>=0:multimedia/kodi-addon-game.libretro-devel

USES=		cmake ssl gl compiler:c++14-lang
USE_GL=		egl gl glew glu
USE_LDCONFIG=	yes
USE_CXXSTD=	c++14
#USE_GCC=	yes
CFLAGS=		-pipe -O0 -g3 -ggdb -fpie -fsanitize=address
CPPFLAGS=	-pipe -O0 -g3 -ggdb -fpie -fsanitize=address
CXXFLAGS=	-pipe -O0 -g3 -ggdb -fpie -fsanitize=address
#LLD_UNSAFE=	yes
LDFLAGS+=	-pthread -fsanitize=address # -stdlib=libc++ # -static-libstdc++ -static-libgcc # --static
USE_GITHUB=	yes
GH_ACCOUNT=	rozhuk-im \
		jpd002:play \
		jpd002:codegen \
		jpd002:framework \
		jpd002:dependencies \
		gulrak:ghc_filesystem
		#libretro:play \

GH_PROJECT=	Play-:play \
		Play--CodeGen:codegen \
		Play--Framework:framework \
		Play-Dependencies:dependencies \
		filesystem:ghc_filesystem
# Keep in sync with: depends/common/play/play.txt
GH_TAGNAME=	ce31f1a \
		5e1c39017b46a02a3ec2b50390db0b0b936def86:play \
		88aaa95093538ce0731632b52e97fd8f3f6bcb4f:codegen \
		a29a0a852d8549cc88fdd9e1cc1d8921650dbfe0:framework \
		1d582d48c9768f13e38cc2860061a833ae30b4c2:dependencies \
		8ea72cfb7312ac1bce58ebc18cec599b0045bfc9:ghc_filesystem
		#884ae3b96c631f235cd18b2643d1f318fa6951fb:play \
		#1324776:codegen \
		#f04716b:framework \

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME} \
		-DSHORT_HASH=${GH_TAGNAME_DEFAULT} \
		-DBUILD_PLAY:BOOL=OFF \
		-DBUILD_PSFPLAYER:BOOL=OFF \
		-DBUILD_TESTS:BOOL=OFF \
		-DBUILD_AOT_CACHE:BOOL=OFF \
		-DBUILD_LIBRETRO_CORE:BOOL=ON \
		-DENABLE_AMAZON_S3:BOOL=OFF \
		-DPLAY_LIB=../.build/depends/common/play/Source/ui_libretro/play_libretro.so

post-extract:
	@${MV} ${WRKSRC_play}/* ${WRKSRC}/depends/common/play/
	@${MV} ${WRKSRC_codegen}/* ${WRKSRC}/depends/common/play/deps/CodeGen/
	@${MV} ${WRKSRC_framework}/* ${WRKSRC}/depends/common/play/deps/Framework/
	@${MV} ${WRKSRC_dependencies}/* ${WRKSRC}/depends/common/play/deps/Dependencies/
	@${MV} ${WRKSRC_ghc_filesystem}/* ${WRKSRC}/depends/common/play/deps/Dependencies/ghc_filesystem/

post-patch:
	@${REINPLACE_CMD} -e 's|find_library(PLAY_LIB.*|add_subdirectory(depends/common/play)|g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|execute_process(COMMAND git rev-parse.*|set(SHORT_HASH_RESULT 0)|g' \
		${WRKSRC}/depends/common/play/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|target_compile_options(PUBLIC|add_compile_options(|g' \
		${WRKSRC}/depends/common/play/Source/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|if(CMAKE_CURRENT_SOURCE_DIR STREQUAL.*|if (TRUE)|g' \
		${WRKSRC}/depends/common/play/deps/Dependencies/cmake-modules/Header.cmake
	@${REINPLACE_CMD} -e 's|memset(.*||g' \
		${WRKSRC}/depends/common/play/Source/MemoryUtils.cpp
	# Make libs static
	@${REINPLACE_CMD} -e 's|add_library(CodeGen|add_library(CodeGen STATIC|g' \
		${WRKSRC}/depends/common/play/deps/CodeGen/build_cmake/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|add_library(Framework_OpenGl|add_library(Framework_OpenGl STATIC|g' \
		${WRKSRC}/depends/common/play/deps/Framework/build_cmake/FrameworkOpenGl/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|add_library(Framework|add_library(Framework STATIC|g' \
		${WRKSRC}/depends/common/play/deps/Framework/build_cmake/Framework/CMakeLists.txt
	# Other
	@${REINPLACE_CMD} -e 's|list(APPEND PROJECT_LIBS "-static.*||g' \
		${WRKSRC}/depends/common/play/Source/ui_libretro/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|set(CMAKE_CXX_STANDARD.*||g' \
		${WRKSRC}/depends/common/play/deps/Dependencies/cmake-modules/Header.cmake \
		${WRKSRC}/depends/common/play/deps/Framework/build_cmake/Framework_Common.cmake \
		${WRKSRC}/depends/common/play/deps/CodeGen/build_cmake/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|std::filesystem|std::__fs::filesystem|g' \
		-e 's|defined(__APPLE__)|1|g' \
		${WRKSRC}/depends/common/play/deps/Framework/include/filesystem_def.h
	@${REINPLACE_CMD} -e 's|defined(__linux__)|1|g' \
		${WRKSRC}/depends/common/play/deps/Dependencies/ghc_filesystem/include/ghc/filesystem.hpp
	# Run
	@${REINPLACE_CMD} -e 's|CLog::GetInstance().Print(LOG_NAME|fprintf(stderr|g' \
		-e 's|CLog::GetInstance().Warn(LOG_NAME|fprintf(stderr|g' \
		${WRKSRC}/depends/common/play/Source/ui_libretro/main_libretro.cpp \
		${WRKSRC}/depends/common/play/Source/ui_libretro/GSH_OpenGL_Libretro.cpp
	@${REINPLACE_CMD} -e 's|defined(USE_GLEW)|1|g' \
		-e 's|assert(result == GLEW_OK);||g' \
		${WRKSRC}/depends/common/play/Source/ui_libretro/GSH_OpenGL_Libretro.cpp
	#@${REINPLACE_CMD} -e 's|m_virtualMachine->m_ee->m_gs|SetupVideoHandler(); m_virtualMachine->m_ee->m_gs|g' \
	#	${WRKSRC}/depends/common/play/Source/ui_libretro/main_libretro.cpp
	@${REINPLACE_CMD} -e 's|m_virtualMachine->m_ee->m_gs|if (m_virtualMachine->m_ee->m_gs) m_virtualMachine->m_ee->m_gs|g' \
		-e 's|first_run = true;|first_run = true;SetupVideoHandler();|g' \
		${WRKSRC}/depends/common/play/Source/ui_libretro/main_libretro.cpp
	#@${REINPLACE_CMD} -e 's|gs->WriteRegisterMassively|if (gs) gs->WriteRegisterMassively|g' \
	#	 -e 's|m_gs->FeedImageData|if (m_gs) m_gs->FeedImageData|g' \
	#	${WRKSRC}/depends/common/play/Source/ee/GIF.cpp
	#@${REINPLACE_CMD} -e 's|assert(thread->contextPtr >= thread->stackBase);||g' \
	#	${WRKSRC}/depends/common/play/Source/ee/PS2OS.cpp
	#@${REINPLACE_CMD} -e 's|CAppConfig::GetInstance().GetPreferenceBoolean(PREF_LOG_SHOWPRINTS)|true|g' \
	#	-e 's|#ifndef DISABLE_LOGGING|#if 0|g' \
	#	-e 's|#if defined(_DEBUG) && !defined(DISABLE_LOGGING)|#if 0|g' \
	#	${WRKSRC}/depends/common/play/Source/Log.cpp
	#@${REINPLACE_CMD} -e 's|Framework::PathUtils::GetPersonalDataPath() / BASE_DATA_PATH|"/tmp/"|g' \
	#	${WRKSRC}/depends/common/play/Source/AppConfig.cpp

post-install:
	#rm -rf ${STAGEDIR}${PREFIX}/lib/libretro

.include <bsd.port.mk>
