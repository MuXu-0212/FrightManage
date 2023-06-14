# hello:hello.c
# 	gcc hello.c -o hello

##########################################################################

# hello:hello.o
# 	gcc hello.o -o hello
# hello.o:hello.c
# 	gcc -c hello.c -o hello.o

##########################################################################

# ALL:

# add.o:add.c
# 	gcc -c add.c -o add.o

##########################################################################

# src = $(wildcard *.c)
# obj = $(patsubst %.c, %.o, $(src))

# ALL:a.out

# a.out:$(obj)
# 	gcc $(obj) -o a.out
# add.o:add.c
# 	gcc -c add.c -o add.o
# sub.o:sub.c
# 	gcc -c sub.c -o sub.o
# mul.o:mul.c
# 	gcc -c mul.c -o mul.o
# div.o:div.c
# 	gcc -c div.c -o div.o
# main.o:main.c
# 	gcc -c main.c -o main.o
# hello.o:hello.c
# 	gcc -c hello.c -o hello.o

# clean:
# 	-rm -rf $(obj) a.out

##########################################################################

# src = $(wildcard *.c)
# obj = $(patsubst %.c, %.o, $(src))

# ALL:a.out

# a.out:$(obj)
# 	gcc $^ -o $@
# add.o:add.c
# 	gcc -c $< -o $@
# sub.o:sub.c
# 	gcc -c $< -o $@
# hello.o:hello.c
# 	gcc -c $< -o $@
# div1.o:div1.c
# 	gcc -c $< -o $@

# clean:
# 	-rm -rf $(obj) a.out


##########################################################################

# src = $(wildcard *.c)
# obj = $(patsubst %.c, %.o, $(src))

# ALL:a.out

# a.out:$(obj)
# 	gcc $^ -o $@

# %.o:%.c
# 	gcc -c $< -o $@

# clean:
# 	-rm -rf $(obj) a.out


##########################################################################

# doc_args = c	#	c表示编译c文件，cpp表示编译c++文件
# gg = gcc		#	gcc表示编译c文件，g++表示c++文件


# src = $(wildcard ./src/*.c)
# obj = $(patsubst ./src/%.c, ./obj/%.o, $(src))

# inc_path = ./inc

# myArgs = -Wall -g

# ALL:a.out

# a.out:$(obj)
# 	$(gg) $^ -o $@ $(myArgs)

# $(obj):./obj/%.o:./src/%.c
# 	$(gg) -c $< -o $@ $(myArgs) -I $(inc_path)

# clean:
# 	-rm -rf $(obj) a.out

# .PHONY: clean ALL	



##########################################################################


src = $(wildcard ./src/*.c)
obj = $(patsubst ./src/%.c, ./obj/%.o, $(src))

gg = gcc
myArgs = -Wall -g
INCLUDES = -I ./inc

ALL:a.out

a.out:$(obj)
	$(gg) $^ -o $@ $(myArgs)

$(obj):./obj/%.o:./src/%.c
	$(gg) $(INCLUDES) -c $< -o $@ $(myArgs) 
clean:
	-rm -rf $(obj) a.out

.PHONY: clean ALL	


