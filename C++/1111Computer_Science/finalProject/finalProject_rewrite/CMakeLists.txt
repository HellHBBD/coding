cmake_minimum_required(VERSION 3.10)

project(bulls-and-cows VERSION 1.0)

# final executable
add_executable(bulls-and-cows main.c)
target_include_directories(bulls-and-cows PUBLIC include)
target_link_libraries(bulls-and-cows PUBLIC gameflow answer player)

# add library function
function(addlib name)
	add_library(${name} STATIC lib/${name}.c)
	target_include_directories(${name} PUBLIC include)
endfunction()

# library list
addlib(gameflow)
addlib(answer)
addlib(player)
addlib(timer)
