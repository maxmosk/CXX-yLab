#!/bin/sh
I=1
while IFS=% read -r source exp; do
        res=$(echo $source | $1)
        if [ x"$exp" != x"$res" ]; then
                echo TEST $I '('$source')' FAILED: expexted "$exp", got "$res"

        else
                echo TEST $I PASSED
        fi
        I=$((I+1))
done <<END
    0%0
    1 1%0
    5 1 2 3 4 5%0
    5 1 1 1 1 1%4
END

