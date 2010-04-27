#/bin/sh

if !(test -d build) ;
then mkdir -v build
fi

cd build
cmake .. && make
