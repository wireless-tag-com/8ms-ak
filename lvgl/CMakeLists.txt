file(GLOB_RECURSE SOURCES src/*.c)

add_library(lvgl_lib ${SOURCES})

# 将 lvgl 源码编译成静态库，放到 /application/lib/lvgl 路径下。
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../lib/lvgl)

