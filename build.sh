#1/sbin/sh
rm -rf /usr/obj/*
cd /usr/src
make obj
cd etc
env DESTDIR=/ make distrib-dirs
cd ..
make build
