PORTNAME=	codelite
PORTVERSION=	17.0.0.20240408
PORTREVISION=	0
CATEGORIES=	editors devel
PKGNAMESUFFIX=	-devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
#PATCHFILES+=	07e7b8728c6b6065c625e82db3cd86ccfda83595.patch:-p1 # https://github.com/eranif/codelite/pull/3336

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Open Source IDE for C/C++
WWW=		https://codelite.org/

LICENSE=	GPLv2+

RUN_DEPENDS=	${LOCALBASE}/bin/open:sysutils/open
LIB_DEPENDS=	libsqlite3.so:databases/sqlite3 \
		libuchardet.so:textproc/uchardet

USES=		cmake:noninja compiler:c++17-lang dos2unix gettext gnome \
		localbase pathfix pkgconfig shebangfix sqlite
USE_GNOME=	cairo glib20 gtk30
DOS2UNIX_GLOB=	*.cpp *.txt
SHEBANG_FILES=	Runtime/codelite_xterm
USE_WX=		3.2

USE_GITHUB=	yes
GH_ACCOUNT=	eranif:DEFAULT \
		eranif:ctags \
		cubicdaiya:dtl \
		eranif:tinyjson \
		eranif:wxdap \
		jbeder:yamlcpp
GH_PROJECT=	codelite:DEFAULT \
		cc-wrapper:ccwrapper \
		ctags:ctags \
		dtl:dtl \
		tinyjson:tinyjson \
		wxdap:wxdap \
		yaml-cpp:yamlcpp
GH_TAGNAME=	c96ed5584981d444a9089ae90650bc056de5d52d:DEFAULT \
		67713440e867493e74ce5c7ce0352b81eb4b726b:ccwrapper \
		3e173d8d82fd2d3534feff0d822d6de36ca3d74e:ctags \
		cd45dd48089c6e9f7a595d920ddfb82c08d59150:dtl \
		a6b0d0d31a05a9f55b4944b3b20f769305eb583a:tinyjson \
		e5c7d35f17ca119aa99710244c0764b07f0cc4c6:wxdap \
		1b50109f7bea60bd382d8ea7befce3d2bd67da5f:yamlcpp
GH_SUBDIR=	ctags:ctags \
		cc-wrapper:ccwrapper \
		dtl:dtl \
		cc-wrapper/tinyjson:tinyjson \
		wxdap:wxdap \
		yaml-cpp:yamlcpp

CMAKE_ARGS=	-DHAVE_GLIB_GREGEX_H=1 \
		-DCL_PREFIX:STRING="${PREFIX}" \
		-DRETAIN_CACHED_VALUES:BOOL=ON \
		-DCL_GTK_USE_NATIVEBOOK:STRING=1 \
		-DWITH_NATIVEBOOK:STRING=1 \
		-DWITH_WX_CONFIG:FILEPATH="${WX_CONFIG}" \
		-DCL_WX_CONFIG:STRING="${WX_CONFIG:T}"
USE_LDCONFIG=	${PREFIX}/lib/codelite
INSTALLS_ICONS=	yes

OPTIONS_RADIO=		CLANG
OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	CALLGRAPH CMAKE CSCOPE GIT HELP MEMCHK \
			QMAKE SFTP SPELLCHK SVN
OPTIONS_DEFAULT=	GIT SFTP
OPTIONS_SUB=		yes

CALLGRAPH_DESC=		CallGraph plugin
CALLGRAPH_RUN_DEPENDS=	${LOCALBASE}/bin/dot:graphics/graphviz
CMAKE_DESC=		CMake plugin
CMAKE_RUN_DEPENDS=	${LOCALBASE}/bin/cmake:devel/cmake-core
CSCOPE_DESC=		CScope integration
CSCOPE_RUN_DEPENDS=	cscope:devel/cscope
GIT_DESC=		Build with git support
GIT_RUN_DEPENDS=	${LOCALBASE}/bin/git:devel/git
MEMCHK_DESC=		MemCheck (valgrind) plugin
MEMCHK_RUN_DEPENDS=	${LOCALBASE}/bin/valgrind:devel/valgrind
HELP_DESC=		Help plugin
HELP_RUN_DEPENDS=	${LOCALBASE}/bin/zeal:devel/zeal
QMAKE_DESC=		QT5 qmake plugin
QMAKE_RUN_DEPENDS=	${LOCALBASE}/lib/qt5/bin/qmake:devel/qt5-qmake
SFTP_DESC=		Secure FTP support via libssh
SFTP_LIB_DEPENDS=	libssh.so:security/libssh
SFTP_CMAKE_OFF=		-DENABLE_SFTP=0
SPELLCHK_DESC=		Spell checker plugin
SPELLCHK_LIB_DEPENDS+=	libhunspell-1.7.so:textproc/hunspell
SVN_DESC=		Subversion support
SVN_RUN_DEPENDS=	${LOCALBASE}/bin/svn:devel/subversion

CLANG_DESC=		Clang code-completion

.for v in 15 16 17 18 19
OPTIONS_RADIO_CLANG+=	CLANG$v
CLANG$v_DESC=		Clang ${v:C/(.)(.)/\1.\2.x/}
CLANG$v_BUILD_DEPENDS=	llvm$v>0:devel/llvm$v
CLANG$v_RUN_DEPENDS=	llvm$v>0:devel/llvm$v

post-patch-CLANG$v-on:
	@${REINPLACE_CMD} -e \
		's|/usr/lib/llvm-.*/|${LOCALBASE}/llvm$v/|' \
		${WRKSRC}/cmake/Modules/FindLibClang.cmake \
		${WRKSRC}/cmake/Modules/FindLibLLDB.cmake
.endfor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLANG*}
CMAKE_ARGS+=	-DENABLE_LLDB:STRING=1 -DENABLE_CLANG:STRING=1
.else
CMAKE_ARGS+=	-DENABLE_LLDB:STRING=0 -DENABLE_CLANG:STRING=0
.endif

post-patch:
	@${REINPLACE_CMD} -i .orig -e \
		's|.* -O2").*|| ; \
		 s|.*"-s").*|| ; \
		 s|.* -s").*||' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|share/man|man|' \
		${WRKSRC}/LiteEditor/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|cmake_minimum_required(VERSION .*|cmake_minimum_required(VERSION 3.10)|' \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/cc-wrapper/CMakeLists.txt \
		${WRKSRC}/cc-wrapper/tinyjson/CMakeLists.txt \
		${WRKSRC}/cmake/Modules/OSXInstall.cmake \
		${WRKSRC}/yaml-cpp/CMakeLists.txt \
		${WRKSRC}/wxdap/dap/CMakeLists.txt
	# Revert: 4e270fb42bd8b1a8f5fc72817cda9005e8ea44e4
	# Use sh instead of bash.
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/cmake/Modules/UtilsHelper.cmake \
		${WRKSRC}/CodeLite/clConsoleBash.cpp \
		${WRKSRC}/CodeLite/clConsoleGnomeTerminal.cpp \
		${WRKSRC}/CodeLite/clConsoleRXVTerminal.cpp \
		${WRKSRC}/CodeLite/fileextmanager.cpp \
		${WRKSRC}/CodeLite/fileutils.cpp \
		${WRKSRC}/CodeLite/TerminalEmulator.cpp \
		${WRKSRC}/CodeLite/ssh/clSSHChannelCommon.cpp \
		${WRKSRC}/Docker/clDockerDriver.cpp \
		${WRKSRC}/Plugin/clRemoteBuilder.cpp \
		${WRKSRC}/Plugin/consolefinder.cpp \
		${WRKSRC}/Plugin/custombuildrequest.cpp \
		${WRKSRC}/Plugin/globals.cpp \
		${WRKSRC}/Plugin/pipedprocess.cpp \
		${WRKSRC}/Plugin/wxterminal.cpp \
		${WRKSRC}/Remoty/RemotyWorkspace.cpp
	# Iconv search fix.
	@${REINPLACE_CMD} -e 's|Iconv|iconv|g' \
		${WRKSRC}/ctags/CMakeLists.txt
	# Fix CPPCheck crash.
	@${REINPLACE_CMD} -e 's|eventStarted.SetToolchain.*||g' \
		${WRKSRC}/cppchecker/cppchecker.cpp
	# LLVM search fix.
	@${REINPLACE_CMD} -e 's|/usr/lib/llvm-|${PREFIX}/llvm|g' \
		${WRKSRC}/cmake/Modules/FindLibLLDB.cmake
	# LLDB fix, optional.
	#@${REINPLACE_CMD} -e 's|.*Exists(lldbDebugServer).*|if (0) {|g' \
	#	${WRKSRC}/LLDBDebugger/codelite-lldb/CodeLiteLLDBApp.cpp

post-patch-CALLGRAPH-off:
	@${REINPLACE_CMD} -e \
		's|add_subdirectory(CallGraph)||' \
		${WRKSRC}/CMakeLists.txt

post-patch-CMAKE-off:
	@${REINPLACE_CMD} -e \
		's|add_subdirectory(CMakePlugin)||' \
		${WRKSRC}/CMakeLists.txt

post-patch-CSCOPE-off:
	@${REINPLACE_CMD} -e \
		's|add_subdirectory(cscope)||' \
		${WRKSRC}/CMakeLists.txt

post-patch-GIT-off:
	@${REINPLACE_CMD} -e \
		's|add_subdirectory(git)||' \
		${WRKSRC}/CMakeLists.txt

post-patch-MEMCHK-off:
	@${REINPLACE_CMD} -e \
		's|add_subdirectory(MemCheck)||' \
		${WRKSRC}/CMakeLists.txt

post-patch-HELP-off:
	@${REINPLACE_CMD} -e \
		's|add_subdirectory(HelpPlugin)||' \
		${WRKSRC}/CMakeLists.txt

post-patch-QMAKE-off:
	@${REINPLACE_CMD} -e \
		's|add_subdirectory(QmakePlugin)||' \
		${WRKSRC}/CMakeLists.txt

post-patch-SPELLCHK-off:
	@${REINPLACE_CMD} -e \
		's|add_subdirectory(SpellChecker)||' \
		${WRKSRC}/CMakeLists.txt

post-patch-SVN-off:
	@${REINPLACE_CMD} -e \
		's|add_subdirectory(Subversion2)||' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${RM} -f ${STAGEDIR}${PREFIX}/share/codelite/clang-tools.tgz

add-plist-post:
	# Regenerate .PLIST.pymodtemp to get all installed files from
	# ${STAGEDIR}.
	@${FIND} ${STAGEDIR} -type f -o -type l | \
		${SORT} -u | ${SED} -e 's|${STAGEDIR}||' \
		> ${WRKDIR}/.PLIST.mktmp

.include <bsd.port.mk>
