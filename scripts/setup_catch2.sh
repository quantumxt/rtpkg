pwd
git clone https://github.com/catchorg/Catch2/ -b v2.x
cd Catch2
mkdir tmp
cmake -Bbuild -H. -DBUILD_TESTING=OFF -DCMAKE_INSTALL_PREFIX=tmp
sudo cmake --build build/ --target install
