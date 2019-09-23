// sh对拍脚本
// 编译好data.cpp sol.cpp std.cpp后sh check.sh
#!/bin/bash
a=0
while true; do
	#g++ -o data data.cpp
	#g++ -o sol sol.cpp
	#g++ -o std std.cpp
    ./data > data.in
    ./std <data.in > std.out
    ./sol <data.in > sol.out
    a=`expr $a + 1`
    echo $a
    if diff std.out sol.out; then
        printf "AC\n"
    else
        printf "Wa\n"
        cat sol.out std.out
        exit 0
    fi
done