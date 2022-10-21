# This is simply a test showing how c++ use move instead of copy of large return values (which c does..)

# Output

Running main() from c:\a\1\s\thirdparty\googletest\googletest\src\gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from big_test
[ RUN      ] big_test.big_struct
[       OK ] big_test.big_struct (0 ms)
[ RUN      ] big_test.big_create_and_update
[       OK ] big_test.big_create_and_update (0 ms)
[ RUN      ] big_test.big_c_performance_test
C  : Time (N=1000000): 0.0462308 seconds
[       OK ] big_test.big_c_performance_test (47 ms)
[ RUN      ] big_test.big_cpp_performance_test
Cpp: Time (N=1000000): 0.0253635 seconds
[       OK ] big_test.big_cpp_performance_test (26 ms)
[----------] 4 tests from big_test (74 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (74 ms total)
[  PASSED  ] 4 tests.

C:\Users\Bent\source\repos\MoveVsCopyTest\x64\Release\MoveVsCopyTest.exe (process 31904) exited with code 0.
Press any key to close this window . . .
