CC=gcc
#CC=arm-linux-gcc

SOURCE=$(wildcard source/*c)
#DONG_JING=$(wildcard -L./library/libmy_stati.a)
DONG_JING=$(wildcard -L./library/libmy_auto.so)

binary/bims: $(SOURCE)
	@$(CC) $(SOURCE) -o $@  $(DONG_JING)
clean:
	@rm binary/* -r
run:
	@./binary/bims