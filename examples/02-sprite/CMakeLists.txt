# CMake 최소 요구 버전 설정 (3.10 이상 필요)
cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름 설정
project(Example_sprite)

# C++ 표준 버전 설정 (C++17 사용)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)  # C++17을 필수로 설정

# SFML 라이브러리를 찾기
# ~/dev/libs/sfml-3.0.0/build/lib
set(SFML_DIR "/home/syan/dev/libs/sfml-3.0.0/install/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES ON)
find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

# 실행 파일 생성 (sfml_practice 라는 이름의 실행 파일을 만들고, 소스 코드 추가)
add_executable(example_sprite src/main.cpp)

# SFML 라이브러리를 실행 파일에 연결
target_link_libraries(example_sprite PRIVATE SFML::Graphics SFML::Window SFML::System)

add_custom_command(
	TARGET example_sprite POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different 
			${CMAKE_CURRENT_SOURCE_DIR}/assets/character.png
			${CMAKE_BINARY_DIR}/assets/character.png
)