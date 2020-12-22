PORTNAME=	rutorrent
PORTVERSION=	5.2.10
DISTVERSIONPREFIX=v
CATEGORIES=	www

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Web front-end for the Bittorrent client rtorrent
WWW=		https://github.com/Novik/ruTorrent

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		php:web
USE_PHP=	mbstring posix xml session zlib

NO_BUILD=	yes
NO_ARCH=	yes
USE_GITHUB=	yes
PORTEXAMPLES=	rutorent.conf
SUB_FILES=	pkg-message
GH_ACCOUNT=	Novik
GH_PROJECT=	ruTorrent

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_GROUP=	PLUGINS 3RDPARTY
OPTIONS_GROUP_PLUGINS=	AUTOTOOLS BULKMAGNET CHECKPORT CHUNKS COOKIES CPULOAD \
		CREATE DATA DATADIR DISKSPACE EDIT ERASEDATA EXTRATIO \
		EXTSEARCH FEEDS FILEDROP GEOIP HISTORY HTTPRPC IPAD \
		LOGINMGR LOOKAT MEDIAINFO RATIO RETRACKERS RSS \
		RUTRKCHK SCHEDULER SCREENSHOTS SEEDINGTIME \
		SWTORRENT SOURCE SPECTROGRAM THEME THROTTLE TRACKLBLS \
		TRAFIC UNPACK UPLOADETA XMPP
OPTIONS_GROUP_3RDPARTY=	HOSTNAME MOBILE INSTANTSEARCH PAUSEWEBUI \
		RATIOCOLOR
OPTIONS_DEFAULT=CHUNKS CREATE DATADIR EDIT ERASEDATA HOSTNAME \
		SCHEDULER SEEDINGTIME SOURCE TRACKLBLS TRAFIC
OPTIONS_SUB=	yes

3RDPARTY_DESC=		3rd party plugins

AUTOTOOLS_DESC=		Provides some possibilities on automation
AUTOTOOLS_DIRS=		autotools
AUTOTOOLS_USE=		PHP=sysvsem

BULKMAGNET_DESC=	Allows bulk operations with magnet links
BULKMAGNET_DIRS=	bulk_magnet

CHECKPORT_DESC=		Adds incoming port status indicator
CHECKPORT_DIRS=		check_port

CHUNKS_DESC=		Shows the download status of torrent chunks
CHUNKS_DIRS=		chunks

COOKIES_DESC=		Use cookies for client authentication on trackers
COOKIES_DIRS=		cookies

CPULOAD_DESC=		Adds a CPU Load usage bar to the bottom toolbar
CPULOAD_DIRS=		cpuload

CREATE_DESC=		Allows for the creation of new .torrent files
CREATE_DIRS=		create

DATA_DESC=		Adds the "Get File" item to the right click menu
DATA_DIRS=		data

DATADIR_DESC=		Replacement of the cur torrent data dir
DATADIR_DIRS=		datadir
DATADIR_USE=		PHP=sysvsem

DISKSPACE_DESC=		Adds an easy to read disk meter
DISKSPACE_DIRS=		diskspace

EDIT_DESC=		Edit list of trackers and comment of the torrent
EDIT_DIRS=		edit

ERASEDATA_DESC=		Allows to delete data via context menu
ERASEDATA_DIRS=		erasedata

EXTRATIO_DESC=		Extends the functionality of the ratio plugin
EXTRATIO_DIRS=		extratio
EXTRATIO_IMPLIES=	RATIO

EXTSEARCH_DESC=		Allows to search many popular torrent sites
EXTSEARCH_DIRS=		extsearch
EXTSEARCH_USE=		PHP=dom,iconv

FEEDS_DESC=		Making RSS feeds with information of torrents
FEEDS_DIRS=		feeds

FILEDROP_DESC=		Allows to drag multiple torrents to the browser
FILEDROP_DIRS=		filedrop

GEOIP_DESC=		Shows geolocation of peers for the selected torrent
GEOIP_DIRS=		geoip
GEOIP_USE=		PHP=sqlite3

HISTORY_DESC=		Log a history of torrents
HISTORY_DIRS=		history

HTTPRPC_DESC=		Replacement for the mod_scgi webserver module
HTTPRPC_DIRS=		httprpc

IPAD_DESC=		Use scrolling and right-click mouse button
IPAD_DIRS=		ipad

LOGINMGR_DESC=		Used to login to 3rd party torrent sites
LOGINMGR_DIRS=		loginmgr

LOOKAT_DESC=		Search for torrent name in external sources
LOOKAT_DIRS=		lookat

MEDIAINFO_DESC=		Display media file information
MEDIAINFO_DIRS=		mediainfo
MEDIAINFO_RUN_DEPENDS=	mediainfo:multimedia/mediainfo

RATIO_DESC=		Set ratio limits for groups of torrents
RATIO_DIRS=		extratio ratio

RETRACKERS_DESC=	Add specified trackers to newly added torrents
RETRACKERS_DIRS=	retrackers

RSS_DESC=		Fetch torrents via rss download links
RSS_DIRS=		rss rssurlrewrite
RSS_USE=		PHP=dom,iconv

RUTRKCHK_DESC=		Checks the rutracker.org for changed torrents
RUTRKCHK_DIRS=		rutracker_check

SCHEDULER_DESC=		Scheduler to control limits
SCHEDULER_DIRS=		scheduler

SCREENSHOTS_DESC=	Show screenshots from video
SCREENSHOTS_DIRS=	screenshots
SCREENSHOTS_RUN_DEPENDS=ffmpeg:multimedia/ffmpeg

SEEDINGTIME_DESC=	Adds the columns 'Finished' and 'Added'
SEEDINGTIME_DIRS=	seedingtime

SWTORRENT_DESC=		Show peers like wTorrent
SWTORRENT_DIRS=		show_peers_like_wtorrent

SOURCE_DESC=		Adds a "Get .torrent" to the click context menu
SOURCE_DIRS=		source
SOURCE_USE=		PHP=zip

SPECTROGRAM_DESC=	Show spectrogram of audio files
SPECTROGRAM_DIRS=	spectrogram
SPECTROGRAM_RUN_DEPENDS=sox:audio/sox

THEME_DESC=		Allows change gui theme
THEME_DIRS=		theme

THROTTLE_DESC=		Set limits of speed for groups of torrents
THROTTLE_DIRS=		throttle

TRACKLBLS_DESC=		Adds a set of labels on the category panel
TRACKLBLS_DIRS=		tracklabels

TRAFIC_DESC=		Subsystem for monitoring rtorrent traffic totals
TRAFIC_DIRS=		trafic

UNPACK_DESC=		unrar/unzip torrent data
UNPACK_DIRS=		unpack
UNPACK_RUN_DEPENDS=	unrar:archivers/unrar

UPLOADETA_DESC=		Add upload target and ETA columns
UPLOADETA_DIRS=		uploadeta

XMPP_DESC=		Send notification via xmpp about finished downloads
XMPP_DIRS=		xmpp
XMPP_USE=		PHP=dom

# 3rd party plugins
HOSTNAME_DESC=		Add hostname column to peers tab
HOSTNAME_DIRS=		hostname
HOSTNAME_GH_ACCOUNT=	rozhuk-im:plugin_hostname
HOSTNAME_GH_PROJECT=	rutorrent-hostname:plugin_hostname
HOSTNAME_GH_TAGNAME=	120e1d5c30b5848d9be5b23777687239189025d4:plugin_hostname

INSTANTSEARCH_DESC=	Searchresults appears instantly
INSTANTSEARCH_DIRS=	instantsearch
INSTANTSEARCH_GH_ACCOUNT=Gyran:plugin_instantsearch
INSTANTSEARCH_GH_PROJECT=rutorrent-instantsearch:plugin_instantsearch
INSTANTSEARCH_GH_TAGNAME=d1bc52d6ef6547bc643312b5868c3662c7118a9b:plugin_instantsearch

MOBILE_DESC=		Mobile version of ruTorrent
MOBILE_DIRS=		mobile
MOBILE_GH_ACCOUNT=	xombiemp:plugin_mobile
MOBILE_GH_PROJECT=	rutorrentMobile:plugin_mobile
MOBILE_GH_TAGNAME=	e3555a935469f810ea755516a6f0d85046571114:plugin_mobile

PAUSEWEBUI_DESC=	Adds an button to pause the webui from updating
PAUSEWEBUI_DIRS=	pausewebui
PAUSEWEBUI_GH_ACCOUNT=	Gyran:plugin_pausewebui
PAUSEWEBUI_GH_PROJECT=	rutorrent-pausewebui:plugin_pausewebui
PAUSEWEBUI_GH_TAGNAME=	b398483f1e70c8e215ddbe34dfe3af3fc5f192ef:plugin_pausewebui

RATIOCOLOR_DESC=	Change color of ratio column depending on ratio
RATIOCOLOR_DIRS=	ratiocolor
RATIOCOLOR_GH_ACCOUNT=	Gyran:plugin_ratiocolor
RATIOCOLOR_GH_PROJECT=	rutorrent-ratiocolor:plugin_ratiocolor
RATIOCOLOR_GH_TAGNAME=	3ab4962be86d17fb83649b6db44767796ee377de:plugin_ratiocolor

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIPAD} && ${PORT_OPTIONS:MMOBILE}
IGNORE=			options IPAD and MOBILE are incopatible
.endif

post-extract-HOSTNAME-on:
	@${MKDIR} ${WRKSRC}/plugins/hostname/
	@${MV} ${WRKSRC_plugin_hostname}/* ${WRKSRC}/plugins/hostname/

post-extract-INSTANTSEARCH-on:
	@${MKDIR} ${WRKSRC}/plugins/instantsearch/
	@${MV} ${WRKSRC_plugin_instantsearch}/* ${WRKSRC}/plugins/instantsearch/

post-extract-MOBILE-on:
	@${MKDIR} ${WRKSRC}/plugins/mobile/
	@${MV} ${WRKSRC_plugin_mobile}/* ${WRKSRC}/plugins/mobile/

post-extract-PAUSEWEBUI-on:
	@${MKDIR} ${WRKSRC}/plugins/pausewebui/
	@${MV} ${WRKSRC_plugin_pausewebui}/* ${WRKSRC}/plugins/pausewebui/

post-extract-RATIOCOLOR-on:
	@${MKDIR} ${WRKSRC}/plugins/ratiocolor/
	@${MV} ${WRKSRC_plugin_ratiocolor}/* ${WRKSRC}/plugins/ratiocolor/

do-install:
	# Prepare.
	@${FIND} ${WRKSRC} -type f \( \
		-name '*.orig' \
		-o -name '*.bak' \
		-o -name '.gitignore' \) -delete
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	# Install base files.
.for _dir in conf css images js lang php share
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${_dir} ${STAGEDIR}${WWWDIR})
.endfor
.for _file in index.html
	${INSTALL_DATA} ${WRKSRC}/${_file} ${STAGEDIR}${WWWDIR}/
.endfor
	# Install base plugins.
	@${MKDIR} ${STAGEDIR}${WWWDIR}/plugins
.for _dir in _cloudflare _getdir _noty _noty2 _task
	@(cd ${WRKSRC}/plugins && ${COPYTREE_SHARE} ${_dir} ${STAGEDIR}${WWWDIR}/plugins)
.endfor
	# Install selected plugins.
.for _opt in ${OPTIONS_GROUP_PLUGINS} ${OPTIONS_GROUP_3RDPARTY}
.  if ${PORT_OPTIONS:M${_opt}}
.    for _dir in ${${_opt}_DIRS}
	@(cd ${WRKSRC}/plugins && ${COPYTREE_SHARE} ${_dir} ${STAGEDIR}${WWWDIR}/plugins)
.    endfor
.  endif
.endfor
	# Fix perms.
	@${FIND} ${STAGEDIR}${WWWDIR} -type f -name "*.sh" -exec ${CHMOD} +x {} \+
	# Rename config files to .sample.
.for _conf in access.ini config.php plugins.ini
	@${MV} ${STAGEDIR}${WWWDIR}/conf/${_conf} ${STAGEDIR}${WWWDIR}/conf/${_conf}.sample
.endfor
	# Rename plugins configs to .sample.
	@${FIND} ${STAGEDIR}${WWWDIR}/plugins -maxdepth 2 -type f \
		-name "conf.php" -exec ${MV} {} {}.sample \;

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/rutorent.conf ${STAGEDIR}${EXAMPLESDIR}/

post-stage:
	# Generate plist.
	@${SETENV} ${CO_ENV} ${SH} ${SCRIPTSDIR}/check-stagedir.sh makeplist | \
		${GREP} -v ^\/ | \
		${SED} -e 's|%%WWWDIR%%|www/${PORTNAME}|' \
			-e 's|%%PORTEXAMPLES%%||' \
			-e 's|%%EXAMPLESDIR%%|share/examples/${PORTNAME}|' \
			> ${TMPPLIST}
	# Mark config files as samples in plist.
	@${REINPLACE_CMD} -E "s|(.*\.sample)$$|@sample \1|" ${TMPPLIST}
	# Fix perms.
	@${ECHO_CMD} "@postexec chown -R root:${WWWGRP} ${WWWDIR}/share" >> ${TMPPLIST}
	@${ECHO_CMD} "@postexec chmod -R u=rwX,g=rwX,o=rwX ${WWWDIR}/share" >> ${TMPPLIST}
	@${ECHO_CMD} "@postexec chmod u=rw,g=r,o=r ${WWWDIR}/share/.htaccess" >> ${TMPPLIST}

.include <bsd.port.post.mk>
