--- random/rndunix.c.orig	2017-11-23 21:16:58.000000000 +0300
+++ random/rndunix.c	2019-09-12 02:30:28.798592000 +0300
@@ -727,23 +727,7 @@
     }
     /* close all files but the ones we need */
     {	int nmax, n1, n2, i;
-#ifdef _SC_OPEN_MAX
-	if( (nmax=sysconf( _SC_OPEN_MAX )) < 0 ) {
-# ifdef _POSIX_OPEN_MAX
-	    nmax = _POSIX_OPEN_MAX;
-# else
-	    nmax = 20; /* assume a reasonable value */
-# endif
-	}
-        /* AIX returns INT32_MAX instead of a proper value.  We assume that
-         * this is always an error and use a reasonable value.  */
-# ifdef INT32_MAX
-        if (nmax == INT32_MAX)
-          nmax = 20;
-# endif
-#else /*!_SC_OPEN_MAX*/
 	nmax = 20; /* assume a reasonable value */
-#endif /*!_SC_OPEN_MAX*/
 	n1 = fileno( stderr );
 	n2 = dbgfp? fileno( dbgfp ) : -1;
 	for(i=0; i < nmax; i++ ) {
