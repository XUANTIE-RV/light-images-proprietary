#!/bin/sh

  ps -ef | grep cam_app | grep -v grep | awk '{print $2}' |  xargs kill -9


