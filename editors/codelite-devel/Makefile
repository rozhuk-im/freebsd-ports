# $FreeBSD$

PORTNAME=	codelite
PORTVERSION=	14.0.5.20201223
PORTREVISION=	0
CATEGORIES=	editors devel
PKGNAMESUFFIX=	-devel

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Open Source IDE for C/C++

LICENSE=	GPLv2+

RUN_DEPENDS=	${LOCALBASE}/bin/open:sysutils/open
LIB_DEPENDS=	libuchardet.so:textproc/uchardet

# dos2unix
USES=		cmake:noninja compiler:c++11-lib gettext gnome \
		localbase pathfix pkgconfig shebangfix sqlite
USE_GNOME=	cairo glib20 gtk30
#DOS2UNIX_GLOB=	*.cpp *.txt
SHEBANG_FILES=	Runtime/codelite_xterm
USE_WX=		3.1
USE_GITHUB=	yes
GH_ACCOUNT=	eranif
GH_TAGNAME=	33ef275c64551a0fc089f75ad7b08019c23ed4d9
CMAKE_ARGS=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DPREFIX:STRING="${PREFIX}" \
		-DIS_FREEBSD:STRING=1 \
		-DGTK_USE_CUSTOMBOOK:STRING=1 \
		-DCL_WX_CONFIG:STRING="${WX_CONFIG:T}"
USE_LDCONFIG=	${PREFIX}/lib/codelite
INSTALLS_ICONS=	yes
CFLAGS+=	-DNDEBUG
LDFLAGS+=	-lutil

OPTIONS_RADIO=		CLANG
OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	CALLGRAPH CMAKE CSCOPE GIT HELP MEMCHK \
			QMAKE SFTP SPELLCHK SVN
OPTIONS_DEFAULT=	GIT
OPTIONS_SUB=		yes

CALLGRAPH_DESC=		CallGraph plugin
CALLGRAPH_RUN_DEPENDS=	${LOCALBASE}/bin/dot:graphics/graphviz
CMAKE_DESC=		CMake plugin
CMAKE_RUN_DEPENDS=	${LOCALBASE}/bin/cmake:devel/cmake
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
SFTP_CMAKE_OFF=		-DENABLE_SFTP:STRING=0
SPELLCHK_DESC=		Spell checker plugin
SPELLCHK_LIB_DEPENDS+=	libhunspell-1.7.so:textproc/hunspell
SVN_DESC=		Subversion support
SVN_RUN_DEPENDS=	${LOCALBASE}/bin/svn:devel/subversion

CLANG_DESC=		Clang code-completion

.for v in 80 90 10 11 12
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
	# Use the correct wx-config
	@${REINPLACE_CMD} -e \
		'/ IS_FREEBSD/s|^|#| ; \
		 / CL_WX_CONFIG/s|^|#| ; \
		 / -Wno-/s|^|#| ; \
		 / -O2/s|^|#| ; \
		 s|"-s"|""|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|share/man|man|' \
		${WRKSRC}/LiteEditor/CMakeLists.txt
	@${REINPLACE_CMD} -e '/ADDITIONAL_LIBRARIES/s|""|"-lexecinfo"|' \
		${WRKSRC}/sdk/codelite_cppcheck/CMakeLists.txt
	# https://github.com/eranif/codelite/issues/2498
	@${REINPLACE_CMD} -e 's|libcodelite|libcodelite gobject-2.0|g' \
		${WRKSRC}/codelitephp/CMakeLists.txt
	# Revert: 4e270fb42bd8b1a8f5fc72817cda9005e8ea44e4
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/CodeLite/TerminalEmulator.cpp \
		${WRKSRC}/CodeLite/clConsoleBash.cpp \
		${WRKSRC}/CodeLite/clConsoleGnomeTerminal.cpp \
		${WRKSRC}/CodeLite/clConsoleRXVTerminal.cpp \
		${WRKSRC}/CodeLite/fileextmanager.cpp \
		${WRKSRC}/CodeLite/fileutils.cpp \
		${WRKSRC}/Docker/clDockerDriver.cpp \
		${WRKSRC}/Plugin/clRemoteBuilder.cpp \
		${WRKSRC}/Plugin/consolefinder.cpp \
		${WRKSRC}/Plugin/custombuildrequest.cpp \
		${WRKSRC}/Plugin/globals.cpp \
		${WRKSRC}/Plugin/pipedprocess.cpp \
		${WRKSRC}/Plugin/wxterminal.cpp \
		${WRKSRC}/codelite_terminal/wxTerminalCtrl.cpp
	# LLDB fix, optional.
	@${REINPLACE_CMD} -e 's|.*Exists(lldbDebugServer).*|if (0) {|g' \
		${WRKSRC}/LLDBDebugger/codelite-lldb/CodeLiteLLDBApp.cpp

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

.include <bsd.port.mk>
