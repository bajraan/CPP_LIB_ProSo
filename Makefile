CC = g++
CFLAGS = -std=c++2a -Wall
TARGET = out
TEST_TARGET = test_runner

SRCS = main.cpp 00_pbaProSo/pbaProSo.cpp
OBJS = $(SRCS:.cpp=.o)

TEST_SRCS = test.cpp 00_pbaProSo/pbaProSo.cpp 60_Tests_Unit_Level/pbaProSoTests.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) -o $(TEST_TARGET)