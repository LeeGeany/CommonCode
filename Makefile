# C++ 컴파일러
CC = g++

# C++ 컴파일러 옵션
CXXFLAGS = -g -std=c++17

# 링커 옵션
LDFLAGS = 

# Library
LIBS = -lurcu

# 소스 파일 디렉토리
SRC_DIR = Srcs

# 오브젝트 파일 디렉토리
OBJ_DIR = Objs

# Include 파일 디렉토리
INCLUDE = -I $(SRC_DIR)
										
# 생성하고자 하는 실행 파일 이름
TARGET = main

# Main
SRCS += $(wildcard $(SRC_DIR)/*.cpp)

# Application
SRCS += $(wildcard $(SRC_DIR)/App/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/App/Manager/Data/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/App/Manager/Thread/*.cpp)


# Common
SRCS += $(wildcard $(SRC_DIR)/Common/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/Common/Communication/Ethernet/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/Common/Communication/Ethernet/TCP/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/Common/Communication/IPC/MsgQueue/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/Common/Communication/Signal/*.cpp)

SRCS += $(wildcard $(SRC_DIR)/Common/Concurrent/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/Common/Concurrent/Mutex/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/Common/Concurrent/Thread/*.cpp)

SRCS += $(wildcard $(SRC_DIR)/Common/DataSystem/*.cpp)

SRCS += $(wildcard $(SRC_DIR)/Common/FileSystem/File/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/Common/FileSystem/Directory/*.cpp)

SRCS += $(wildcard $(SRC_DIR)/Common/Time/*.cpp)

# Source




#SRCS += $(wildcard $(SRC_DIR)/Common/Logger/*.cpp)

#SRCS += $(wildcard $(SRC_DIR)/Common/Time/*.cpp)



#SRCS += $(wildcard $(SRC_DIR)/Source/Interface/Manager/*.cpp)
#SRCS += $(wildcard $(SRC_DIR)/Source/Interface/Node/*.cpp)
#SRCS += $(wildcard $(SRC_DIR)/Source/Data/*.cpp)

#SRCS += $(wildcard $(SRC_DIR)/UnitTest/*.cpp)
#SRCS += $(wildcard $(SRC_DIR)/UnitTest/*.cpp)
#SRCS += $(wildcard $(SRC_DIR)/UnitTest/Test_MsgQueue/*.cpp)
#SRCS += $(wildcard $(SRC_DIR)/UnitTest/Test_Thread/*.cpp)
#SRCS += $(wildcard $(SRC_DIR)/UnitTest/Test_Signal/*.cpp)
#SRCS += $(wildcard $(SRC_DIR)/UnitTest/Test_TCP/*.cpp)



OBJS = ${SRCS:.cpp=.o}
DEPS = $(OBJS:.o=.d)

OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: main
$(OBJ_DIR)/%.o : $(SRCS)
	mkdir -p $(shell dirname $@) 
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CC) $(CXXFLAGS) $(INCLUDE) $(SRCS) -o  $(TARGET) $(LDFLAGS) 

.PHONY: clean all
clean:
	rm -f $(OBJECTS) $(TARGET)

-include $(DEPS)
