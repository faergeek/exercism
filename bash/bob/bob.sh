#!/usr/bin/env bash

[[ $1 =~ ^[[:space:]]*$ ]] && echo 'Fine. Be that way!' && exit 0

if [[ $1 =~ \?[[:space:]]*$ ]]; then
	asking=1
fi

if [[ $1 =~ [a-zA-Z] && $1 = "${1^^}" ]]; then
	if [[ $asking ]]; then
		echo "Calm down, I know what I'm doing!"
	else
		echo 'Whoa, chill out!'
	fi
elif [[ $asking ]]; then
	echo 'Sure.'
else
	echo 'Whatever.'
fi
