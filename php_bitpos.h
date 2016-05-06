/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Ivan Tsirulev                                                |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_BITPOS_H
#define PHP_BITPOS_H

extern zend_module_entry bitpos_module_entry;
#define phpext_bitpos_ptr &bitpos_module_entry

#define PHP_BITPOS_VERSION "1.0.0"

#ifdef PHP_WIN32
#	define PHP_BITPOS_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_BITPOS_API __attribute__ ((visibility("default")))
#else
#	define PHP_BITPOS_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#if defined(ZTS) && defined(COMPILE_DL_BITPOS)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#ifndef PHP_FE_END
#define PHP_FE_END {NULL, NULL, NULL}
#endif

PHP_FUNCTION(get_bit_positions);

#endif	/* PHP_BITPOS_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
