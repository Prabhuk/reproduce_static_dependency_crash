Making client project with VASAN:
Path of the llvm build in the example: /vagrant/llvm/build

cmake ../client/ \
-DCMAKE_C_COMPILER=/vagrant/llvm/build/bin/clang \
-DCMAKE_C_FLAGS="-lstdc++ -fsanitize=vasan -fsanitize=vasancaller" \
-DCMAKE_CXX_COMPILER=/vagrant/llvm/build/bin/clang++ \
-DCMAKE_CXX_FLAGS="-lstdc++ -fsanitize=vasan -fsanitize=vasancaller"
