# $FreeBSD$

PORTNAME=	homeassistant
PORTVERSION=	0.118.5
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Open-source home automation platform running on Python 3

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

# homeassistant/package_constraints.txt
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp_cors>=0.7.0:www/py-aiohttp_cors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.6.2:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}astral1>=1.10.1:astro/py-astral1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_timeout>=3.0.1:devel/py-async_timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=19.3.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=3.1.7:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2020.6.20:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ciso8601>=2.1.3:devel/py-ciso8601@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=2.9.2:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0.6.0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=1.5.0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}emoji>=0.5.0:misc/py-emoji@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.31.0:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hass-nabucasa>=0.38.0:devel/py-hass-nabucasa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}home-assistant-frontend>=20201212.0:www/py-home-assistant-frontend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.18.0:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.16.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=1.6.0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.11.2:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netdisco>=2.8.2:devel/py-netdisco@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paho-mqtt>=1.5.0:net/py-paho-mqtt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=7.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=8.0.3:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.6.6:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=1.7.1:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=1.3.0:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-slugify>=4.0.1:textproc/py-python-slugify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2020.1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.15.100:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy13>=1.3.20:databases/py-sqlalchemy13@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.24.3:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}voluptuous-serialize>=2.4.0:devel/py-voluptuous-serialize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}voluptuous>=0.12.0:devel/py-voluptuous@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.3.1:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yarl>=1.4.2:www/py-yarl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zeroconf>=0.28.5:net/py-zeroconf@${PY_FLAVOR}

# Extra deps for first start.
# requirements_all.txt
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}PyMetno>=0.8.1:devel/py-pymetno@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=1.42.0:audio/py-mutagen@${PY_FLAVOR}
#		${PYTHON_PKGNAMEPREFIX}gtts>=2.1.1:audio/py-gtts@${PY_FLAVOR}
#		${PYTHON_PKGNAMEPREFIX}gtts-token>=1.1.3:security/py-gtts-token@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}pyotp>=2.4.1:security/py-pyotp@${PY_FLAVOR}

# Plugins deps.
#RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}google-cloud-pubsub>0:devel/py-google-cloud-pubsub@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}ffmpeg-python>0:multimedia/py-ffmpeg-python@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}pycups>0:print/py-pycups@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}HATasmota>0:devel/py-hatasmota@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}temescal>0:devel/py-temescal@${PY_FLAVOR}

#
# astro/py-astral1
# devel/py-ciso8601
# devel/py-voluptuous-serialize
#
# devel/py-netdisco
# devel/py-metno-locationforecast
# devel/py-hass-nabucasa
# 

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils
USE_RC_SUBR=	homeassistant

USERS=		homeassistant
GROUPS=		homeassistant

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

NO_ARCH=	yes

OPTIONS_DEFINE=	MQTT_MOSQ
OPTIONS_DEFAULT=MQTT_MOSQ

MQTT_MOSQ_DESC=	Mosquitto MQTT broker
MQTT_MOSQ_RUN_DEPENDS=	mosquitto>=0:net/mosquitto


post-patch:
.for __RUN_DEPEND in ${RUN_DEPENDS}
	@${ECHO} -n "${__RUN_DEPEND:C/(.*)(>|<|==|>=|<=).*/\1/}: "
	@${GREP} -E "^${__RUN_DEPEND:C/(.*)(>|<|==|>=|<=).*/\1/}(>|<|==|>=|<=)" \
	    ${WRKSRC}/homeassistant/package_constraints.txt | \
		${SED} -E "s/${__RUN_DEPEND:C/(.*)(>|<|==|>=|<=).*/\1/}(>|<|==|>=|<=)([.0-9]*)/\2/g" | \
		    ${TR} -cd '[:print:]'
	@${ECHO} " -> ${__RUN_DEPEND:C/.*(>|<|==|>=|<=)(.*)[:].*/\2/}"

	@${REINPLACE_CMD} -E \
		-e "s/(^|\")${__RUN_DEPEND:C/(.*)(>|<|==|>=|<=).*/\1/}(>|<|==|>=|<=)[.0-9]*/\1${__RUN_DEPEND:C/(.*)(>|<|==|>=|<=).*/\1/}>=${__RUN_DEPEND:C/.*(>|<|==|>=|<=)(.*)[:].*/\2/}/g" \
		${WRKSRC}/setup.py \
		${WRKSRC}/homeassistant/package_constraints.txt \
		${WRKSRC}/homeassistant/auth/mfa_modules/*.py \
		${WRKSRC}/homeassistant/scripts/*.py \
		${WRKSRC}/homeassistant/components/*/manifest.json
.endfor
	# Port name did not match python packet name.
.for __RUN_DEPEND in astral jinja2 PyJWT pyyaml PyNaCl sqlalchemy
	@${REINPLACE_CMD} -E \
		-e 's/(^|\")${__RUN_DEPEND}(>|<|==|>=|<=)[.0-9]*/\1${__RUN_DEPEND}>=0/g' \
		${WRKSRC}/setup.py \
		${WRKSRC}/homeassistant/package_constraints.txt \
		${WRKSRC}/homeassistant/auth/mfa_modules/*.py \
		${WRKSRC}/homeassistant/scripts/*.py \
		${WRKSRC}/homeassistant/components/*/manifest.json
.endfor
	@${FIND} ${WRKSRC} -name '*.bak' -name '*.orig' -delete

post-stage:
	@${MKDIR} ${STAGEDIR}/var/db/homeassistant
	@${ECHO_CMD} "@dir(homeassistant,homeassistant,) /var/db/homeassistant" >> ${TMPPLIST}

.include <bsd.port.mk>
