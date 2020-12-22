PORTNAME=	homeassistant
PORTVERSION=	2024.1.3
CATEGORIES=	www python
MASTER_SITES=	
DISTFILES=	
EXTRACT_ONLY=	# nothing to extract
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Open-source home automation platform running on Python 3

LICENSE=	APACHE20

# Real run deps.
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}
# VENV bootstrap deps.
RUN_DEPENDS+=	cmake:devel/cmake-core \
		ninja:devel/ninja \
		pkg-config:devel/pkgconf \
		rustc:lang/rust

USES=		python:3.11+
USE_RC_SUBR=	home-assistant

USERS=		homeassistant
GROUPS=		homeassistant

SUB_LIST=	PORTVERSION=${PORTVERSION} \
		PYTHON_CMD=${PYTHON_CMD} \
		PYTHON_VERSION=${PYTHON_VERSION}

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS_GROUP=	DB
OPTIONS_GROUP_DB=	MSSQL MYSQL PYMYSQL PGSQL

MSSQL_SUB_LIST=		MSSQLCLIENT=pymssql
MSSQL_SUB_LIST_OFF=	MSSQLCLIENT=""
MYSQL_SUB_LIST=		MYSQLCLIENT=mysqlclient
MYSQL_SUB_LIST_OFF=	MYSQLCLIENT=""
PYMYSQL_SUB_LIST=	PYMYSQLCLIENT=pymysql
PYMYSQL_SUB_LIST_OFF=	PYMYSQLCLIENT=""
PGSQL_SUB_LIST=		PGSQLCLIENT=psycopg2
PGSQL_SUB_LIST_OFF=	PGSQLCLIENT=""

MYSQL_DESC=	MySQL/MariaDB support
PYMYSQL_DESC=	MySQL/MariaDB support via pymysql

do-install:
	@${MKDIR} ${STAGEDIR}/var/db/homeassistant

post-stage:
	@${ECHO_CMD} "@dir(homeassistant,homeassistant,) /var/db/homeassistant" >> ${TMPPLIST}
	# Generate plist.
	@${SETENV} ${CO_ENV} ${SH} ${SCRIPTSDIR}/check-stagedir.sh makeplist | \
		${GREP} -v ^\/ | \
		${SED} -e 's|%%PYTHON_SITELIBDIR%%|${PYTHONPREFIX_SITELIBDIR}|' \
			-e 's|%%PYTHON_EXT_SUFFIX%%|${PYTHON_EXT_SUFFIX}|' \
			> ${TMPPLIST}

.include <bsd.port.mk>
