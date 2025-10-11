#!/bin/bash
if [ $# -ne 1 ]; then
	echo "Пожалуйста, укажите ваше имя"
	exit 1
fi
echo "Привет, $1"

