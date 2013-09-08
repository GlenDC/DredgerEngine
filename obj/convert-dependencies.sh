#!/bin/sh
# AUTO-GENERATED FILE, DO NOT EDIT!
if [ -f $1.org ]; then
  sed -e 's!^C:/users/kat11sJermuj/desktop/asdk!/build!ig;s! C:/users/kat11sJermuj/desktop/asdk! /build!ig;s!^F:/ASDK/cygwin/lib!/usr/lib!ig;s! F:/ASDK/cygwin/lib! /usr/lib!ig;s!^F:/ASDK/cygwin/bin!/usr/bin!ig;s! F:/ASDK/cygwin/bin! /usr/bin!ig;s!^F:/ASDK/cygwin/!/!ig;s! F:/ASDK/cygwin/! /!ig;s!^H:!/cygdrive/h!ig;s! H:! /cygdrive/h!ig;s!^G:!/cygdrive/g!ig;s! G:! /cygdrive/g!ig;s!^F:!/cygdrive/f!ig;s! F:! /cygdrive/f!ig;s!^C:!/cygdrive/c!ig;s! C:! /cygdrive/c!ig;' $1.org > $1 && rm -f $1.org
fi
