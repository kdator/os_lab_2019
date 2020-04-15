clear

make sum

./sum --seed 9 --array_size 8000000 --threads_num 4 --border 5
./sum --seed 9 --array_size 7958321 --threads_num 4 --border 10

rm -r resources
rm sum
