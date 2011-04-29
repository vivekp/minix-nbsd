#!/bin/sh

export CC=gcc
export MAKEOBJDIR=obj-gnu
export PATH=$PATH:/usr/pkg/bin

make $@ NBSD_LIBC=${NBSD_LIBC}
