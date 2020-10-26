#!/bin/bash

if [ ! -f ex9.c ] ; then
    echo ex9 faltando
    exit 1
fi

if ! diff <(cat ex9.c | sed 's/ex9.c/ERROR/g' | sed 's/fopen/fоpen/g') <(./ex9.x) ; then 
    echo ex9 com erro 
    exit 1
fi

echo ex9 ok 
exit 0

