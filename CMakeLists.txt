cmake_minimum_required(VERSION 3.16)
project(LaboratorioCriptografia LANGUAGES CXX)

add_executable(laboratorio_criptografia main.cpp)
target_compile_features(laboratorio_criptografia PRIVATE cxx_std_17)
