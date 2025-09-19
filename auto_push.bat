@echo off
:: =========================================
:: LeetCode 刷题自动上传脚本
:: 功能：自动添加、提交、推送到 GitHub
:: 路径：D:\Leetcode刷题
:: 分支：main
:: 作者：你的成长记录助手 😊
:: =========================================

:: 关闭命令回显
setlocal

:: 设置编码为 UTF-8，避免中文乱码（可选）
chcp 65001 >nul

:: 进入你的刷题目录
cd /d "D:\Leetcode刷题"

:: 检查是否在 Git 仓库中
if not exist ".git" (
    echo 未找到 .git 目录，正在初始化仓库...
    git init
    if %errorlevel% neq 0 (
        echo 初始化仓库失败，请检查 Git 是否安装。
        pause
        exit /b 1
    )
)

:: 添加所有新增或修改的文件
echo 正在添加文件到暂存区...
git add .

:: 检查是否有文件需要提交
git diff --cached --quiet
if %errorlevel% equ 0 (
    echo 没有文件需要提交，所有代码已是最新状态。
) else (
    :: 获取当前时间作为提交信息
    for /f "tokens=2 delims==" %%i in ('"wmic os get localdatetime /value"') do set datetime=%%i
    set commit_time=%datetime:~0,4%-%datetime:~4,2%-%datetime:~6,2% %datetime:~8,2%:%datetime:~10,2%
    
    echo 正在提交更改...
    git commit -m "📝 提交 LeetCode 刷题记录 - %commit_time%"
    
    if %errorlevel% neq 0 (
        echo 提交失败，请检查是否有冲突或 Git 配置问题。
        pause
        exit /b 1
    )
)

:: 推送到 GitHub 的 main 分支
echo 正在推送到 GitHub...
git push origin main

:: 检查推送是否成功
if %errorlevel% equ 0 (
    echo.
    echo 🎉 代码已成功推送到 GitHub！
    echo   路径: D:\Leetcode刷题
    echo   时间: %date% %time%
) else (
    echo.
    echo ❌ 推送失败！可能原因：
    echo   1. 网络问题
    echo   2. 未配置 SSH 或 Personal Access Token
    echo   3. 远程仓库地址错误
    echo   4. 分支保护规则
    echo.
    echo 请检查远程仓库配置：
    echo   git remote -v
    echo   git status
)

:: 暂停以便查看结果
echo.
pause