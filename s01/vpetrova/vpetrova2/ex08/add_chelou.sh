echo $FT_NBR1 + $FT_NBR2 \
| tr "'"'\\"?!mrdoc' '0123401234' \
| xargs -I{} echo 'ibase=5;obase=23;'{} \
| bc \
| tr '0123456789ABC' 'gtaio luSnemf'
#sum
#chars to numb
#change the bbase from 5th to 13th, xags jumps the pipe for echo
#caalculate
#translate numbers to strange secret code
