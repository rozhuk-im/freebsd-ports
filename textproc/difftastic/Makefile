PORTNAME=	difftastic
DISTVERSION=	0.64.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Diff tool that compares files based on their syntax
WWW=		https://difftastic.wilfred.me.uk/ \
		https://github.com/Wilfred/difftastic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	Wilfred

PLIST_FILES=	bin/difft

CARGO_CRATES=	ahash-0.8.11 \
		aho-corasick-1.1.3 \
		allocator-api2-0.2.16 \
		anstream-0.6.15 \
		anstyle-1.0.10 \
		anstyle-parse-0.2.6 \
		anstyle-query-1.1.1 \
		anstyle-wincon-3.0.4 \
		assert_cmd-2.0.8 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bitflags-2.5.0 \
		bstr-1.9.1 \
		bumpalo-3.16.0 \
		cc-1.2.7 \
		cfg-if-1.0.0 \
		clap-4.5.23 \
		clap_builder-4.5.23 \
		clap_lex-0.7.4 \
		colorchoice-1.0.3 \
		crossbeam-deque-0.8.5 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.19 \
		crossterm-0.28.1 \
		crossterm_winapi-0.9.1 \
		diff-0.1.13 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.10.0 \
		encoding_rs-0.8.35 \
		env_logger-0.10.2 \
		equivalent-1.0.1 \
		errno-0.3.8 \
		fixedbitset-0.4.2 \
		float-cmp-0.9.0 \
		fnv-1.0.7 \
		glob-0.3.1 \
		globset-0.4.15 \
		hashbrown-0.14.3 \
		heck-0.5.0 \
		hermit-abi-0.3.9 \
		humansize-2.1.3 \
		humantime-2.1.0 \
		ignore-0.4.23 \
		indexmap-2.2.6 \
		is-terminal-0.4.12 \
		is_terminal_polyfill-1.70.1 \
		itertools-0.10.5 \
		itoa-1.0.10 \
		lazy_static-1.4.0 \
		libc-0.2.169 \
		libm-0.2.8 \
		line-numbers-0.3.0 \
		linux-raw-sys-0.4.14 \
		lock_api-0.4.11 \
		log-0.4.21 \
		memchr-2.7.1 \
		minimal-lexical-0.2.1 \
		mio-1.0.3 \
		nom-7.1.3 \
		normalize-line-endings-0.3.0 \
		num-traits-0.2.19 \
		once_cell-1.19.0 \
		owo-colors-3.5.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.9 \
		petgraph-0.6.4 \
		predicates-2.1.5 \
		predicates-core-1.0.6 \
		predicates-tree-1.0.9 \
		pretty_assertions-1.4.1 \
		pretty_env_logger-0.5.0 \
		proc-macro2-1.0.79 \
		quote-1.0.35 \
		radix-heap-0.4.2 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		redox_syscall-0.4.1 \
		regex-1.11.1 \
		regex-automata-0.4.9 \
		regex-syntax-0.8.5 \
		rustc-hash-2.0.0 \
		rustix-0.38.34 \
		rustversion-1.0.14 \
		ryu-1.0.17 \
		same-file-1.0.6 \
		scopeguard-1.2.0 \
		serde-1.0.197 \
		serde_derive-1.0.197 \
		serde_json-1.0.114 \
		shlex-1.3.0 \
		signal-hook-0.3.17 \
		signal-hook-mio-0.2.4 \
		signal-hook-registry-1.4.1 \
		smallvec-1.13.2 \
		streaming-iterator-0.1.9 \
		strsim-0.10.0 \
		strsim-0.11.1 \
		strum-0.26.3 \
		strum_macros-0.26.4 \
		syn-2.0.55 \
		termcolor-1.4.1 \
		terminal_size-0.4.1 \
		termtree-0.4.1 \
		tikv-jemalloc-sys-0.6.0+5.3.0-1-ge13ca993e8ccb9ba9847cc330696e02839f328f7 \
		tikv-jemallocator-0.6.0 \
		tree-sitter-0.24.5 \
		tree-sitter-bash-0.23.3 \
		tree-sitter-c-0.23.4 \
		tree-sitter-c-sharp-0.23.1 \
		tree-sitter-cpp-0.23.4 \
		tree-sitter-css-0.23.1 \
		tree-sitter-elixir-0.3.4 \
		tree-sitter-erlang-0.13.0 \
		tree-sitter-fsharp-0.1.0 \
		tree-sitter-go-0.23.4 \
		tree-sitter-haskell-0.23.1 \
		tree-sitter-html-0.23.2 \
		tree-sitter-java-0.23.4 \
		tree-sitter-javascript-0.23.1 \
		tree-sitter-json-0.24.8 \
		tree-sitter-julia-0.23.1 \
		tree-sitter-language-0.1.3 \
		tree-sitter-lua-0.2.0 \
		tree-sitter-make-1.1.1 \
		tree-sitter-nix-0.0.2 \
		tree-sitter-objc-3.0.2 \
		tree-sitter-ocaml-0.23.2 \
		tree-sitter-pascal-0.10.0 \
		tree-sitter-php-0.23.11 \
		tree-sitter-python-0.23.5 \
		tree-sitter-ruby-0.23.1 \
		tree-sitter-rust-0.23.2 \
		tree-sitter-scala-0.23.3 \
		tree-sitter-swift-0.7.0 \
		tree-sitter-toml-ng-0.7.0 \
		tree-sitter-typescript-0.23.2 \
		tree-sitter-verilog-1.0.3 \
		tree-sitter-xml-0.7.0 \
		tree-sitter-yaml-0.7.0 \
		tree_magic_mini-3.1.6 \
		typed-arena-2.0.2 \
		unicode-ident-1.0.12 \
		unicode-width-0.1.11 \
		utf8parse-0.2.2 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
		walkdir-2.5.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.9 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.6 \
		wu-diff-0.1.2 \
		yansi-1.0.1 \
		zerocopy-0.7.32 \
		zerocopy-derive-0.7.32

PORTSCOUT=	ignore:1

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
LIB_DEPENDS+=	libatomic.so:lang/gcc${GCC_DEFAULT}
LDFLAGS+=	-L/usr/local/lib/gcc${GCC_DEFAULT} -latomic
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${STAGEDIR}${DOCSDIR}/
	@cd ${WRKSRC}/manual/src && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/manual

.include <bsd.port.mk>
