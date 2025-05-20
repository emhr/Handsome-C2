@echo off
:: Git 一键上传脚本（支持自定义提交备注）

chcp 65001 >nul
cd /d %~dp0

echo ========= Git 自动上传开始 =========

:: 提示输入提交信息
set /p message=请输入这次提交的备注（比如：添加了登录功能）： 

:: 如果没有输入内容，使用默认时间信息
if "%message%"=="" (
    for /f "tokens=1-4 delims=/ " %%a in ('date /t') do set mydate=%%a-%%b-%%c
    for /f "tokens=1-2 delims=: " %%a in ('time /t') do set mytime=%%a-%%b
    set message=自动提交：%mydate% %mytime%
)

:: 添加、提交并推送
git add .
git commit -m "%message%"
git push

echo ========= 上传完成，窗口5秒后关闭 =========
timeout /t 5 >nul
