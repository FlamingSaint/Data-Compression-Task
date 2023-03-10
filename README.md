# Data-Compression-Task

This code uses the zlib library to compress an input file and write the compressed data to a new file with the ".gz" extension. It then calculates and prints informative metrics about the compression, such as the original size, compressed size, and compression ratio.

## To compile the c++ file

``` bash
cd task
g++ -o compress compress.cpp -lz

```
## After compiling, you can run the executable with the input file as an argument:

``` bash 
./compress input_file
```
This will compress the "input_file" and write the compressed data to "input_file.gz". It will also print informative metrics about the compression to the console.

## Results 
![]()![Screenshot from 2023-03-10 15-59-33](https://user-images.githubusercontent.com/78465537/224297739-809a12c3-2c4a-4979-8139-e5df66ad3440.png)
