IN=$1
arr=$(echo $IN | tr "." "\n")
echo $arr[*]
for x in $arr
do
  echo "> [$x]"
done
