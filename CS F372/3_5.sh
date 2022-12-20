for i in $(ls | tr " " "#")
do
  echo $i | tr "#" " "
done
