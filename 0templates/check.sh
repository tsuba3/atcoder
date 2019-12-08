#!/bin/zsh

IN=${IN:-"in"}
OUT=${OUT:-"out"}
CHECK="diff"
EXE=${1:-"./a.out"}
TEMP="/tmp/temp$RANDOM"

NAME_LEN=0
for test_name ($(ls -1 $IN)) {
    if [ $NAME_LEN -lt ${#test_name} ]; then
        NAME_LEN=${#test_name}
    fi
}
ALL="0"
AC="0"

for test_name ($(ls -1 $IN)) {
    t=`cat "$IN/$test_name" | eval time $EXE 2>&1 > $TEMP`
    msg=`eval $CHECK $TEMP "$OUT/$test_name"`
    if [ $? -eq 0 ]; then
        printf "\U2705 %-${NAME_LEN}s   %s\n" $test_name $t
        AC=$(( $AC + 1 ))
    else
        printf "\U274C %-${NAME_LEN}s   %s\n" $test_name $t
        echo $msg
        echo
    fi
    if [ -n $TMUX ]; then; tmux refresh-client; fi # 絵文字が表示されないことがあるため
    ALL=$(( $ALL + 1 ))
    rm -f $TEMP
}


echo "$AC / $ALL"

