PORTNAME=	timeSeries
DISTVERSION=	4041.111
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Financial Time Series Objects (Rmetrics)
WWW=		https://r-forge.r-project.org/scm/viewvc.php/pkg/timeSeries/?root=rmetrics

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-timeDate>=2150.95:finance/R-cran-timeDate
TEST_DEPENDS=	R-cran-RUnit>0:devel/R-cran-RUnit \
		R-cran-PerformanceAnalytics>0:finance/R-cran-PerformanceAnalytics \
		R-cran-robustbase>0:math/R-cran-robustbase \
		R-cran-xts>0:math/R-cran-xts

USES=		cran:auto-plist

.include <bsd.port.mk>
