clear
# gcc -o parallel_min_max utils.c find_min_max.c parallel_min_max.c && ./parallel_min_max --seed 9 --array_size 999999999 --pnum 4 --timeout 1
# ./parallel_min_max --seed 9 --array_size 999999999 --pnum 4
make all
./parallel_min_max --seed 9 --array_size 80000000 --pnum 4 --by_files
./parallel_min_max --seed 9 --array_size 79583214 --pnum 4
./sequential_min_max 9 80000000
./background 9 80000000 #999999999
make clean
