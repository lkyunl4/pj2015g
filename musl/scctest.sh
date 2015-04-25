for file in *
do
  sed -i '1i\'"#ifndef SCC_TEST\n" $file && echo "#endif" >> $file
done
