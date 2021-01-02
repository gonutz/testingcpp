@echo off

g++ test_main.cpp -o test.exe
if %errorlevel% neq 0 (pause & exit)

test.exe
pause

del test.exe
