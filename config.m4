dnl $Id$
dnl config.m4 for extension bitpos

PHP_ARG_ENABLE(bitpos, whether to enable bitpos support,
[  --enable-bitpos           Enable bitpos support])

if test "$PHP_BITPOS" != "no"; then
  PHP_NEW_EXTENSION(bitpos, bitpos.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi

