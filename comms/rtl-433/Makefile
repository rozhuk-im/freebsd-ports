# $FreeBSD$

PORTNAME=	rtl-433
PORTVERSION=	20.02
CATEGORIES=	comms hamradio

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Generic data receiver

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librtlsdr.so:comms/rtl-sdr

USES=		cmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	merbanan
GH_PROJECT=	rtl_433

CMAKE_ON=	ENABLE_RTLSDR
CMAKE_OFF=	BUILD_DOCUMENTATION \
		ENABLE_SOAPYSDR \
		BUILD_TESTING_ANALYZER \
		BUILD_TESTING

post-patch:
	@${REINPLACE_CMD} -e 's|.*GetGitRevisionDescription.*||g' \
		-e 's|.*get_git_head_revision.*||g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
