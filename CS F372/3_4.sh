read -p "Enter a number : " n
if [ $((n&1)) -eq 1 ]
then
    echo $n is odd.
else
    echo $n is even.
fi