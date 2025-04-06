cmake_minimum_required(VERSION 3.10)
project(SGPSDP)

# Настройка стандарта C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск необходимых библиотек (пример для Debian)
find_package(Threads REQUIRED)

# Опции для сборки (STATIC или SHARED)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Сборка библиотеки
add_library(SGPSDP
    Astro.cpp
    Math.cpp
    observer.cpp
    SGP4.cpp
    Sgpsdp.cpp
    time.cpp
    Utils.cpp
)

# Добавление заголовочных файлов
target_include_directories(SGPSDP 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Подавление предупреждений для GCC/Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(SGPSDP PRIVATE -w)
    # Для современных компиляторов можно добавить:
    # target_compile_options(SGPSDP PRIVATE -Wno-deprecated)
endif()

# Линковка системных библиотек (пример)
target_link_libraries(SGPSDP 
    PUBLIC 
        ${CMAKE_THREAD_LIBS_INIT}   # Для многопоточности
        m                          # Математическая библиотека (-lm)
)

# Установка библиотеки и заголовков
install(TARGETS SGPSDP
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include
)

# Генерация .pc файла для pkg-config (опционально)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/sgpsdp.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/sgpsdp.pc
    @ONLY
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/sgpsdp.pc DESTINATION lib/pkgconfig)