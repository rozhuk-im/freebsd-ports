PORTNAME=	lhs2tex
PORTVERSION=	1.25
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Preprocessor for typesetting Haskell sources with LaTeX
WWW=		https://www.andres-loeh.de/lhs2tex/

LICENSE=	GPLv2

USES=		cabal tex
USE_CABAL=	regex-base-0.94.0.2_4 \
		regex-compat-0.95.2.1_2 \
		regex-posix-0.96.0.1_3
USE_TEX=	latex dvipsk

CABAL_EXECUTABLES=	lhs2TeX

.include <bsd.port.mk>
