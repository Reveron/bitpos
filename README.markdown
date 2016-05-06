Build Status
------------
[![Build Status](https://travis-ci.org/php-memcached-dev/php-memcached.png?branch=master)](https://travis-ci.org/php-memcached-dev/php-memcached)

Description
-----------
This extension provides a single function that returns an array of positions
of set bits in a given binary string:

```php
array get_bit_positions ( string $string )
```

Positions are counted from left to right starting with 0.

The function works up to 20 times faster than its counterpart written in pure
PHP and is intended to be used on large data sets, or in tasks where performance
matters.

Building
--------

    $ phpize
    $ ./configure
    $ make
    $ make test

Usage example
-------------

```php

// |----------------------------------------------------------------------------------|
// | Position: | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 || 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
// |-----------|---|---|---|---|---|---|---|---||---|---|----|----|----|----|----|----|
// | Bit:      | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 1 || 0 | 0 | 0  | 0  | 1  | 0  | 1  | 0  |
// |----------------------------------------------------------------------------------|
$data = "\x05\x0A";

$result = get_bit_positions($data);

var_export($result);

// Outputs:
//
// array (
//     0 => 5,
//     1 => 7,
//     2 => 12,
//     3 => 14,
//   )

```
