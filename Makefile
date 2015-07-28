CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -g3

SRC = $(addprefix src/,         \
            main.cc             \
            microphone.cc       \
            output-stream.cc    \
            delay.cc            \
            boost.cc            \
            drive.cc            \
            reverb.cc           \
            flanger.cc          \
						swell.cc						\
        )

TARGET = test

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) -lportaudio -ltbb

clean:
	rm -f $(TARGET)
