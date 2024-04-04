
build: clean
	gcc -o xor xor.c
	nasm -f bin boot.asm

run:
	qemu-system-i386 -hda boot 

clean:
	@rm -vf boot ./xor

