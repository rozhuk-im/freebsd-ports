PORTNAME=	homeassistant
PORTVERSION=	2025.11.3
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Open-source home automation platform running on Python 3

LICENSE=	APACHE20

# Packed into venv during build.
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv>=0:devel/py-uv@${PY_FLAVOR}
# Real run deps.
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg
# VENV bootstrap deps.
RUN_DEPENDS+=	cmake:devel/cmake-core \
		gmake:devel/gmake \
		ninja:devel/ninja \
		pkg-config:devel/pkgconf \
		rustc:lang/rust \
		uv:devel/uv
LIB_DEPENDS=	libturbojpeg.so:graphics/libjpeg-turbo

USES=		python:3.13+

USE_GITHUB=	yes
GH_ACCOUNT=	home-assistant
GH_PROJECT=	core

USE_RC_SUBR=	home-assistant
USERS=		homeassistant
GROUPS=		homeassistant

MAKEDIST_VENV=${WRKDIR}/venv
MAKEDIST_ENV=	HOME=${MAKEDIST_VENV} \
		XDG_CACHE_HOME=${MAKEDIST_VENV}/.cache \
		VIRTUAL_ENV=${MAKEDIST_VENV}/ \
		PATH=${MAKEDIST_VENV}/bin/:${PATH} \
		CPUCOUNT=${MAKE_JOBS_NUMBER} \
		MAKEFLAGS=-j${MAKE_JOBS_NUMBER}

BINARY_ALIAS=	make=gmake

SUB_LIST=	PYTHON_VERSION=${PYTHON_VERSION}

OPTIONS_GROUP=	DB
OPTIONS_GROUP_DB=	MSSQL MYSQL PYMYSQL PGSQL

MSSQL_PYPKG=		pymssql
MYSQL_PYPKG=		mysqlclient
PYMYSQL_PYPKG=		pymysql
PGSQL_PYPKG=		psycopg2
MYSQL_DESC=		MySQL/MariaDB support
PYMYSQL_DESC=		MySQL/MariaDB support via pymysql

.include <bsd.port.pre.mk>

post-patch:
	# Disable uv build+install inside venv.
	@${REINPLACE_CMD} -e 's|.*uv==.*||g' \
		${WRKSRC}/pyproject.toml \
		${WRKSRC}/requirements.txt \
		${WRKSRC}/homeassistant/package_constraints.txt
	# Hack to avoid build fail pycares==5.0.0
	@${REINPLACE_CMD} -e 's|aiodns==3.5.0|aiodns==3.6.1|g' \
		${WRKSRC}/pyproject.toml \
		${WRKSRC}/requirements.txt \
		${WRKSRC}/homeassistant/package_constraints.txt \
		${WRKSRC}/homeassistant/components/dnsip/manifest.json
	# Enable FreeBSD support.
	@${REINPLACE_CMD} -e 's|("darwin", "linux")|("darwin", "linux", "freebsd")|g' \
		${WRKSRC}/homeassistant/__main__.py
	# Cleanup.
	@${FIND} ${WRKSRC} -type f \( \
		-name '*.orig' \
		-o -name '*.bak' \
		-o -name '.gitignore' \) -delete

do-build:
	@${PYTHON_CMD} -m venv "${MAKEDIST_VENV}"
	@${MKDIR}	"${MAKEDIST_VENV}/.cache" \
			"${MAKEDIST_VENV}/bin/" \
			"${MAKEDIST_VENV}/lib/${PYTHON_VERSION}/lib-dynload/" \
			"${MAKEDIST_VENV}/lib/${PYTHON_VERSION}/site-packages/"
	# ccache.
	@${LN} -sf "${WRKDIR}/.ccache" "${MAKEDIST_VENV}/.cache/ccache"
	# _sqlite3 hack to avoid --system-site-packages.
	@${CP} -af ${LOCALBASE}/lib/${PYTHON_VERSION}/lib-dynload/*sqlite3*.so "${MAKEDIST_VENV}/lib/${PYTHON_VERSION}/lib-dynload/"
	@${CP} -af ${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/*sqlite3*.so "${MAKEDIST_VENV}/lib/${PYTHON_VERSION}/site-packages/"
	# uv hack to avoid --system-site-packages.
	@${CP} -af ${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/uv "${MAKEDIST_VENV}/lib/${PYTHON_VERSION}/site-packages/"
	@${CP} -af ${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/uv-* "${MAKEDIST_VENV}/lib/${PYTHON_VERSION}/site-packages/"
	# PyNaCl build hack.
	@${LN} -sf '${LOCALBASE}/bin/gmake' "${MAKEDIST_VENV}/bin/make"
	# Install deps.
	# https://github.com/home-assistant/core/blob/dev/.github/workflows/builder.yml
	@${SETENV} ${MAKEDIST_ENV} uv --native-tls --color never --cache-dir ${MAKEDIST_VENV}/.cache/uv/ pip install packaging tomli numpy
	# Hack to avoid build fail pycares==5.0.0
	@${SETENV} ${MAKEDIST_ENV} uv --native-tls --color never --cache-dir ${MAKEDIST_VENV}/.cache/uv/ pip install aiodns==3.6.1 pycares==4.11.0
	@${SETENV} ${MAKEDIST_ENV} uv --native-tls --color never --cache-dir ${MAKEDIST_VENV}/.cache/uv/ --directory ${WRKSRC} pip install .
	# Install selected DB plugins.
.for _opt in ${OPTIONS_GROUP_DB}
.  if ${PORT_OPTIONS:M${_opt}}
	@${SETENV} ${MAKEDIST_ENV} uv --native-tls --color never --cache-dir ${MAKEDIST_VENV}/.cache/uv/ pip install ${${_opt}_PYPKG}
.  endif
.endfor
	# patch pyvenv.cfg
	@${REINPLACE_CMD} -e "s|${MAKEDIST_VENV}|${STAGEDIR}/var/db/homeassistant/|g" \
		${MAKEDIST_VENV}/pyvenv.cfg
	@${RM} -f "${MAKEDIST_VENV}/pyvenv.cfg.bak"

do-install:
	@${RM} -rf "${MAKEDIST_VENV}/.cache"
	@${RM} -rf "${MAKEDIST_VENV}/.cargo"
	@${MKDIR} ${STAGEDIR}/var/db/homeassistant
	@${MV} ${MAKEDIST_VENV} ${STAGEDIR}/var/db/homeassistant/

post-stage:
	# Generate plist.
	@${SETENV} ${CO_ENV} ${SH} ${SCRIPTSDIR}/check-stagedir.sh makeplist | \
		${GREP} -v '/you/have/to/check/what/makeplist/gives/you' | \
		${SED} -e 's|%%PYTHON_INCLUDEDIR%%|include/${PYTHON_VERSION}|' \
			-e 's|%%PYTHON_TAG%%|${PYTHON_TAG}|' \
			-e 's|%%PYTHON_VER%%|${PYTHON_VER}|' \
			-e 's|%%PYTHON_VERSION%%|${PYTHON_VERSION}|' \
			-e 's|%%PYTHON_LIBDIR%%|lib/${PYTHON_VERSION}|' \
			-e 's|%%PYTHON_SITELIBDIR%%|lib/${PYTHON_VERSION}/site-packages|' \
			-e 's|%%PYTHON_EXT_SUFFIX%%|${PYTHON_EXT_SUFFIX}|' \
			> ${TMPPLIST}
	# Force perms on install.
	@${ECHO_CMD} "@postexec chown -R ${USERS}:${GROUPS} /var/db/homeassistant/venv" >> ${TMPPLIST}
	@${ECHO_CMD} "@postexec chmod -R =t,u=rwX,g=rX,o= /var/db/homeassistant/venv" >> ${TMPPLIST}
	# Deinstall+Install magic.
	@${ECHO_CMD} "@preunexec service ${USE_RC_SUBR} forcestop" >> ${TMPPLIST}
	@${ECHO_CMD} "@preexec rm -rf /var/db/homeassistant/venv" >> ${TMPPLIST}

.include <bsd.port.mk>
