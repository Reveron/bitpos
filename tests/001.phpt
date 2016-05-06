--TEST--
Test get_bit_positions() functionality
--SKIPIF--
<?php if (!extension_loaded('bitpos')) print 'skip bitpos extension not available';?>
--FILE--
<?php 
$data = "Test"; // 1010100110010111100111110100

$bit_positions = get_bit_positions($data);

var_export($bit_positions);
?>
--EXPECT--
array (
  0 => 1,
  1 => 3,
  2 => 5,
  3 => 9,
  4 => 10,
  5 => 13,
  6 => 15,
  7 => 17,
  8 => 18,
  9 => 19,
  10 => 22,
  11 => 23,
  12 => 25,
  13 => 26,
  14 => 27,
  15 => 29,
)
