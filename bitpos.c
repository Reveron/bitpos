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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/head.h"
#include "ext/standard/info.h"
#include "php_bitpos.h"

/* {{{ arginfo */
ZEND_BEGIN_ARG_INFO(arginfo_get_bit_positions, 0)
    ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ bitpos_functions[]
 *
 */
const zend_function_entry bitpos_functions[] = {
        PHP_FE(get_bit_positions, arginfo_get_bit_positions)
        PHP_FE_END
};
/* }}} */

/* {{{ proto array get_bit_positions(string data)
   Return an array of the positions of all set bits in the data string */
PHP_FUNCTION(get_bit_positions)
{
    char *data = NULL;
    size_t data_len;
    long long i, position = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &data, &data_len) == FAILURE) {
        return;
    }

    array_init(return_value);

    for (i = 0; i < data_len; i++) {
        int j = 0b10000000;

        do {
            if (data[i] & j) {
                add_next_index_long(return_value, position);
            }
        } while (j >>= 1 && ++position);
    }

    return;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(bitpos)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "bitpos support", "enabled");
    php_info_print_table_end();
}
/* }}} */

/* {{{ bitpos_module_entry
 */
zend_module_entry bitpos_module_entry = {
    STANDARD_MODULE_HEADER,
    "bitpos",
    bitpos_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    PHP_MINFO(bitpos),
    PHP_BITPOS_VERSION,
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_BITPOS
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(bitpos)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
