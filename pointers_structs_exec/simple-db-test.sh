#!/bin/sh

set -e
export APP=./simple-db-ex17
export DB=db.dat

echo $APP $DB c
$APP $DB c
echo $APP $DB s 1 zed zed@zedshaw.com
$APP $DB s 1 zed zed@zedshaw.com
echo $APP $DB s 2 frank frank@zedshaw.com
$APP $DB s 2 frank frank@zedshaw.com
echo $APP $DB s 3 joe joe@zedshaw.com
$APP $DB s 3 joe joe@zedshaw.com

echo
echo $APP $DB l
$APP $DB l
# 1 zed zed@zedshaw.com
# 2 frank frank@zedshaw.com
# 3 joe joe@zedshaw.com
echo $APP $DB d 3
$APP $DB d 3
echo $APP $DB l
$APP $DB l
# 1 zed zed@zedshaw.com
# 2 frank frank@zedshaw.com
echo $APP $DB g 2
$APP $DB g 2
# 2 frank frank@zedshaw.com

echo
echo valgrind --leak-check=yes $APP $DB g 2
valgrind --leak-check=yes $APP $DB g 2
