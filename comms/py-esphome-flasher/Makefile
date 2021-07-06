PORTNAME=	esphome-flasher
DISTVERSION=	1.4.0
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Simple GUI tool to flash ESPs over USB

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	esphome
USES=		python:3.7+
USE_PYTHON=	autoplist distutils
USE_WX=		3.2+
WX_COMPS=	python:run
DESKTOP_ENTRIES="ESPHome-Flasher" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
		"esphomeflasher" "" true
PLIST_FILES=	${PREFIX}/share/pixmaps/${PORTNAME}.ico

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}esptool>=3.2:comms/py-esptool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25.1:www/py-requests@${PY_FLAVOR}

post-patch:
.for __RUN_DEPEND in ${RUN_DEPENDS}
	@${ECHO} -n "${__RUN_DEPEND:C/(.*)(>|<|==|>=|<=).*/\1/}: "
	@${GREP} -E "^${__RUN_DEPEND:C/(.*)(>|<|==|>=|<=).*/\1/}(>|<|==|>=|<=)" \
	    ${WRKSRC}/requirements.txt | \
		${SED} -E "s/${__RUN_DEPEND:C/(.*)(>|<|==|>=|<=).*/\1/}(>|<|==|>=|<=)([.0-9]*)/\2/g" | \
		    ${TR} -cd '[:print:]'
	@${ECHO} " -> ${__RUN_DEPEND:C/.*(>|<|==|>=|<=)(.*)[:].*/\2/}"

	@${REINPLACE_CMD} -E \
		-e "s/(^|\")${__RUN_DEPEND:C/(.*)(>|<|==|>=|<=).*/\1/}(>|<|==|>=|<=)[.0-9]*/\1${__RUN_DEPEND:C/(.*)(>|<|==|>=|<=).*/\1/}>=${__RUN_DEPEND:C/.*(>|<|==|>=|<=)(.*)[:].*/\2/}/g" \
		${WRKSRC}/setup.py \
		${WRKSRC}/requirements.txt
.endfor
	# Show all serial ports.
	@${REINPLACE_CMD} -e 's| or "VID:PID" not in info||g' \
		${WRKSRC}/esphomeflasher/helpers.py
	# Patch for 4x esptool.
	@${REINPLACE_CMD} -e 's|esptool.ESPLoader.detect_chip|esptool.cmds.detect_chip|g' \
		-e 's|esptool.DETECTED_FLASH_SIZES.get|esptool.cmds.DETECTED_FLASH_SIZES.get|g' \
		${WRKSRC}/esphomeflasher/common.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/icon.ico \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.ico

.include <bsd.port.mk>
