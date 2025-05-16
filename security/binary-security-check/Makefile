PORTNAME=	binary-security-check
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1
DISTNAME=	${DISTVERSIONPREFIX}${DISTVERSION}
CATEGORIES=	security
MASTER_SITES=	https://codeberg.org/koutheir/${PORTNAME}/archive/
# XXX Teach USES=cargo to not override default DISTFILES
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Analyzer of security features in executable binaries
WWW=		https://codeberg.org/koutheir/binary-security-check

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cargo
WRKSRC=		${WRKDIR}/${PORTNAME}

# make cargo-crates
CARGO_CRATES=	aho-corasick-1.1.3 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anstream-0.6.18 \
		anstyle-1.0.10 \
		anstyle-parse-0.2.6 \
		anstyle-query-1.1.2 \
		anstyle-wincon-3.0.7 \
		arrayvec-0.7.6 \
		autocfg-1.4.0 \
		bitflags-2.8.0 \
		bumpalo-3.17.0 \
		cc-1.2.15 \
		cfg-if-1.0.0 \
		chrono-0.4.39 \
		clap-4.5.30 \
		clap_builder-4.5.30 \
		clap_derive-4.5.28 \
		clap_lex-0.7.4 \
		colorchoice-1.0.3 \
		core-foundation-sys-0.8.7 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		dynamic-loader-cache-0.2.2 \
		either-1.13.0 \
		flexi_logger-0.29.8 \
		goblin-0.9.3 \
		heck-0.5.0 \
		iana-time-zone-0.1.61 \
		iana-time-zone-haiku-0.1.2 \
		is_terminal_polyfill-1.70.1 \
		js-sys-0.3.77 \
		libc-0.2.169 \
		log-0.4.26 \
		memchr-2.7.4 \
		memmap2-0.9.5 \
		nom-8.0.0 \
		nu-ansi-term-0.50.1 \
		num-traits-0.2.19 \
		once_cell-1.20.3 \
		plain-0.2.3 \
		proc-macro2-1.0.93 \
		quote-1.0.38 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		regex-1.11.1 \
		regex-automata-0.4.9 \
		regex-syntax-0.8.5 \
		rustversion-1.0.19 \
		scroll-0.12.0 \
		scroll_derive-0.12.0 \
		shlex-1.3.0 \
		static_assertions-1.1.0 \
		strsim-0.11.1 \
		syn-2.0.98 \
		termcolor-1.4.1 \
		thiserror-2.0.11 \
		thiserror-impl-2.0.11 \
		unicode-ident-1.0.17 \
		utf8parse-0.2.2 \
		wasm-bindgen-0.2.100 \
		wasm-bindgen-backend-0.2.100 \
		wasm-bindgen-macro-0.2.100 \
		wasm-bindgen-macro-support-0.2.100 \
		wasm-bindgen-shared-0.2.100 \
		winapi-util-0.1.9 \
		windows-core-0.52.0 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
