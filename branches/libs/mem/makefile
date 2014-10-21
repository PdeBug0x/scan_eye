#编译动作，
#  ar: 编译静态库  so: 编译动态库  app: 编译可执行文件
#  只能指定一个动作，ar so app只能选择一个
ACTION = so

#目标名称，最终得到目标的名称，如:
# 静态库可以指定名称为: libXXX.a
# 动态库可以指定名称为: libXXX.so
# 可执行文件可以指定名称为: main.exe
TARGET = libmem.so

#编译器 
CC = gcc 

#连接器
LD = ld

#归档,静态库
AR = ar

#源文件集合
OBJS = $(wildcard *.c)

#编译选项
CFLAGS += -fPIC -shared -o

$(TARGET):$(OBJS)
	$(CC) $< $(CFLAGS) $@ 
clean:
	rm -rf *.o *.so

