#!/bin/sh
I=1
while IFS=% read -r source exp; do
        res=$(echo $source | $1)
        #res=$(echo "$res" | tail -n +2)
        if [ x"$exp" != x"$res" ]; then
                echo TEST $I '('$source')' FAILED: expexted "$exp", got "$res"

        else
                echo TEST $I PASSED
        fi
        I=$((I+1))
done <<END
    5 1 2 3 4 5%0
    0%0
    1 234%0
    12 1 2 3 4 5 6 7 8 9 10 1 2%2
    15 1 2 3 4 5 6 7 8 9 10 100 200 300 400 1%0
END

