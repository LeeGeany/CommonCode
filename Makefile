# C++ 컴파일러
CC = g++

# C++ 컴파일러 옵션
CXXFLAGS = -g

# 링커 옵션
LDFLAGS = 

# 소스 파일 디렉토리
SRC_DIR = Srcs

# 오브젝트 파일 디렉토리
OBJ_DIR = Objs

# Include 파일 디렉토리
INCLUDE =	-I $(SRC_DIR)										\
			-I $(SRC_DIR)/Source								\
			-I $(SRC_DIR)/Common/Communication				\
		   	-I $(SRC_DIR)/Common/Communication/Ethernet		\
			-I $(SRC_DIR)/Common/Communication/Ethernet/TCP

# 생성하고자 하는 실행 파일 이름
TARGET = main

#
SRCS += $(wildcard $(SRC_DIR)/Common/Communication/Ethernet/TCP/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/Source/*.cpp)
SRCS  = $(wildcard $(SRC_DIR)/*.cpp)

#
OBJS = ${SRCS:.cpp=.o}
DEPS = $(OBJS:.o=.d)

OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

#
all: main
$(OBJ_DIR)/%.o : $(SRCS)
	mkdir -p $(shell dirname $@) 
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ -MD $(LDFLAGS)  

$(TARGET) : $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

.PHONY: clean all
clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET)

-include $(DEPS)
