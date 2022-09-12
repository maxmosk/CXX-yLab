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
    10 1 2 3 4 5 6 7 8 9 10%0
    30 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 1 21 22 23 24 25 26 27 28 29 30%1
END

