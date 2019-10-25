# make-eicar

カレントディレクトリに[EICARテストファイル - Wikipedia](https://ja.wikipedia.org/wiki/EICAR%E3%83%86%E3%82%B9%E3%83%88%E3%83%95%E3%82%A1%E3%82%A4%E3%83%AB)を
`eicar.txt`という名前で出力する。

さるLinux用anti virusのテスト用。

2階にわけて出力する。shellだと
``` bash
#!/bin/bash
echo -n 'X5O!P%@AP[4\PZX54(P^)7CC)7}$' > eicar.txt
echo -n 'EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*' >> eicar.txt 
```
に等価。最後の改行はあってもなくてもいいらしい。

straceでsystem callをチェックしやすいようにCで書いた。

``` bash
strace ./make-eicar
strace -c ./make-eicar
strace -e trace=close ./make-eicar
```
などを試してみてください。

ビルドは
``` bash
make clean
make
```
