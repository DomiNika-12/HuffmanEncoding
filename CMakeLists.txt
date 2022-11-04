cmake_minimum_required(VERSION 3.23)
project(HuffmanEncoding)

set(CMAKE_CXX_STANDARD 14)

add_executable(HuffmanEncoding main.cpp FileReader.cpp FileReader.h Node.cpp Node.h Encoder.cpp Encoder.h Types.h Decoder.cpp Decoder.h)
