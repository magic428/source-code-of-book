CUDAPATH = /usr/local/cuda
NVCCFLAGS    := -I$(CUDAPATH)/include
LIBS         := -lglut -lGLU -lGL -lOpenCL
LFLAGS       = -L$(CUDAPATH)/lib64 -lcuda -lcudart -lm -Wno-deprecated-gpu-targets

SRCEXT := .cu 
#搜寻当前目录下的所有目录
SRCDIRS := $(patsubst ./%, %, $(shell find ./ -type d))

#搜寻所有目录下所有.c的文件
SRCS := $(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*, $(SRCEXT))))
BINS         = $(patsubst %.cu, %, $(SRCS))

# $(warning  $(SRCS))

DIRS := $(dir $(SRCS))
BIN_DIRS = $(addprefix bin/, $(DIRS))

BIN_DIRS := $(foreach d,$(BIN_DIRS),$(shell if [ -d $(d) ]; then echo "exist"; else mkdir -p $(d); fi;))
# $(warning  $(BIN_DIRS))
# $(warning  $(exist))

all: $(BINS)

%: %.cu
	nvcc $(NVCCFLAGS) $(LFLAGS) $(LIBS) $< -o ./bin/$@

clean:
	rm -rf ./bin/*
