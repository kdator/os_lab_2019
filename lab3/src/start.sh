clear
# gcc -o parallel_min_max utils.c find_min_max.c parallel_min_max.c
make all
./parallel_min_max --seed 9 --array_size 8000000 --pnum 4 --by_files
./parallel_min_max --seed 9 --array_size 8000000 --pnum 4
./sequential_min_max 9 8000000
./background 9 8000000
make clean
