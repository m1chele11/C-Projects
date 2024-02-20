# This script defines a simple compiler function. 
# Think of this as a primative make compile

# It expects as an argument a .c source file. 
function compile {
    src_file=$1
    binary_file=${1%.c}
    rm ${binary_file}
    gcc ${src_file} -o ${binary_file}
}

function compile_and_run {
    compile $1
    ./${1%.c}
}