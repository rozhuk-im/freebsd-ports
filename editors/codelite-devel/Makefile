PORTNAME=	codelite
PORTVERSION=	18.2.0.20251209
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
		localbase lua:54 pathfix pkgconfig python:build shebangfix sqlite
USE_GNOME=	cairo glib20 gtk30
DOS2UNIX_GLOB=	*.cpp *.txt
SHEBANG_FILES=	codelite_open_helper.py \
		Runtime/codelite-remote \
		Runtime/codelite_xterm
USE_WX=		3.2
CFLAGS+=	-fPIC -I${LUA_INCDIR}
LDFLAGS+=       -L${LUA_LIBDIR} -llua-${LUA_VER} -lgobject-2.0

USE_GITHUB=	yes
GH_ACCOUNT=	eranif:DEFAULT \
		eranif:assistant \
		DaveGamble:cjson \
		eranif:ctags \
		cubicdaiya:dtl \
		eranif:lexilla \
		eranif:luabridge \
		eranif:tinyjson \
		eranif:wxdap \
		eranif:wxsfcode \
		jbeder:yamlcpp
GH_PROJECT=	codelite:DEFAULT \
		assistant:assistant \
		cc-wrapper:ccwrapper \
		cJSON:cjson \
		ctags:ctags \
		dtl:dtl \
		lexilla:lexilla \
		LuaBridge:luabridge \
		tinyjson:tinyjson \
		wxdap:wxdap \
		wxsf-code:wxsfcode \
		yaml-cpp:yamlcpp
GH_TAGNAME=	32e64b0af3a9c22165eeadcb29d34f508328aae1:DEFAULT \
		2ff677d4b28908e66400adddc799b6d5d932d1c9:assistant \
		53464674ff2c287dfd68f05030d1d79e02d4974c:ccwrapper \
		fd1ac4f1791b403af1f7350b1195ac114f9b792b:cjson \
		ac5c942b422ca6dc6cdbfd2a0c2d481af1f18f02:ctags \
		32567bb9ec704f09040fb1ed7431a3d967e3df03:dtl \
		8502988a5eb83fcd281ee5a38533a9f170e6b2bf:lexilla \
		a78d4f1469890eb4e795709848ebf57b002ad369:luabridge \
		d51ef6fc646d60c1400ebde767ebfdd2b7361482:tinyjson \
		e390b824ba0ab29e7665229f84f9fa44e8bef468:wxdap \
		b5dc09a9b94b9955ef98111d0f311cb43f32f649:wxsfcode \
		2f86d13775d119edbb69af52e5f566fd65c6953b:yamlcpp
GH_SUBDIR=	submodules/assistant:assistant \
		submodules/cJSON:cjson \
		submodules/ctags:ctags \
		submodules/cc-wrapper:ccwrapper \
		submodules/dtl:dtl \
		submodules/lexilla:lexilla \
		submodules/LuaBridge:luabridge \
		submodules/cc-wrapper/tinyjson:tinyjson \
		submodules/wxdap:wxdap \
		submodules/wxsf-code:wxsfcode \
		submodules/yaml-cpp:yamlcpp

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

.for v in 15 16 17 18 19 20 21
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
		${WRKSRC}/submodules/cc-wrapper/CMakeLists.txt \
		${WRKSRC}/submodules/cc-wrapper/tinyjson/CMakeLists.txt \
		${WRKSRC}/cmake/Modules/OSXInstall.cmake \
		${WRKSRC}/submodules/yaml-cpp/CMakeLists.txt \
		${WRKSRC}/submodules/wxdap/dap/CMakeLists.txt
	# Revert: 4e270fb42bd8b1a8f5fc72817cda9005e8ea44e4
	# Use sh instead of bash.
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/cmake/Modules/UtilsHelper.cmake \
		${WRKSRC}/CodeLite/AsyncProcess/TerminalEmulator.cpp \
		${WRKSRC}/CodeLite/Console/clConsoleBash.cpp \
		${WRKSRC}/CodeLite/Console/clConsoleGnomeTerminal.cpp \
		${WRKSRC}/CodeLite/Console/clConsoleRXVTerminal.cpp \
		${WRKSRC}/CodeLite/fileextmanager.cpp \
		${WRKSRC}/CodeLite/fileutils.cpp \
		${WRKSRC}/CodeLite/ssh/clSSHChannelCommon.cpp \
		${WRKSRC}/Docker/clDockerDriver.cpp \
		${WRKSRC}/Plugin/consolefinder.cpp \
		${WRKSRC}/Plugin/custombuildrequest.cpp \
		${WRKSRC}/Plugin/globals.cpp \
		${WRKSRC}/Plugin/pipedprocess.cpp \
		${WRKSRC}/Plugin/wxterminal.cpp \
		${WRKSRC}/Remoty/RemotyWorkspace.cpp
	# Iconv search fix.
	@${REINPLACE_CMD} -e 's|Iconv|iconv|g' \
		${WRKSRC}/submodules/ctags/CMakeLists.txt
	# Fix CPPCheck crash.
	@${REINPLACE_CMD} -e 's|eventStarted.SetToolchain.*||g' \
		${WRKSRC}/cppchecker/cppchecker.cpp
	# LUA from system.
	@${REINPLACE_CMD} -e 's|lualib||g' \
		${WRKSRC}/Plugin/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|add_subdirectory(lua)||g' \
		${WRKSRC}/submodules/CMakeLists.txt
	# LLVM search fix.
	@${REINPLACE_CMD} -e 's|/usr/lib/llvm-|${PREFIX}/llvm|g' \
		${WRKSRC}/cmake/Modules/FindLibLLDB.cmake
	# LLDB fix, optional.
	#@${REINPLACE_CMD} -e 's|.*Exists(lldbDebugServer).*|if (0) {|g' \
	#	${WRKSRC}/LLDBDebugger/codelite-lldb/CodeLiteLLDBApp.cpp
	# Cleanup.
	@${MV} ${WRKSRC}/EOSWiki/resources/eoswiki.zip ${WRKSRC}/EOSWiki/resources/eoswiki.piz
	@${MV} ${WRKSRC}/Runtime/PHP.zip ${WRKSRC}/Runtime/PHP.piz
	@${MV} ${WRKSRC}/wxcrafter/wxgui.zip ${WRKSRC}/wxcrafter/wxgui.piz
	@${FIND} ${WRKSRC} -type f \( \
		-name '*.orig' \
		-o -name '*.bak' \
		-o -name '*.gz' \
		-o -name '*.exe' \
		-o -name '*.tar' \
		-o -name '*.tgz' \
		-o -name '*.zip' \
		-o -name '.gitignore' \) -delete
	@${MV} ${WRKSRC}/EOSWiki/resources/eoswiki.piz ${WRKSRC}/EOSWiki/resources/eoswiki.zip
	@${MV} ${WRKSRC}/Runtime/PHP.piz ${WRKSRC}/Runtime/PHP.zip
	@${MV} ${WRKSRC}/wxcrafter/wxgui.piz ${WRKSRC}/wxcrafter/wxgui.zip

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

add-plist-post:
	# Regenerate .PLIST.pymodtemp to get all installed files from
	# ${STAGEDIR}.
	@${FIND} ${STAGEDIR} -type f -o -type l | \
		${SORT} -u | ${SED} -e 's|${STAGEDIR}||' \
		> ${WRKDIR}/.PLIST.mktmp

.include <bsd.port.mk>
