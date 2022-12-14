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
    10 0%0
    10 1 1%0
    10 5 1 1 1 1 1%4
    10 5 1 2 3 4 5%0
    10 10 1 2 3 4 5 1 2 3 4 5%5
    10 12 1 2 3 4 5 6 7 8 9 10 1 2%2
    10 12 1 2 3 4 5 6 7 8 9 10 1 1%2
    10 12 1 2 3 4 5 6 7 8 9 10 9 10%2
    10 15 1 2 3 4 5 6 7 8 1 2 3 4 5 6 7%7
    10 15 1 2 3 4 5 6 7 8 9 10 100 200 300 400 1%0
    10 17 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 100 6%5
    10 17 1 2 3 4 5 6 7 8 9 10 101 101 101 101 101 102 2%4
    10 20 1 2 3 4 5 6 7 8 9 10 101 102 103 104 105 106 107 108 109 110%0
    10 20 1 2 3 4 5 6 7 8 9 10 101 102 103 104 105 106 107 108 109 10%1
    10 30 1 2 3 4 5 6 7 8 9 10 11 11 12 12 13 13 14 14 15 15 16 16 17 17 18 18 19 19 20 20%10
    10 30 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10%20
    10 35 1 2 3 4 5 6 7 8 9 10 11 11 12 12 13 13 14 14 15 15 16 16 17 17 18 18 19 19 20 20 1 2 3 4 5%10
    10 40 1 2 3 4 5 6 7 8 9 10 11 11 12 12 13 13 14 14 15 15 16 16 17 17 18 18 19 19 20 20 1 2 3 4 5 11 12 13 14 15%14
    10 40 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1%39
END

