mkdir $ABI/openssl
cd $ABI/include
cp -R * ../openssl
cd ..
mv openssl include
