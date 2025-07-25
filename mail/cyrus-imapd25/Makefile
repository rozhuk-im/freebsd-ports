PORTNAME=	cyrus-imapd
PORTVERSION=	2.5.17
PORTREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	https://github.com/cyrusimap/cyrus-imapd/releases/download/${PORTNAME}-${PORTVERSION}/
PKGNAMESUFFIX=	25

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Cyrus mail server, supporting POP3 and IMAP4 protocols
WWW=		https://www.cyrusimap.org/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		fails to build: ./tools/config2header: Error code 1
BROKEN_armv7=		fails to build: ./tools/config2header: Error code 1
BROKEN_riscv64=		fails to build: lib/imapopts.c: Error 1

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2 \
		libpcre.so:devel/pcre

CONFLICTS_INSTALL=	cyrus-imapd2? cyrus-imapd3? cyrus-imapd3?-http

USES=		cpe libtool perl5 ssl
USE_RC_SUBR=	imapd
CYRUS_PREFIX=	${PREFIX}/cyrus
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-cyrus-prefix=${CYRUS_PREFIX} \
		--with-cyrus-user=${CYRUS_USER} \
		--with-cyrus-group=${CYRUS_GROUP} \
		--with-sasl=${LOCALBASE} \
		--with-bdb=${BDB_LIB_NAME} \
		--with-com_err \
		--with-openssl=${OPENSSLBASE} \
		--with-perl=${PERL}
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes

CPE_VENDOR=	cmu
CPE_PRODUCT=	cyrus_imap_server

OPTIONS_DEFINE=		AUTOCREATE BDB CLAMAV HTTP IDLED LDAP MURDER MYSQL \
			NETSCAPEHACK NNTP PGSQL REPLICATION SNMP SQLITE DOCS \
			EXAMPLES
OPTIONS_DEFAULT=	IDLED
OPTIONS_SUB=		yes
AUTOCREATE_DESC=	Enable autocreate support
AUTOCREATE_CONFIGURE_ENABLE=	autocreate
BDB_USES=		bdb
BDB_CONFIGURE_ON=	--with-bdb-incdir=${BDB_INCLUDE_DIR} \
			--with-bdb-libdir=${LOCALBASE}/lib
CLAMAV_DESC=		Use ClamAV
CLAMAV_CONFIGURE_WITH=	clamav
CLAMAV_LIB_DEPENDS=	libclamav.so:security/clamav
HTTP_DESC=		Enable HTTP (beta quality)
HTTP_CONFIGURE_ENABLE=	http
HTTP_LIB_DEPENDS=	libjansson.so:devel/jansson \
			libical.so:devel/libical
HTTP_USES=		gnome pkgconfig
HTTP_USE=		GNOME=libxml2
IDLED_DESC=		Enable IMAP idled support
IDLED_CONFIGURE_ENABLE=	idled
LDAP_DESC=		Enable LDAP support (experimental)
LDAP_USES=		ldap
LDAP_CONFIGURE_ON=	--with-ldap=${LOCALBASE}
MURDER_DESC=		Enable IMAP Murder support
MURDER_CONFIGURE_ENABLE=murder
MURDER_MAKE_ENV=	PTHREAD_LIBS="-lpthread"
MYSQL_USES=		mysql
MYSQL_CONFIGURE_ON=	--with-mysql=yes \
			--with-mysql-libdir=${LOCALBASE}/lib/mysql \
			--with-mysql-incdir=${LOCALBASE}/include/mysql
NETSCAPEHACK_DESC=	Enable X-NETSCAPE extensions
NETSCAPEHACK_CONFIGURE_ENABLE=netscapehack
NNTP_DESC=		Enable NNTP support
NNTP_CONFIGURE_ENABLE=	nntp
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
REPLICATION_DESC=	Enable replication (experimental)
REPLICATION_CONFIGURE_ENABLE=replication
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_ON=	--with-snmp=${LOCALBASE}
SNMP_CONFIGURE_OFF=	--with-snmp=no
SQLITE_CONFIGURE_ON=	--with-sqlite=${LOCALBASE}

OPTIONS_RADIO=			GSSAPI
OPTIONS_RADIO_GSSAPI=		GSSAPI_HEIMDAL GSSAPI_MIT
.if exists(/usr/lib/libkrb5.a)
OPTIONS_RADIO_GSSAPI+=		GSSAPI_BASE
OPTIONS_DEFAULT+=		GSSAPI_BASE
.endif
GSSAPI_BASE_USES=		gssapi
GSSAPI_BASE_CONFIGURE_ON=	--enable-gssapi="${GSSAPIBASEDIR}"
.if exists(/usr/libexec/krb5kdc)
GSSAPI_BASE_CONFIGURE_ON+=	--with-gss_impl=mit
.else
GSSAPI_BASE_CONFIGURE_ON+=	--with-gss_impl=heimdal
.endif
GSSAPI_HEIMDAL_USES=		gssapi:heimdal,flags
GSSAPI_HEIMDAL_CONFIGURE_ON=	--enable-gssapi="${GSSAPIBASEDIR}" \
				--with-gss_impl=heimdal
GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--enable-gssapi="${GSSAPIBASEDIR}" \
				--with-gss_impl=mit

MANDIRS=	${CYRUS_PREFIX}/man

PORTDOCS=	*

SUB_FILES=	pkg-message pkg-install pkg-deinstall cyrus-imapd-man.conf

SUB_LIST=	CYRUS_USER=${CYRUS_USER} CYRUS_GROUP=${CYRUS_GROUP}

CYRUS_USER?=	cyrus
CYRUS_GROUP?=	cyrus

MAN_MAN1=	imtest installsieve lmtptest mupdatetest nntptest pop3test \
		sieveshell sivtest smtptest
MAN_MAN3=	imclient
MAN_MAN5=	cyrus.conf imapd.conf krb.equiv

CYRUS_MAN8=	arbitron chk_cyrus ctl_cyrusdb ctl_deliver ctl_mboxlist \
		cvt_cyrusdb cyr_dbtool cyr_deny cyr_df cyr_expire cyr_info \
		cyr_synclog deliver fud idled imapd ipurge lmtpd master \
		mbexamine mbpath notifyd pop3d quota reconstruct rmnews \
		smmapd squatter sync_client sync_reset sync_server timsieved \
		tls_prune unexpunge

CYRUS_PERL_MAN1=cyradm
CYRUS_PERL_MAN3=Cyrus::Annotator::Daemon Cyrus::Annotator::Message \
		Cyrus::IMAP Cyrus::IMAP::Admin Cyrus::IMAP::IMSP \
		Cyrus::IMAP::Shell Cyrus::SIEVE::managesieve

CONFS=		cmu-backend.conf cmu-frontend.conf normal.conf prefork.conf \
		small.conf

.include <bsd.port.options.mk>

.if empty(${PORT_OPTIONS:MBDB})
BDB_LIB_NAME=	no
.endif

PLIST_SUB+=	CLAMAV="@comment "

.if ${PORT_OPTIONS:MHTTP} || ${PORT_OPTIONS:MSQLITE}
USES+=	sqlite
.endif

.if !${PORT_OPTIONS:MGSSAPI_BASE} && !${PORT_OPTIONS:MGSSAPI_HEIMDAL} && \
    !${PORT_OPTIONS:MGSSAPI_MIT}
CONFIGURE_ARGS+=--disable-gssapi
.endif

.if ${PORT_OPTIONS:MHTTP}
CYRUS_MAN8+=	ctl_zoneinfo httpd
.endif
.if ${PORT_OPTIONS:MNNTP}
CYRUS_MAN8+=	fetchnews nntpd
.endif

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" \
			  -e "s|%%CYRUS_USER%%|${CYRUS_USER}|g" \
			  -e "s|%%CYRUS_GROUP%%|${CYRUS_GROUP}|g" \
		${WRKSRC}/tools/mkimap
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|g" \
			  -e "s|/usr/sieve|/var/imap/sieve|g" \
		${WRKSRC}/tools/masssievec
	@${REINPLACE_CMD} \
		-e 's|$$(libdir)/\(pkgconfig\)|${PREFIX}/libdata/\1|g' \
		-e 's|$$(mandir)/\(man[8]\)|${PREFIX}/cyrus/man/\1|g' \
		${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/imapd.conf \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/master/conf/normal.conf \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap \
		${STAGEDIR}${CYRUS_PREFIX}/bin/mkimap
	${INSTALL_SCRIPT} ${WRKSRC}/tools/masssievec \
		${STAGEDIR}${CYRUS_PREFIX}/bin/masssievec
	${INSTALL_DATA} ${WRKDIR}/cyrus-imapd-man.conf \
		${STAGEDIR}${PREFIX}/etc/man.d/cyrus-imapd.conf
.for s in 1 3 5
.  for m in ${MAN_MAN${s}}
	@${ECHO_CMD} share/man/man${s}/${m}.${s}.gz >> ${TMPPLIST}
.  endfor
.endfor
.for s in 1 3
.  for m in ${CYRUS_PERL_MAN${s}}
	@${ECHO_CMD} ${SITE_MAN${s}}/${m}.${s}.gz >> ${TMPPLIST}
.  endfor
.endfor
.for m in ${CYRUS_MAN8}
	@${ECHO_CMD} ${CYRUS_PREFIX}/man/man8/${m}.8.gz >> ${TMPPLIST}
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

# there are already files in EXAMPLESDIR at that point, so no
# need to create it.
post-install-EXAMPLES-on:
.for f in ${CONFS:Nnormal.conf}
	${INSTALL_DATA} ${WRKSRC}/master/conf/${f} \
		${STAGEDIR}${EXAMPLESDIR}
	@${ECHO_CMD} ${EXAMPLESDIR:S,^${PREFIX}/,,}/${f} >>${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
