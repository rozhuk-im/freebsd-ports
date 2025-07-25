PORTNAME=	docbook-utils
PORTVERSION=	0.6.14
PORTREVISION=	14
CATEGORIES=	textproc
MASTER_SITES=	SOURCEWARE/docbook-tools/new-trials/SOURCES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates various output formats from DocBook SGML documents
WWW=		https://www.sourceware.org/docbook-tools/

BUILD_DEPENDS+=	docbook-sgml>0:textproc/docbook-sgml \
		dsssl-docbook-modular>0:textproc/dsssl-docbook-modular \
		nsgmls:textproc/jade
RUN_DEPENDS+=	dsssl-docbook-modular>0:textproc/dsssl-docbook-modular \
		nsgmls:textproc/jade \
		sgmlspl:textproc/p5-SGMLSpm \
		lynx:www/lynx

CONFLICTS=	docbook2X linux-j # bin/docbook2man bin/docbook2texi bin/jw

USES=		perl5 gmake shebangfix tex
USE_PERL5=	run
USE_TEX=	jadetex

GNU_CONFIGURE=	yes
MAKE_ARGS+=	docdir="${DOCSDIR}" htmldir="${DOCSDIR}/html"
NO_ARCH=	yes
SHEBANG_FILES=	bin/sgmldiff.in
perl_OLD_CMD=	@perl_bindir@/perl

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/sgml/catalog|${PREFIX}/share/sgml/catalog|g' \
		${WRKSRC}/doc/HTML/Makefile.in
	@${REINPLACE_CMD} -e 's|/etc/sgml|${LOCALBASE}/share/sgml|g' \
			-e 's|/usr/bin/|${LOCALBASE}/bin/|g' \
			${WRKSRC}/doc/refentry/*.sgml \
			${WRKSRC}/backends/txt

pre-configure:
	${RM} ${WRKSRC}/config.cache

.include <bsd.port.mk>
