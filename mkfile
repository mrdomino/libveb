MKSHELL=$PLAN9/bin/rc

<$PLAN9/src/mkhdr

<mkconfig

LIB=$PREFIX/lib/libveb.a

CFLAGS='-std=c99'

OFILES=\
	veb.$O\

CFILES=\
	veb.c\
	mach.c\

HFILES=\
	veb.h\

<$PLAN9/src/mklib

install:QV:	$HFILES
	for (t in $HFILES)
    	cp $t $PREFIX/include
