rd /s/q c:\boost
rd /s/q boost_1_61_0
"C:\Program Files\7-Zip\7z" x boost_1_61_0.7z
cd boost_1_61_0
call bootstrap > ..\log1.txt
rem b2 toolset=msvc-14.0 --build-type=complete --abbreviate-paths architecture=x86 address-model=32 --libdir=c:\boost32 --includedir=c:\boost32\include --build-type=complete install -j8
b2 toolset=msvc-14.0 --build-type=complete --abbreviate-paths architecture=x86 address-model=64 --libdir=c:\boost --includedir=c:\boost\include --build-type=complete install -j4 > ..\log2.txt
cd ..
rd /s/q boost_1_61_0
pause .