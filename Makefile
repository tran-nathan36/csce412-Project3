CXX = g++ # Change this if using a different compiler

SRCS = main.cpp request.cpp webserver.cpp loadbalancer.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = loadbalancer

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJS)
