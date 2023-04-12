conan install . --output-folder=build --build=missing
cmake -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake -S . -B build
cmake --build build
cp build/compile_commands.json .
