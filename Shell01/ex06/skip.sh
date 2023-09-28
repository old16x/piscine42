#!/bin/sh
ls -l | awk '(NR-0)%2'
