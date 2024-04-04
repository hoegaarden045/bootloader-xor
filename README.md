## Описание
Простой загрузчик, шифрующий сообщение с помощью XOR

## Makefile 
Собрать 
```
make build
```
Очистить от лишних файлов
```
make clean 
```
Запустить qemu
``` 
make run
```
## Запуск 
```
make build
./xor "message" "1_byte_key"
make run 
