# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by malexand          #+#    #+#              #
#    Updated: 2017/11/29 23:02:41 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = opengl

export DEBUG = no
CC = g++
OS := $(shell uname -s)
DEPEND_FRAGMENT = Make.depend
MAKEFLAGS += --silent

ifeq ($(DEBUG), yes)
	CFLAGS =
	CXXFLAGS = -g -ggdb `pkg-config --cflags glfw3` `pkg-config --cflags glew` #-Wall -Werror -Wextra
	CPPFLAGS =
else
	CFLAGS =
	CXXFLAGS = -Ofast -D_REENTRANT `pkg-config --cflags glfw3` `pkg-config --cflags glew` #-Wall -Werror -Wextra
	CPPFLAGS =
endif

ifeq ($(OS), Linux)
	LFLAGS = 	`pkg-config --libs glfw3` `pkg-config --libs glew` -lGL -lm -lGLU
	INCLUDE = 	-I./incs
else
	LFLAGS = 	`pkg-config --libs glfw3` `pkg-config --libs glew` -framework OpenGL -lm
	INCLUDE = 	-I./incs
endif

OUT_DIR = 	objs
SRC_DIR = 	srcs
INC_DIR = 	incs

SDIR = 		./srcs/
SRCS = 		$(shell ls srcs)
SRCC = 		$(addprefix $(SDIR),$(SRCS))

ODIR = 		./objs/
OBJS = 		$(SRCS:.cpp=.o)
OBCC = 		$(addprefix $(ODIR),$(OBJS))

all: dirs $(EXEC) $(DEPEND_FRAGMENT)

-include $(DEPEND_FRAGMENT)

$(EXEC): $(OBCC)
ifeq ($(OS), Linux)
	@echo -e "\x1B[34m$(EXEC):\x1B[0m"
	@$(CC) $(CXXFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS)
	@echo -e "\x1b[36m  + Compile program:\x1B[0m $@"
else
	@echo "\x1B[34m$(EXEC):\x1B[0m"
	@$(CC) $(CXXFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS)
	@echo "\x1b[36m  + Compile program:\x1B[0m $@"
endif

$(ODIR)%.o: $(SDIR)%.cpp
	$(CC) $< $(CXXFLAGS) -c -o $@ $(INCLUDE)
ifeq ($(OS), Linux)
	@echo -e "\r\x1B[32m  + Compile:\x1B[0m $(notdir $<)"
else
	@echo "\r\x1B[32m  + Compile:\x1B[0m $(notdir $<)"
endif

$(DEPEND_FRAGMENT): $(SRCC)
	@touch $(DEPEND_FRAGMENT)
	@makedepend -f $(DEPEND_FRAGMENT) -- -Y -O -DHACK $(CFLAGS) $(CXXFLAGS) $(INCLUDE) -- $(SRCC) >& /dev/null
	@sed 's/.\/srcs/.\/objs/g' $(DEPEND_FRAGMENT) > $(DEPEND_FRAGMENT).bak
	@mv $(DEPEND_FRAGMENT).bak $(DEPEND_FRAGMENT)

clean:
	@rm -rf $(DEPEND_FRAGMENT) $(OUT_DIR) 
ifeq ($(OS), Linux)
	@echo -e "\x1B[31m  - Remove:\x1B[0m objs"
else
	@echo "\x1B[31m  - Remove:\x1B[0m objs"
endif

fclean: clean
	@rm -f $(EXEC)
ifeq ($(OS), Linux)
	@echo -e "\x1B[31m  - Remove:\x1B[0m $(EXEC)"
else
	@echo "\x1B[31m  - Remove:\x1B[0m $(EXEC)"
endif

re: fclean
	make

run: all
	@./$(EXEC)

dirs: $(OUT_DIR) $(SRC_DIR) $(INC_DIR)

$(OUT_DIR):
	@mkdir -p $(OUT_DIR)

$(SRC_DIR):
	@mkdir -p $(SRC_DIR)

$(INC_DIR):
	@mkdir -p $(INC_DIR)

.PHONY: all clean fclean re run dirs
