# CustomClangFormat
调用clang-format加载自己的格式文件，以支持例如VS、Qt Creator等IDE。

## 环境
* Windows x64

## 使用
1. 在IDE中配置，格式化的执行文件路径为custom-format.exe。
2. 修改clang-format.txt中的文本内容为自己的格式设置即可。

## 说明
* clang到了14版本的时候，才支持参数-style=file:\<path\>的形式，所以这里用的clang-format.exe是14版本的。

