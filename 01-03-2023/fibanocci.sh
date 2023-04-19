echo "Enter the number"
read n 
a=0
b=1
c=0
i=1
while [ $i -le $n ]
do
    echo $c
    a=$(($b+$c))
    b=$c
    c=$a
    i=$(($i+1))
done