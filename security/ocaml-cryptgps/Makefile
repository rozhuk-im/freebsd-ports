PORTNAME=	cryptgps
PORTVERSION=	0.2.1
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Symmetric cryptographic algorithms package for OCaml
WWW=		https://www.ocaml-programming.de/packages/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		gmake
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes

ALL_TARGET=	all opt

PORTDOCS=	*
DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
